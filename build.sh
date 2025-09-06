#!/bin/bash
set -e

echo "🔨 Building Project..."
mkdir -p build

echo "📦 Installing Dependencies..."
sudo apt update

arch=$(uname -m)

case "$arch" in
    x86_64)
        echo "➡️ Running on AMD64"
        sudo apt install -y build-essential mingw-w64 gcc-aarch64-linux-gnu g++-aarch64-linux-gnu gcc-multilib g++-multilib

        echo "🟢 Compiling for Linux AMD64..."
        g++ -O2 -fPIC -shared -o build/SharedLibrary-Linux-AMD64.so src/*.cpp

        echo "🟢 Compiling for Linux ARM64..."
        aarch64-linux-gnu-g++ -O2 -fPIC -shared -o build/SharedLibrary-Linux-ARM64.so src/*.cpp

        echo "🟢 Compiling for Windows 64-Bit..."
        x86_64-w64-mingw32-g++ -O2 -shared -o build/SharedLibrary-Windows-AMD64.dll src/*.cpp

        echo "🟢 Compiling for Windows 32-Bit..."
        i686-w64-mingw32-g++ -O2 -shared -o build/SharedLibrary-Windows-32.dll src/*.cpp
        ;;
    aarch64)
        echo "➡️ Running on ARM64"
        sudo apt install -y build-essential mingw-w64 gcc-aarch64-linux-gnu g++-aarch64-linux-gnu gcc-multilib g++-multilib

        echo "🟢 Compiling for Linux ARM64 (native)..."
        g++ -O2 -fPIC -shared -o build/SharedLibrary-Linux-ARM64.so src/*.cpp

        echo "🟢 Cross-compiling for Linux AMD64..."
        x86_64-linux-gnu-g++ -O2 -fPIC -shared -o build/SharedLibrary-Linux-AMD64.so src/*.cpp

        echo "🟢 Cross-compiling for Windows 64-Bit..."
        x86_64-w64-mingw32-g++ -O2 -shared -o build/SharedLibrary-Windows-AMD64.dll src/*.cpp

        echo "🟢 Cross-compiling for Windows 32-Bit..."
        i686-w64-mingw32-g++ -O2 -shared -o build/SharedLibrary-Windows-32.dll src/*.cpp
        ;;
    *)
        echo "⚠️ Unsupported architecture: $arch"
        exit 1
        ;;
esac

echo "✅ Build finished! Outputs are in ./build/"

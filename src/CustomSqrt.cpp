#include "SimpleMathDll.h"
// Windows DLL Support
#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif
EXPORT double CustomSqrt(double input) {}
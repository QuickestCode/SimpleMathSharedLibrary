// SPDX-License-Identifier: MIT
// Copyright (c) 2025 QuickestCode
#ifndef GITHUB_QUICKESTCODE_REPO_SIMPLEMATHDLL_SIMPLEMATHDLL_H
#define GITHUB_QUICKESTCODE_REPO_SIMPLEMATHDLL_SIMPLEMATHDLL_H
#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif
// Functions from DLL should be added here, starting with EXPORT, such as
// EXPORT int add(int a = 0, int b= 0);
#endif
/**
 * 预编译头文件（Precompiled Header）
 * 
 * 预编译头文件（Precompiled Header）是一种优化编译时间的技术。
 * 它可以将一些常用的头文件预先编译成一个二进制文件，以便在编译其他源文件时可以直接使用这个二进制文件，而不需要重新编译这些头文件。
 * 
 * 在C++中，预编译头文件通常以.pch或.gch为扩展名。
 * 在使用预编译头文件时，需要在源文件的开头添加一个#include指令，指向预编译头文件的路径。
 * 
 * 可移植性问题：预编译头文件通常是与特定编译器和操作系统相关的。
 * 如果在不同的编译器或操作系统上使用相同的预编译头文件，可能会导致编译错误或不兼容的问题。
 */
#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Cactus/Log.h"

#ifdef CC_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
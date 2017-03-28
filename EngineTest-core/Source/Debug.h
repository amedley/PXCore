#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG 1

#include <iostream>

#if DEBUG
#define LOG(string, ...) printf(string, __VA_ARGS__); printf("\n");
#include <assert.h>
#define Assert(passes, message, ...) if (!passes) { LOG(message, __VA_ARGS__); assert(0); }
#else
#define LOG(string, args)
#define Assert(passes, message, ...)
#endif

#endif
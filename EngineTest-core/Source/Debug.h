#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG 1

#include "CommonIncludes.h"
#include "CommonTypes.h"

#if DEBUG
#define LOG(string, ...) printf(string, __VA_ARGS__); printf("\n");
#include <assert.h>

#define ASSERT(passes, message, ...) if (!passes) { LOG(message, __VA_ARGS__); assert(0); }
#else
#define LOG(string, args)
#define ASSERT(passes, message, ...)
#endif

#endif
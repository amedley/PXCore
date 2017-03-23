#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG 1

#include <iostream>

#if DEBUG
#define LOG(string, ...) printf(string, __VA_ARGS__); printf("\n");
#else
#define LOG(string, args)
#endif

#endif
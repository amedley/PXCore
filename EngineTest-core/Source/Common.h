#ifndef COMMON_H
#define COMMON_H

#include "Debug.h"
#include "String.h"
#include "CommonIncludes.h"
#include "CommonTypes.h"

#define BIT(x) (1 << x)

#define METHOD_1(x) std::bind(x, this, std::placeholders::_1)
#define METHOD(x) METHOD_1(x)

#endif
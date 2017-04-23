#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "../Common.h"
#include <fstream>

namespace EngineTest { namespace Utils {
	class FileUtils
	{
	public:
		FileUtils();
		~FileUtils();
	public:
		String ReadFile(const char* filePath);
	};
}}

#endif
#include "FileUtils.h"

namespace EngineTest { namespace Utils {
	FileUtils::FileUtils()
	{
	}

	FileUtils::~FileUtils()
	{
	}

	String FileUtils::ReadFile(const char* filePath)
	{
		// Open file
		FILE* file = fopen(filePath, "rt");
			
		// Seek to the end and retrieve the length. Then allocate a char array (all zeros) with a terminating character at the end
		fseek(file, 0, SEEK_END);
		unsigned long length = ftell(file);
		char* data = new char[length + 1];
		memset(data, 0, length + 1);
			
		// Go back to the beginning now that the length has been figured out and read all of the file into the data
		fseek(file, 0, SEEK_SET);
		fread(data, 1, length, file);

		// Close file
		fclose(file);

		// Store this data into a string, delete the data array, and return the result
		String result(data);
		DELETE_ARRAY(data);

		return result;
	}
}}
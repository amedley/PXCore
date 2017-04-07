#ifndef SHADER_H
#define SHADER_H

#include <vector>
#include "../Utils/FileUtils.h"
#include "GL/glew.h"
#include "../Math/Math.h"
#include "../Math/Vector3.h"
#include "../Math/Vector4.h"

namespace EngineTest
{
	namespace Graphics
	{
		using namespace Math;

		struct Vertex
		{
			Vector4 _color;
			Vector3 _position;
		};

#define MAX_UNIFORM_LOCATIONS 32

		class Shader
		{
		private:
			GLuint m_ProgramID;
			bool m_Enabled;
			const char* m_VertPath;
			const char* m_FragPath;
			const GLchar* m_UniformNameCache[32];
			GLint m_UniformLocationCache[32];
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void SetUniform1i(const GLchar* name, int value);
			void SetUniform1f(const GLchar* name, float value);
			void SetUniform2f(const GLchar* name, const Math::Vector2& vector);
			void SetUniform3f(const GLchar* name, const Math::Vector3& vector);
			void SetUniform4f(const GLchar* name, const Math::Vector4& vector);
			void SetUniformMatrix4(const GLchar* name, const Math::Matrix4& matrix);

			void Enable();
			void Disable();

			bool Enabled();
			GLuint ProgramID();

		private:
			GLint GetUniformLocation(const GLchar* name);
			GLuint Load();
		};
	}
}

#endif
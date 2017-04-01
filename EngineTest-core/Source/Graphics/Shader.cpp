#include "Shader.h"

namespace EngineTest
{
	namespace Graphics
	{
		using namespace Utils;

		Shader::Shader(const char* vertPath, const char* fragPath)
		{
			m_VertPath = vertPath;
			m_FragPath = fragPath;

			for (int i = 0; i < MAX_UNIFORM_LOCATIONS; i++)
			{
				m_UniformLocationCache[i] = 0;
				m_UniformNameCache[i] = "";
			}
			m_ProgramID = Load();
		}
		Shader::~Shader()
		{
			if (m_ProgramID)
			{
				glDeleteProgram(m_ProgramID);
			}
		}
		void Shader::SetUniform1i(const GLchar* name, int value)
		{
			glUniform1i(GetUniformLocation(name), value);
		}
		void Shader::SetUniform1f(const GLchar* name, float value)
		{
			glUniform1f(GetUniformLocation(name), value);
		}
		void Shader::SetUniform2f(const GLchar* name, const Math::Vector2& vector)
		{
			glUniform2f(GetUniformLocation(name), vector._x, vector._y);
		}
		void Shader::SetUniform3f(const GLchar* name, const Math::Vector3& vector)
		{
			glUniform3f(GetUniformLocation(name), vector._x, vector._y, vector._z);
		}
		void Shader::SetUniform4f(const GLchar* name, const Math::Vector4& vector)
		{
			glUniform4f(GetUniformLocation(name), vector._x, vector._y, vector._z, vector._w);
		}
		void Shader::SetUniformMatrix4(const GLchar* name, const Math::Matrix4& matrix)
		{
			glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, matrix._elements);
		}

		GLuint Shader::Load()
		{
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);

			String vertSourceStr = FileUtils::Get()->ReadFile(m_VertPath);
			const char* vertSource = vertSourceStr.c_str();

			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint vertexSuccess;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &vertexSuccess);
			if (vertexSuccess == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);

				LOG("Failed to load shader: %s with error: %s", m_VertPath, &error[0]);
				glDeleteShader(vertex);
				return 0;
			}

			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
			String fragSourceStr = FileUtils::Get()->ReadFile(m_FragPath);
			const char* fragSource = fragSourceStr.c_str();

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			GLint fragmentSuccess;
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &fragmentSuccess);
			if (fragmentSuccess == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);

				LOG("Failed to load shader: %s with error: %s", m_FragPath, &error[0]);
				glDeleteShader(fragment);
				return 0;
			}
			GLuint program = glCreateProgram();
			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		void Shader::Enable()
		{
			glUseProgram(m_ProgramID);
			m_Enabled = true;
		}
		void Shader::Disable()
		{
			glUseProgram(0);
			m_Enabled = false;
		}

		bool Shader::Enabled()
		{
			return m_Enabled;
		}

		GLint Shader::GetUniformLocation(const GLchar* name)
		{
			for (int i = 0; i < MAX_UNIFORM_LOCATIONS; i++)
			{
				if (!strcmp(name, m_UniformNameCache[i]))
				{
					return m_UniformLocationCache[i];
				}
				if (m_UniformLocationCache[i] == 0)
				{
					m_UniformNameCache[i] = name;
					return (m_UniformLocationCache[i] = glGetUniformLocation(m_ProgramID, name));
				}
			}
			return 0;
		}
		GLuint Shader::ProgramID()
		{
			return m_ProgramID;
		}
	}
}
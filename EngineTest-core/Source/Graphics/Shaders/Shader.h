#ifndef SHADER_H
#define SHADER_H

#include <vector>
#include "GL/glew.h"
#include "../../Utils/FileUtils.h"
#include "../../Math/Math.h"
#include "../../Math/Vector3.h"
#include "../../Math/Vector4.h"

namespace EngineTest { namespace Graphics { namespace Shaders {

	enum SHADER_TYPE
	{
		kBasic2D				= 0,
		kBasic3D,
		kSHADER_TYPE_COUNT
	};

	using namespace Math;

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
		SHADER_TYPE m_Type;
	public:
		Shader(SHADER_TYPE type, const char* vertPath, const char* fragPath);
		virtual ~Shader();

		void SetUniform1i(const GLchar* name, int value);
		void SetUniform1f(const GLchar* name, float value);
		void SetUniform2f(const GLchar* name, const Math::Vector2& vector);
		void SetUniform3f(const GLchar* name, const Math::Vector3& vector);
		void SetUniform4f(const GLchar* name, const Math::Vector4& vector);
		void SetUniformMatrix4(const GLchar* name, const Math::Matrix4& matrix);

		virtual bool Enable();
		virtual bool Disable();
		virtual void EnableVertexAttribs();

		bool Enabled();
		GLuint ProgramID();
		SHADER_TYPE GetType();

	private:
		GLint GetUniformLocation(const GLchar* name);
		GLuint Load();
	};
}}}

#endif
#ifndef COLOR_RGBA_H
#define COLOR_RGBA_H

#include "../Math/Math.h"

namespace EngineTest { namespace Entities {

	using namespace Math;

	class ColorRGBA
	{
	public:
		ColorRGBA(const Vector4& rgba, const Vector4& rgbaOffset);
		ColorRGBA(const Vector4& rgba);
		ColorRGBA();
		~ColorRGBA();

		Vector4 m_RGBA;
		Vector4 m_RGBAOffset;

		void CalculateRGBAMultiplied();
		Vector4& GetRGBAMultiplied();
	private:
		Vector4 m_RGBAMultiplied;
	};

}}

#endif
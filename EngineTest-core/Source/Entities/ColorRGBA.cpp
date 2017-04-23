#include "ColorRGBA.h"

namespace EngineTest { namespace Entities {

	ColorRGBA::ColorRGBA(const Vector4& rgba, const Vector4& rgbaOffset)
	{
		m_RGBA = rgba;
		m_RGBAOffset = rgbaOffset;

		m_RGBAMultiplied = Vector4(1.0f);
		CalculateRGBAMultiplied();
	}
	ColorRGBA::ColorRGBA(const Vector4& rgba) : ColorRGBA(rgba, Vector4(1.0f))
	{
	}
	ColorRGBA::ColorRGBA() : ColorRGBA(Vector4(1.0f), Vector4(1.0f))
	{

	}
	ColorRGBA::~ColorRGBA()
	{
	}

	void ColorRGBA::CalculateRGBAMultiplied()
	{
		m_RGBAMultiplied = m_RGBA * m_RGBAOffset;
	}
	Vector4& ColorRGBA::GetRGBAMultiplied()
	{
		return m_RGBAMultiplied;
	}
}}
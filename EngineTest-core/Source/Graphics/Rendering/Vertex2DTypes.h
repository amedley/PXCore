#ifndef VERTEX_2D_TYPES_H
#define VERTEX_2D_TYPES_H

#include "../../Math/Math.h"

namespace EngineTest { namespace Graphics { namespace Rendering {

	using namespace Math;

	struct Vertex2D
	{
		Vector3 _position;
		Vector4 _color;
	};

}}}
#endif
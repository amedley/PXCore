#ifndef CAMERA_H
#define CAMERA_H

#include "../Common.h"
#include "../Math/Math.h"

namespace EngineTest { namespace Entities {

	using namespace Math;

	class Camera
	{
	public:
		Camera();
		virtual ~Camera();

		virtual void OnUpdate();
	};
}}

#endif
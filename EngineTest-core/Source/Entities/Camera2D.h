#ifndef CAMERA_2D_H
#define CAMERA_2D_H

#include "Camera.h"
#include "Common2DForwardDcls.h"

namespace EngineTest { namespace Entities {

	class Camera2D : public Camera
	{
	public:
		Camera2D();
		~Camera2D();

		void OnUpdate();

		Transform2D& GetTransform();
	private:
		Transform2D* m_Transform;
	};

}}

#endif
#ifndef LAYER_2D_H
#define LAYER_2D_H

#include "Group2D.h"

namespace EngineTest { namespace Entities {

	class Layer2D : public Entity2D
	{
	public:
		Layer2D(const Matrix4& proj);
		virtual ~Layer2D();

		virtual bool OnUpdate(uint64 gameTick);
		virtual void OnRender();

		Matrix4& GetProj();
		Renderer2D& GetRenderer();
		Camera2D& GetCamera();

	private:
		Matrix4 m_Proj;
		Renderer2D* m_Renderer;
		Camera2D* m_Camera;
	};

}}

#endif
#include "Common2DIncludes.h"

namespace EngineTest { namespace Entities {

	Group2D::Group2D() : Entity2D(Vector3(0.0f), Vector2(1.0f), Vector4(1.0f))
	{
	}
	Group2D::~Group2D()
	{
	}

	bool Group2D::OnUpdate(uint64 gameTick)
	{
		if (!Entity2D::OnUpdate(gameTick))
			return false;

		return true;
	}
	void Group2D::OnRender(Renderer2D* renderer)
	{
		if (!GetTransform().GetMatrixSynced())
			GetTransform().CalculateModel();
		renderer->PushMatrix(GetTransform().GetMatrix());

		Entity2D::OnRenderChildEntities(renderer);
		
		renderer->PopMatrix();
	}
}}
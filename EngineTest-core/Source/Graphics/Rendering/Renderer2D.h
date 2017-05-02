#ifndef RENDERER_2D
#define RENDERER_2D

#include "Renderer.h"
#include "../../Entities/Common2DForwardDcls.h"
#include "Vertex2DTypes.h"

namespace EngineTest { namespace Graphics { namespace Rendering {

#define TRANSFORM_2D_STACK_SIZE 64
#define MAX_RECTANGLES_PER_DRAW 4096
#define MAX_SUBMISSIONS 65536

	using namespace Entities;

	class Renderer2D : public Renderer
	{
	private:
		int32 m_TransformStackSize;
		Matrix4 m_TransformStack[TRANSFORM_2D_STACK_SIZE];
		Matrix4* m_TransformStackResult;
		uint32 m_SubmissionCount;
		std::vector<Vertex2D> m_Vertices;
		std::vector<uint16> m_Indices;

	public:
		Renderer2D();
		~Renderer2D();

		void PushMatrix(const Matrix4& transform, bool multiply);
		void PushMatrix(const Matrix4& transform);
		void PopMatrix();
		Matrix4& GetTransformMatrix();

		void Begin();
		void Submit(Entity2D* sender, Rect2D* rect, ColorRGBA* colorRGBA);
		void End();
		void Draw();
		void Draw(int32 submissionIndex, int32 submissionCount);
	};

}}}

#endif
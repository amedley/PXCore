#ifndef TRANSFORM_2D_H
#define TRANSFORM_2D_H

#include "../Math/Math.h"

namespace EngineTest { namespace Entities {

	using namespace Math;

	class Transform2D
	{
	public:
		Transform2D(const Vector3& position, const Vector2& size, const Vector2& scale, float rotation);
		Transform2D();
		~Transform2D();
		
		void CalculateModel();
		void CalculateView();
		Matrix4& GetMatrix();

		void SetPosition(const Vector3& position);
		void SetSize(const Vector2& size);
		void SetScale(const Vector2& scale);
		void SetRotation(float rotation);

		void ChangePosition(const Vector3& dPosition);
		void ChangeSize(const Vector2& dSize);
		void ChangeScale(const Vector2& dScale);
		void ChangeRotation(float dRotation);

		const Vector3& GetPosition();
		const Vector2& GetSize();
		const Vector2& GetScale();
		float GetRotation();

		bool GetMatrixSynced();

	private:
		Vector3 m_Position;
		Vector2 m_Size;
		Vector2 m_Scale;
		float m_Rotation;

		Matrix4 m_Matrix;
		bool m_MatrixSynced;
	};

}}

#endif
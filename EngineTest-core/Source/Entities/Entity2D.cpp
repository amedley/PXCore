#include "Entity2D.h"
#include "Common2DIncludes.h"

namespace EngineTest { namespace Entities {

	Entity2D::Entity2D(const Vector3& position, const Vector2& size, const Vector4& rgba)
	{
		m_Rect = new Rect2D();
		m_Transform = new Transform2D(position, size, Vector2(1.0f), 0.0f);
		m_ColorRGBA = new ColorRGBA(rgba);
		
		m_Parent = NULL;
		m_ChildEntities = std::vector<Entity2D*>(); 

		m_EntityState = kEntity2DRemoved;
		m_RenderingGuide = kRenderLikeParent;
		m_RenderingEnabled = true;
		m_GameTick = 0;
		m_ChildUpdateIndex = (size_t)-1;
		m_ChildRenderIndex = (size_t)-1;
	}
	Entity2D::Entity2D() : Entity2D(Vector3(0.0f), Vector2(32.0f), Vector4(1.0f))
	{

	}
	Entity2D::~Entity2D()
	{
		m_EntityState = kEntity2DDestructed;
		m_ChildEntities.clear();
		DELETE(m_Rect);
		DELETE(m_Transform);
		DELETE(m_ColorRGBA);
		m_Parent = NULL;
	}


	bool Entity2D::OnUpdate(uint64 gameTick)
	{
		// Prevent more than one update from occurring per game tick.
		if (m_GameTick >= gameTick)
			return false;

		if (m_ChildEntities.size())
		{
			m_ChildUpdateIndex = 0;
			while (m_ChildUpdateIndex < m_ChildEntities.size())
			{
				m_ChildEntities[m_ChildUpdateIndex]->OnUpdate(gameTick);
				m_ChildUpdateIndex++;
			}
			m_ChildUpdateIndex = (size_t)-1;
		}

		m_GameTick = gameTick;
		return true;
	}
	void Entity2D::OnRender(Renderer2D* renderer)
	{
		if (!m_Transform->GetMatrixSynced())
			m_Transform->CalculateModel();
		bool shouldRender = GetShouldRender();
		if (shouldRender)
		{
			renderer->PushMatrix(m_Transform->GetMatrix());
			m_Rect->CalculateVertices(renderer->GetTransformMatrix());
			renderer->Submit(this, m_Rect, m_ColorRGBA);
		}

		OnRenderChildEntities(renderer);

		if (shouldRender)
		{
			renderer->PopMatrix();
		}
	}
	void Entity2D::OnRenderChildEntities(Renderer2D* renderer)
	{
		if (m_ChildEntities.size())
		{
			m_ChildRenderIndex = 0;
			while (m_ChildRenderIndex < m_ChildEntities.size())
			{
				m_ChildEntities[m_ChildRenderIndex]->OnRender(renderer);
				m_ChildRenderIndex++;
			}
			m_ChildRenderIndex = (size_t)-1;
		}
	}

	Rect2D& Entity2D::GetRect()
	{
		return *m_Rect;
	}
	Transform2D& Entity2D::GetTransform()
	{
		return *m_Transform;
	}
	ColorRGBA& Entity2D::GetColor()
	{
		return *m_ColorRGBA;
	}


	void Entity2D::AddChild(Entity2D& entity)
	{
		if (GetEntityState() == kEntity2DDestructed)
			return;
		if (entity.GetEntityState() == kEntity2DAdded)
		{
			entity.Remove();
		}
		if (entity.GetEntityState() == kEntity2DRemoved)
		{
			m_ChildEntities.push_back(&entity);
			entity.Added(*this);
		}
	}
	void Entity2D::Added(Entity2D& parent)
	{
		m_EntityState = kEntity2DAdded;
		m_Parent = &parent;
		OnAdded(parent);
	}
	void Entity2D::OnAdded(Entity2D& parent) {};


	void Entity2D::RemoveChild(Entity2D& entity)
	{
		if (GetEntityState() == kEntity2DDestructed)
			return;
		if (entity.GetEntityState() == kEntity2DAdded)
		{
			std::vector<Entity2D*>::iterator indexOfEntity = std::find(m_ChildEntities.begin(), m_ChildEntities.end(), &entity);
			if (indexOfEntity != m_ChildEntities.end())
			{
				if (m_ChildUpdateIndex < (size_t)-1 && (size_t)(indexOfEntity - m_ChildEntities.begin()) <= m_ChildUpdateIndex)
				{
					m_ChildUpdateIndex--;
				}
				if (m_ChildRenderIndex < (size_t)-1 && (size_t)(indexOfEntity - m_ChildEntities.begin()) <= m_ChildRenderIndex)
				{
					m_ChildRenderIndex--;
				}
				m_ChildEntities.erase(indexOfEntity);
				entity.Removed(*this);
			}
		}
	}
	void Entity2D::Removed(Entity2D& parent)
	{
		m_EntityState = kEntity2DRemoved;
		m_Parent = NULL;
		OnRemoved(parent);
	}
	void Entity2D::OnRemoved(const Entity2D& parent) {};


	void Entity2D::Remove()
	{
		if (m_Parent)
			m_Parent->RemoveChild(*this);
	}


	Entity2D& Entity2D::GetParent()
	{
		return *m_Parent;
	}

	// Property getters
	EntityState2D Entity2D::GetEntityState()
	{
		return m_EntityState;
	}
	RenderingGuide2D Entity2D::GetRenderingGuide()
	{
		return m_RenderingGuide;
	}
	bool Entity2D::GetRenderingEnabled()
	{
		return m_RenderingEnabled;
	}
	bool Entity2D::GetShouldRender()
	{
		switch(GetRenderingGuide())
		{
			case kRenderAlways:
			{
				return true;
			}
			case kRenderIfEnabled:
			{
				if (GetRenderingEnabled())
					return true;
				break;
			}
			case kRenderLikeParent:
			{
				if (GetRenderingEnabled() && (!m_Parent || m_Parent->GetShouldRender()))
					return true;
				break;
			}
			case kRenderNever:
				break;
		}
		return false;
	}
	uint64 Entity2D::GetGameTick()
	{
		return m_GameTick;
	}

	// Property setters
	void Entity2D::SetRenderingEnabled(bool enabled)
	{
		if (m_RenderingEnabled == enabled)
			return;
		m_RenderingEnabled = enabled;
	}
	void Entity2D::SetRenderingGuide(RenderingGuide2D guide)
	{
		if (m_RenderingGuide == guide)
			return;
		m_RenderingGuide = guide;
	}
}};
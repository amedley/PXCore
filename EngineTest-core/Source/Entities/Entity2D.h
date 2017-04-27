#ifndef ENTITY_2D_H
#define ENTITY_2D_H

#include "../Math/Math.h"
#include "../Common.h"
#include "Common2DForwardDCLS.h"

namespace EngineTest { namespace Entities {

	enum EntityState2D
	{
		kEntity2DRemoved						= 0,		// An entity is removed if it does not exist in a parent's m_ChildEntities array
		kEntity2DAdded,										// An entity is added if it does exist in a paren't m_ChildEntities array
		kEntity2DDestructed									// An entity is destructed as soon as the destructor is called
	};
	enum RenderingGuide2D
	{
		kRenderAlways							= 0,		// Render anytime OnRender is called
		kRenderIfEnabled,									// Render anytime OnRender is called and rendering is enabled
		kRenderLikeParent,									// Render anytime OnREnder is called and rendering is enabled and if the parent should render
		kRenderNever										// Never render even if rendering is enabled
	};

	using namespace Math;
	using namespace Graphics;
	using namespace Rendering;

	class Entity2D
	{
	public:
		Entity2D(const Vector3& position, const Vector2& size, const Vector4& rgba);
		Entity2D();
		virtual ~Entity2D();

		virtual bool OnUpdate(uint64 gameTick);
		virtual void OnRender(Renderer2D* renderer);

		Rect2D& GetRect();
		Transform2D& GetTransform();
		ColorRGBA& GetColor();

		// Parent child methods
		void AddChild(Entity2D& entity);
		void RemoveChild(Entity2D& entity);
		Entity2D& GetParent();
		const std::vector<Entity2D*>& GetChildEntities();

		// Property getters
		EntityState2D GetEntityState();
		RenderingGuide2D GetRenderingGuide();
		bool GetRenderingEnabled();
		bool GetShouldRender();
		uint64 GetGameTick();

		// Property setters
		void SetRenderingEnabled(bool enabled);
		void SetRenderingGuide(RenderingGuide2D guide);
	protected:
		virtual void OnRenderChildEntities(Renderer2D* renderer);
		virtual void OnAdded(Entity2D& parent);
		virtual void OnRemoved(const Entity2D& parent);
		virtual void Remove();

	private:
		Rect2D* m_Rect;
		Transform2D* m_Transform;
		ColorRGBA* m_ColorRGBA;

		/*
		There are a few simple rules behind this parent child system:
		1) All of this entity's child entities must point to this entity as their parent.
		2) This entity must know about all of the child entities that point to this entity as their parent.
		3) An entity can only be deleted via its parent.
		4) An entity may only choose its parent via the parent's AddChild and RemoveChild methods.
		*/
		void Added(Entity2D& parent);
		void Removed(Entity2D& parent);
		Entity2D* m_Parent;
		std::vector<Entity2D*> m_ChildEntities;

		// Properties
		EntityState2D m_EntityState;
		RenderingGuide2D m_RenderingGuide;
		bool m_RenderingEnabled;
		uint64 m_GameTick;
		size_t m_ChildUpdateIndex;
		size_t m_ChildRenderIndex;
	};

}}

#endif
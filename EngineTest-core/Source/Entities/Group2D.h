#ifndef GROUP_2D_H
#define GROUP_2D_H

#include "Entity2D.h"

namespace EngineTest { namespace Entities {

	class Group2D : public Entity2D
	{
	public:
		Group2D();
		virtual ~Group2D();

		virtual bool OnUpdate(uint64 gameTick);
		virtual void OnRender(Renderer2D* renderer);
	};
}}

#endif
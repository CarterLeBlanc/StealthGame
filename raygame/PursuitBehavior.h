#pragma once
#include "Behavior.h"

class PursuitBehavior : public Behavior
{
public:
	PursuitBehavior() {}
	virtual ~PursuitBehavior() {}

	virtual void update(Agent* agent, float deltaTime);

	void setTarget(Agent* agent) { m_Target = agent; }

private:
	Agent* m_Target = nullptr;
};
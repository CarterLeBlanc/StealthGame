#pragma once
#include "Decision.h"

class BehaviorDecision : public Decision
{
public:
	BehaviorDecision(Behavior* behavior) : m_Behavior(behavior) {}
	~BehaviorDecision() {}

	virtual void makeDecision(Agent* agent, float deltaTime);

private:
	Behavior* m_Behavior = nullptr;
};
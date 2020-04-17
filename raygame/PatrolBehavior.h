#pragma once
#include "Behavior.h"

class PatrolBehavior : public Behavior
{
public:
	PatrolBehavior() {}
	virtual ~PatrolBehavior() {}

	virtual void update(Agent* agent, float deltaTime);

private:
	float m_Radius = 2000.0f;
	float m_Offset = 0.0f;
	float m_Jitter = 500.0f;
	Vector2 m_PrevTarget = { 0,0 };
};
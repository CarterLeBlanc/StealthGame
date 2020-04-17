#include "BehaviorDecision.h"
#include "Behavior.h"

void BehaviorDecision::makeDecision(Agent* agent, float deltaTime)
{
	if (m_Behavior == nullptr)
		return;

	m_Behavior->update(agent, deltaTime);
}
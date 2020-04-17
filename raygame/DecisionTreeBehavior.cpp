#include "DecisionTreeBehavior.h"

void DecisionTreeBehavior::update(Agent* agent, float deltaTime)
{
	m_RootDecision->makeDecision(agent, deltaTime);
}
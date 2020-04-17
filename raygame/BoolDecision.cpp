#include "BoolDecision.h"

void BoolDecision::makeDecision(Agent* agent, float deltaTime)
{
	if (m_Condition->test(agent))
		m_A->makeDecision(agent, deltaTime);

	else
		m_B->makeDecision(agent, deltaTime);
}
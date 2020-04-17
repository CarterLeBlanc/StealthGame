#pragma once
#include "Decision.h"
#include "Condition.h"

class BoolDecision : public Decision
{
public:
	BoolDecision(Decision* a, Decision* b, Condition* condition) : m_A(a), m_B(b), m_Condition(condition) {}
	~BoolDecision() {}

	virtual void makeDecision(Agent* agent, float deltaTime);

private:
	Decision* m_A;
	Decision* m_B;
	Condition* m_Condition;
};
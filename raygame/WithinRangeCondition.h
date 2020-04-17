#pragma once
#include "Condition.h"

class WithinRangeCondition : public Condition
{
public:
	WithinRangeCondition(Agent* target, float range) : m_Target(target), m_Range(range) {}
	virtual ~WithinRangeCondition() {}

	virtual bool test(Agent* agent) const;

private:
	Agent* m_Target;
	float m_Range;
};
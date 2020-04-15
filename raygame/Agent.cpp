#include "Agent.h"
#include "Behavior.h"

void Agent::update(float deltaTime)
{
	//For each behavior in the behavior list
	for (auto i = m_BehaviorList.begin(); i != m_BehaviorList.end(); i++)
	{
		//Call the behavior's update function
		(*i)->update(this, deltaTime);
	}

	//Add velocity times delta time to position
	m_Position += (m_Velocity * deltaTime);
}

void Agent::draw()
{
	DrawRectangle(m_Position.x, m_Position.y, 10, 10, m_Color);
}

void Agent::addBehavior(Behavior* behavior)
{
	//Add a behavior to the behavior list
	m_BehaviorList.insert(m_BehaviorList.end(), behavior);
}

void Agent::addForce(Vector2 force)
{
	m_Velocity += force;
}
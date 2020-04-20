/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Agent.h"
#include "KeyboardBehavior.h"
#include "PursuitBehavior.h"
#include "WithinRangeCondition.h"
#include "BoolDecision.h"
#include "BehaviorDecision.h"
#include "DecisionTreeBehavior.h"
#include "PatrolBehavior.h"
#include "ScreenEdgeBehavior.h"
#include <iostream>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1600;
	int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	//Set up the player
	Agent* player = new Agent();
	player->setPosition({ screenWidth / 2.0f, screenHeight / 2.0f });
	player->setSpeed(250.0f);
	player->setColor(LIME);
	//Create and add keyboard behavior
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior();
	player->addBehavior(keyboardBehavior);
	//Create ScreenEdgeBehavior
	ScreenEdgeBehavior* screenEdgeBehavior = new ScreenEdgeBehavior();
	//Add screenEdgeBehavior to the player
	player->addBehavior(screenEdgeBehavior);

	//Set up the enemies
	Agent* enemy1 = new Agent();
	enemy1->setPosition(Vector2{ 750.0f, 450.0f });
	enemy1->setSpeed(250.0f);
	enemy1->setColor(MAROON);
	//Add screenEdgeBehavior to enemy1
	enemy1->addBehavior(screenEdgeBehavior);

	//Enemy 2
	Agent* enemy2 = new Agent();
	enemy2->setPosition(Vector2{ 650.0f, 350.0f });
	enemy2->setSpeed(250.0f);
	enemy2->setColor(MAROON);
	//Add screenEdgeBehavior to enemy2
	enemy2->addBehavior(screenEdgeBehavior);

	//Enemy 3
	Agent* enemy3 = new Agent();
	enemy3->setPosition(Vector2{ 550.0f, 250.0f });
	enemy3->setSpeed(250.0f);
	enemy3->setColor(MAROON);
	//Add screenEdgeBehavior to enemy3
	enemy3->addBehavior(screenEdgeBehavior);

	//Enemy 4
	Agent* enemy4 = new Agent();
	enemy4->setPosition(Vector2{ 450.0f, 150.0f });
	enemy4->setSpeed(250.0f);
	enemy4->setColor(MAROON);
	//Add screenEdgeBehavior to enemy4
	enemy4->addBehavior(screenEdgeBehavior);

	//Enemy 5
	Agent* enemy5 = new Agent();
	enemy5->setPosition(Vector2{ 350.0f, 50.0f });
	enemy5->setSpeed(250.0f);
	enemy5->setColor(MAROON);
	//Add screenEdgeBehavior to enemy5
	enemy5->addBehavior(screenEdgeBehavior);

	//Leaves
	PatrolBehavior* patrolBehavior = new PatrolBehavior();
	BehaviorDecision* patrolDecision = new BehaviorDecision(patrolBehavior);
	PursuitBehavior* pursuitBehavior = new PursuitBehavior();
	pursuitBehavior->setTarget(player);
	BehaviorDecision* pursuitDecision = new BehaviorDecision(pursuitBehavior);

	//Branches
	WithinRangeCondition* canSeeCondition = new WithinRangeCondition(player, 100.0f);
	BoolDecision* canSeeDecision = new BoolDecision(pursuitDecision, patrolDecision, canSeeCondition);

	//Enemy decision tree
	DecisionTreeBehavior* enemyDecisionTree = new DecisionTreeBehavior(canSeeDecision);
	enemy1->addBehavior(enemyDecisionTree);
	enemy2->addBehavior(enemyDecisionTree);
	enemy3->addBehavior(enemyDecisionTree);
	enemy4->addBehavior(enemyDecisionTree);
	enemy5->addBehavior(enemyDecisionTree);


	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		float deltaTime = GetFrameTime();
		player->update(deltaTime);
		enemy1->update(deltaTime);
		enemy2->update(deltaTime);
		enemy3->update(deltaTime);
		enemy4->update(deltaTime);
		enemy5->update(deltaTime);

		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		//Draw tile map
		//map.draw();

		player->draw();
		enemy1->draw();
		enemy2->draw();
		enemy3->draw();
		enemy4->draw();
		enemy5->draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
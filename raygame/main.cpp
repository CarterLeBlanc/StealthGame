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
#include "Pathfinding.h"
#include "Maze.h"
#include <iostream>

using namespace pathfinding;

enum tileType 
{
	open,
	closed
};

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 3200;
	int screenHeight = 1600;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	Maze<tileType> maze({ 3, 4 }, { 200, 200 }, closed, MAROON);

	//Walls
	maze.createTile({ 0, 0 }, open, SKYBLUE);
	maze.createTile({ 2, 0 }, open, SKYBLUE);
	maze.createTile({ 2, 1 }, open, SKYBLUE);
	maze.createTile({ 2, 2 }, open, SKYBLUE);
	maze.createTile({ 1, 3 }, open, SKYBLUE);
	maze.createTile({ 0, 2 }, open, SKYBLUE);

	Tile<tileType> tile1 = maze.checkTile({ 100, 100 });
	Tile<tileType> tile2 = maze.getTile({ 1, 3 });

	std::cout << tile1.data << ", ";
	std::cout << tile2.data << std::endl;

	//Nodes
	Node* a = new Node();
	a->position = Vector2{ 500.0f, 300.0f };

	Node* b = new Node();
	b->position = Vector2{ 1000.0f, 300.0f };

	Node* c = new Node();
	c->position = Vector2{ 1000.0f, 600.0f };

	Node* d = new Node();
	d->position = Vector2{ 1000.0f, 900.0f };

	Node* e = new Node();
	e->position = Vector2{ 750.0f, 1200.0f };

	Node* f = new Node();
	f->position = Vector2{ 500.0f, 900.0f };

	//Edges
	a->connections.push_back(Edge{ b, 2 });
	a->connections.push_back(Edge{ f, 5 });

	b->connections.push_back(Edge{ c, 3 });

	c->connections.push_back(Edge{ a, 3 });
	c->connections.push_back(Edge{ d, 1 });

	d->connections.push_back(Edge{ e, 4 });
	d->connections.push_back(Edge{ f, 4 });

	f->connections.push_back(Edge{ e, 6 });

	std::vector<Node*> shortestPath = AStarSearch(a, e);

	for (Node* node : shortestPath) 
	{
		std::cout << node->gScore << std::endl;
	}

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		//Draw the graph
		std::vector<Node*>* drawnList = new std::vector<Node*>();
		drawGraph(a, drawnList);
		delete drawnList;

		//Draw the shortest path
		for (Node* node : shortestPath)
		{
			drawNode(node, true);
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
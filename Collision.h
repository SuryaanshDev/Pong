#pragma once
#include "Paddle.h"
#include "Ball.h"

class Collision
{

private:

	bool checkCollisionBox( Ball &ball,  Paddle &paddle);

public:
	Collision();
	~Collision();

	bool isCollide( Ball &ball,Paddle &paddle);
};


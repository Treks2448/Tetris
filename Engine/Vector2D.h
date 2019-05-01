#pragma once

class Vector2D
{
	Vector2D operator+(Vector2D vectorToAdd);
	Vector2D operator*(float multiplier);
	Vector2D operator+=(Vector2D vectorToAdd);
	Vector2D operator*=(Vector2D multiplier);
	Vector2D operator-=(Vector2D vectorToSubtract);
	Vector2D operator++();
public:
	float X;
	float Y;
};
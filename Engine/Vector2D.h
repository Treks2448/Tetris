#pragma once

class Vector2D
{
public:
	Vector2D operator + (Vector2D vectorToAdd);
	Vector2D operator * (float multiplier);
	Vector2D operator += (Vector2D vectorToAdd);
	Vector2D operator *= (Vector2D multiplier);
	Vector2D operator -= (Vector2D vectorToSubtract);
	Vector2D operator ++ ();
	bool operator == (Vector2D comparedVector);

public:
	float X;
	float Y;
};
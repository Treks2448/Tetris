#include "Vector2D.h"

Vector2D Vector2D::operator+(Vector2D vectorToAdd)
{
	return {X + vectorToAdd.X, Y + vectorToAdd.Y};
}

Vector2D Vector2D::operator-(Vector2D vectorToSubtract)
{
	return { X - vectorToSubtract.X, Y - vectorToSubtract.Y };
}

Vector2D Vector2D::operator*(float multiplier)
{
	return { X + multiplier, Y + multiplier };
}

Vector2D Vector2D::operator+=(Vector2D vectorToAdd)
{
	X = X + vectorToAdd.X;
	Y = Y + vectorToAdd.Y;
	return { X, Y };
}

Vector2D Vector2D::operator*=(Vector2D multiplier)
{
	X = X * multiplier.X;
	Y = Y * multiplier.Y;
	return { X, Y };
}

Vector2D Vector2D::operator-=(Vector2D vectorToSubtract)
{
	X = X - vectorToSubtract.X;
	Y = Y - vectorToSubtract.Y;
	return { X, Y };
}

Vector2D Vector2D::operator++()
{
	return { X + 1, Y + 1};
}

bool Vector2D::operator==(Vector2D comparedVector)
{
	return (X == comparedVector.X && Y == comparedVector.Y);
}
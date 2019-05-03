#include "Matrix2D.h"

Vector2D Matrix2D::Transform(Vector2D& rhs)
{
	Vector2D Result;
	Result.X = A11 * rhs.X + A12 * rhs.Y;
	Result.Y = A21 * rhs.X + A22 * rhs.Y;
	return Result;
}

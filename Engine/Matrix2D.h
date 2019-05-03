#pragma once

#include "Vector2D.h"

class Matrix2D
{
public:
	Vector2D Transform(Vector2D& rhs);

public:
	float A11;
	float A21;
	float A12;
	float A22;
};
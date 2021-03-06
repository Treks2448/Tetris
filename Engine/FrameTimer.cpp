#include "FrameTimer.h"

using namespace std::chrono;

FrameTimer::FrameTimer()
{
	Last = steady_clock::now();
}

float FrameTimer::Mark()
{
	const auto Old = Last;
	Last = steady_clock::now();
	const duration<float> FrameTime = Last - Old;
	return FrameTime.count();
}

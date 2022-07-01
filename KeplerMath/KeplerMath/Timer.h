#pragma once

#include <chrono>

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;

	std::chrono::time_point<clock_t> s_timePoint;
public:
	Timer()
	{
		Start();
	}
	
	void Start()
	{
		s_timePoint = clock_t::now();
	}

	const double Elapsed()
	{
		std::chrono::time_point<clock_t> curTimePoint = clock_t::now();
		double duration = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(curTimePoint - s_timePoint).count() * 0.001f * 0.001f);

		return duration;
	}
};
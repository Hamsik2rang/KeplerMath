#pragma once

#include <chrono>

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;

	static std::chrono::time_point<clock_t>	s_timePoint;
	static int a;
public:
	static void Start()
	{
		s_timePoint = clock_t::now();
	}

	static const double Elapsed()
	{
		std::chrono::time_point<clock_t> curTimePoint = clock_t::now();
		double duration = std::chrono::duration_cast<std::chrono::milliseconds>(curTimePoint - s_timePoint).count();

		return duration;
	}
};

std::chrono::time_point<std::chrono::high_resolution_clock> Timer::s_timePoint = clock_t::now();

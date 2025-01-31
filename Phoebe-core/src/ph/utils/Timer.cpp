#include "Timer.h"

namespace ph {

	Timer::Timer() {
		Reset();
	}

	void Timer::Reset() {
		m_Start = HighResolutionClock::now();
	}

	float Timer::Elapsed() const {
		return std::chrono::duration_cast<milliseconds>(HighResolutionClock::now() - m_Start).count() / 1000.0f;
	}

	float Timer::ElapsedMillis() const {
		return Elapsed() * 1000.0f;
	}

}
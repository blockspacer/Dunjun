#ifndef DUNJUN_SYSTEM_TICKCOUNTER_HPP
#define DUNJUN_SYSTEM_TICKCOUNTER_HPP

#include <Dunjun/System/Clock.hpp>

namespace Dunjun
{
	class TickCounter
	{
	public:
		bool update(Time frequency) // frequency is the time between tick rate updates
		{
			bool reset = false;
			if (m_clock.getElapsedTime() >= frequency)
			{
				m_tickRate = m_tick * (1.0f / frequency.asSeconds());
				m_tick = 0;
				reset = true;
				m_clock.restart();
			}
			m_tick++;
			return reset;
		}

		inline f64 getTickRate() const { return m_tickRate; }

	private:
		std::size_t m_tick = 0;
		f64 m_tickRate = 0;
		Clock m_clock = Clock();

	};
}

#endif
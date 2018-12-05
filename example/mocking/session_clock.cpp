/**
 * @file session.cpp
 *
 * Test a session class
 */

#include <iostream>
#include <ctime>
#include <cassert>
#include <unistd.h>

class Clock {
public:
    virtual std::time_t start() const = 0;
    virtual std::time_t now() const = 0;
};

class TimeClock : public Clock {
public: 
    virtual std::time_t start() const { return now(); }
    virtual std::time_t now() const { return std::time(nullptr); }
};

class OneHourClock : public Clock {
public: 
    virtual std::time_t start() const { return 0; }
    virtual std::time_t now() const { return 3600; }
};

class ConfigurableClock : public Clock {
private:
    std::time_t length;
public:
    ConfigurableClock(std::time_t length) : length(length) {}
    virtual std::time_t start() const { return 0; }
    virtual std::time_t now() const { return length; }
};


class Session {
private:
    const Clock & clock;
    std::time_t start_time;
public:
    Session(const Clock & clock) : clock(clock), start_time(clock.start()) {}
    int elapsed() { return clock.now() - start_time; }
};

int main() {

    {
	// setup
	TimeClock time_clock;
	Session s(time_clock);

	// test
	sleep(2);
	
	// verify
	assert(s.elapsed() == 2);
    }

    {
	// setup
	OneHourClock clock;
	Session s(clock);

	// verify
	assert(s.elapsed() == 3600);
    }

    {
	// setup
	ConfigurableClock clock(86400);
	Session s(clock);

	// verify
	assert(s.elapsed() == 86400);
    }

}

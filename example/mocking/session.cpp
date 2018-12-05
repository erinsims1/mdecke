/**
 * @file session.cpp
 *
 * Test a session class
 */

#include <iostream>
#include <ctime>
#include <cassert>
#include <unistd.h>

class Session {
private:
    std::time_t start_time;
public:
    Session() : start_time(std::time(nullptr)) {}
    int elapsed() { return std::time(nullptr) - start_time; }
};

int main() {

    {
	// setup
	Session s;

	// test
	sleep(2);
	
	// verify
	assert(s.elapsed() == 2);
    }

    {
	// setup
	Session s;

	// test
	sleep(3600);
	
	// verify
	assert(s.elapsed() == 3600);
    }

}

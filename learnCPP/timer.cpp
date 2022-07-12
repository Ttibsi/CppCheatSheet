#include <chrono>

/*
* To use this, just import it using an #include and then create a timer object
* and cout object.elapsed() to see how long the code took to run
*/

class Timer {
	// Type aliases to make accessing nested type easier
	using clock_type = std::chrono::steady_clock;
	using second_type = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_type> start {clock_type::now()};

public:
    void reset() { start = clock_type::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<second_type>(
            clock_type::now() - start
        ).count();
    }
};

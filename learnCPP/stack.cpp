#include <array>
#include <cassert>
#include <iostream>

class Stack
{
private:
	// We use a std::array to store the elements
	using container_type = std::array<int, 10>;
	// For convenience, add a type alias for the type of the indexes
	using size_type = container_type::size_type;

	container_type m_array {}; // Here's where we're going to store our stack data
	size_type m_next{ 0 }; // This will hold the index of the next free element on the stack

    public:

        void reset() { m_next = 0; }

        bool push(int value) {
            // If the stack is already full, return false now
            if (m_next == m_array.size())
                return false;

            m_array[m_next++] = value; // set the next free element to the value, then increase m_next
            return true;
        }

        int pop() {
            // If there are no elements on the stack, assert out
            assert (m_next > 0 && "Can not pop empty stack");

            return m_array[--m_next];
        }

        void print() {
            std::cout << "( ";
            for (size_type i{ 0 }; i < m_next; ++i)
                std::cout << m_array[i] << ' ';
            std::cout << ")\n";
        }
};

int main() {

}

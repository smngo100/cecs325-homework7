//
// Created by sophi on 5/3/2025.
//

#include "StringQueue.h"

// Fields //
// std::string* m_data, an array in dynamic memory that stores the elements of the queue.


// size_t m_dataSize, the length of the currently-used m_data array, initially 8.


// size_t m_count, the number of elements that are still in the queue, initially 0.


// size_t m_front, the index of where the "front" element is stored, initially 0.


// size_t m_rear, the index of where the next element to be enqueued will be placed, initially 0.







// Constructors //
// A default constructor, which initializes the queue with a dynamic data array of length 8.










// Functions //
// size_t size() const, which returns the number of elements in the queue.


// size_t capacity() const, which returns the number of elements that could be added to the queue without requiring it to resize.


// void clear(), which resets m_count, m_front, and m_rear to 0.


// void enqueue(std::string value), which first resizes the queue if its capacity is 0; and then moves the value into m_data at the index specified by m_rear. m_rear is incremented, resetting back to 0 if it has reached the end of the data array.





// ALSO IMPLEMENT //
// ~StringQueue(), a destructor that frees the m_data array.
// A copy constructor that performs a deep copy of its parameter.
// A copy assignment operator=, that overrides lhs with a deep copy of rhs, but only after freeing the m_data array already owned by lhs.
// A move constructor that takes ownership of a temporary StringQueue's data array, and sets the temporary's array to nullptr.
// A move assignment operator=, that overrides lhs by swapping its m_data pointer with rhs's, so that the temporary rhs will automatically destroy lhs's old data array.



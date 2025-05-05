//
// Created by sophi on 5/3/2025.
//

#ifndef STRINGQUEUE_H
#define STRINGQUEUE_H

#include <iostream>

class StringQueue {
private:
    std::string* m_data;	// Stores the elements of the queue
    size_t m_dataSize;		// Length of the currently used array
    size_t m_count;			// # of elements that are still in queue
    size_t m_front;			// Index of where the "front" element is stored
    size_t m_rear;			// Index of where the next element to be enqueued will be placed

public:
	// Constructors, destructor, and operators
	StringQueue();										// Default constructor
	~StringQueue();										// Destructor
	StringQueue(const StringQueue& other); 				// Copy constructor
	StringQueue& operator=(const StringQueue& other); 	// Copy assignment operator=
	StringQueue(StringQueue&& other);					// Move constructor
	StringQueue& operator=(StringQueue&& other);		// Move assignment operator=

	// Queue operations
	size_t size() const;				// Returns the # of elements in the queue
	size_t capacity() const;			// Returns the # of elements that *could* be added to the queue withnout resizing
	void clear();						// Resets m_count, m_front, and m_rear to 0
	void enqueue(std::string value);	// Resizes the queue if its capacity is 0, moves the val into m_data, resets to 0 if reaches end of array
	std::string dequeue();				// Moves the element at front of queue into temp string, ++m_front , returns temp

	// Friend function for output
	friend sd::ostream& operator<<(sd::ostream& lhs, const StringQueue& rhs);
};



#endif //STRINGQUEUE_H

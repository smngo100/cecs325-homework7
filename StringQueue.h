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
	StringQueue();										// Default constructor
	~StringQueue();										// Destructor
	StringQueue(const StringQueue& other); 				// Copy constructor
	StringQueue& operator=(const StringQueue& other); 	// Copy assignment operator=
	StringQueue(StringQueue&& other);					// Move constructor
	StringQueue& operator=(StringQueue&& other);		// Move assignment operator=
};



#endif //STRINGQUEUE_H

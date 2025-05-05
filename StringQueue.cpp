//
// Created by sophi on 5/3/2025.
//

#include "StringQueue.h"

StringQueue::StringQueue() {
    m_dataSize = 8;
    m_data = new std::string[m_dataSize];
    m_count = 0;
    m_front = 0;
    m_rear = 0;
}

StringQueue::~StringQueue() {
    delete[] m_data;
}

StringQueue::StringQueue(const StringQueue& other)
    : m_dataSize(other.m_dataSize), m_count(other.m_count),
      m_front(0), m_rear(other.m_count)
{
    m_data = new std::string[m_dataSize];

    for (size_t i = 0; i < m_count; ++i) {
        size_t index = (other.m_front + i) % other.m_dataSize;
        m_data[i] = other.m_data[index];
    }
}

StringQueue& operator=(const StringQueue& other) {
    if (this == &other) {
        return *this;
    }

    m_count = other.m_count;
    m_dataSize = other.m_dataSize;
    delete[] m_data;
    m_data = new std::string[m_dataSize];

    for (size_t i = 0; i < m_count; ++i) {
        size_t index = (other.m_front + i) % other.m_dataSize;
        m_data[i] = other.m_data[index];
    }

    m_front = 0;
    m_rear = m_count;

    return *this;
}

StringQueue::StringQueue(StringQueue&& other)
    : m_data(other.m_data),
      m_dataSize(other.m_dataSize),
      m_count(other.m_count),
      m_front(other.m_front),
      m_rear(other.m_rear)

{
    other.m_data = nullptr;
    other.m_count = 0;
    other.m_dataSize = 0;
    other.m_front = 0;
    other.m_rear = 0;
}

StringQueue& StringQueue::operator=(StringQueue&& other) {
    if (this == &other) {
        return *this;
    }

    delete[] m_data;

    m_data = other.m_data;
    m_count = other.m_count;
    m_dataSize = other.m_dataSize;
    m_front = other.m_front;
    m_rear = other.m_rear;

    other.m_data = nullptr;
    other.m_count = 0;
    other.m_dataSize = 0;
    other.m_front = 0;
    other.m_rear = 0;

    return *this;
}

size_t size() const {
    return m_count;
}

size_t capacity() const {
    return m_dataSize - m_count;
}

void clear() {
    m_count = 0;
    m_front = 0;
    m_rear = 0;
}

void enqueue(std::string value) {
    if (capacity() == 0) {
        size_t newSize = m_dataSize * 2;
        std::string* newData = new std::string[newSize];

        for (size_t i = 0; i < m_count; ++i) {
            size_t oldIndex = (m_front + i) % m_dataSize;
            newData[i] = std::move(m_data[oldIndex]);
        }

        delete[] m_data;
        m_data = newData;
        m_front = 0;
        m_rear = m_count;
        m_dataSize = newSize;
    }

    m_data[m_rear] = std::move(value);
    m_rear = (m_rear + 1) % m_dataSize;
    ++m_count;
}

std::string dequeue() {
    if (m_count == 0) {
        return std::string("");
    }

    std::string temp = std::move(m_data[m_front]);
    m_front = (m_front + 1) % m_dataSize;
    --m_count;
    return temp;
}

std::ostream& operator<<(std::ostream& lhs, const StringQueue& rhs) {
    if (rhs.m_count == 0) {
        return lhs;
    }

    lhs << rhs.m_data[rhs.m_front];

    for (size_t i = 1; i < rhs.m_count; ++i) {
        size_t index = (rhs.m_front + i) % rhs.m_dataSize;
        lhs << "," << rhs.m_data[index];
    }
    return lhs;
}
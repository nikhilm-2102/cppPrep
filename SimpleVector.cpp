#include <stdexcept>
#include <iostream>

class SimpleVector {
    int* array;
    int size;
    int capacity;

    void copyData(const int* sourceArray, int* destArray, int nSize) const {
        for (int i = 0; i < nSize; ++i) {
            destArray[i] = sourceArray[i];
        }
    }

    void reallocate(int newCapacity) {
        int* newArray = new int[newCapacity];
        copyData(array, newArray, size);
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

public:
    SimpleVector() : array(new int[5]), size(0), capacity(5) {}

    SimpleVector(const SimpleVector& rVector)
        : array(new int[rVector.capacity]), size(rVector.size), capacity(rVector.capacity) {
        copyData(rVector.array, array, size);
    }

    SimpleVector& operator=(const SimpleVector& rVector) {
        if (this != &rVector) {
            delete[] array;
            size = rVector.size;
            capacity = rVector.capacity;
            array = new int[capacity];
            copyData(rVector.array, array, size);
        }
        return *this;
    }

    SimpleVector(SimpleVector&& rvalVector) noexcept
        : array(rvalVector.array), size(rvalVector.size), capacity(rvalVector.capacity) {
        rvalVector.array = nullptr;
        rvalVector.size = 0;
        rvalVector.capacity = 0;
    }

    SimpleVector& operator=(SimpleVector&& rvalVector) noexcept {
        if (this != &rvalVector) {
            delete[] array;
            array = rvalVector.array;
            size = rvalVector.size;
            capacity = rvalVector.capacity;

            rvalVector.array = nullptr;
            rvalVector.size = 0;
            rvalVector.capacity = 0;
        }
        return *this;
    }

    void push_back(int val) {
        if (size >= capacity) {
            reallocate(capacity * 2);
        }
        array[size++] = val;
    }

    int pop_back() {
        if (size == 0) {
            throw std::out_of_range("pop_back() called on empty vector");
        }
        return array[--size];
    }

    int operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return array[index];
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return array[index];
    }

    int GetSize() const {
        return size;
    }

    int GetCapacity() const {
        return capacity;
    }

    ~SimpleVector() {
        delete[] array;
    }
};

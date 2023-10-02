/**
#include "DynArr.h"

template <typename T>
DynamicVector<T>::DynamicVector() : elements(nullptr), size(0), capacity() {}

template <typename T>
DynamicVector<T>::~DynamicVector() {
    delete[] elements;
}

template <typename T>
void DynamicVector<T>::add(const T& value) {
    if (size == capacity) {
        capacity *= 2;
        if (capacity == 0) {
            capacity = 1;
        }

        T* newElements = new T[capacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }

        delete[] elements;
        elements = newElements;
    }

    elements[size] = value;
    size++;
}

template <typename T>
void DynamicVector<T>::remove(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }

        size--;
    }
}

template <typename T>
void DynamicVector<T>::update(int index, const T& value) {
    if (index >= 0 && index < size) {
        elements[index] = value;
    }
}

template <typename T>
int DynamicVector<T>::length() const {
    return size;
}

template <typename T>
T DynamicVector<T>::getElement(int index) const {
    if (index >= 0 && index < size) {
        return elements[index];
    }

    return T();  // Return default-constructed T if index is out of bounds
}

template <typename T>
T DynamicVector<T>::findPosition(const T& value) const {
    for (int i = 0; i < size; i++) {
        if (elements[i] == value) {
            return i;
        }
    }
    return -1;
}
*/

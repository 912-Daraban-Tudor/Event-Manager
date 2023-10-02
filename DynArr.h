#ifndef A45_912_DARABAN_TUDOR_DYNARR_H
#define A45_912_DARABAN_TUDOR_DYNARR_H
template <typename T>
class DynamicVector {
private:
    T* elements;
    int size;
    int capacity;

public:
    DynamicVector() : elements(nullptr), size(0), capacity(0) {}
    ~DynamicVector() { delete[] elements; }


    void add(const T& value) {
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

    void remove(int index)
    {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                elements[i] = elements[i + 1];
            }

            size--;
        }
    }

    void update(int index, const T& value)
    {
        if (index >= 0 && index < size) {
            elements[index] = value;
        }
    }

    int length() const {
        return size;
    }

    T getElement(int index) const {
        if (index >= 0 && index < size) {
            return elements[index];
        }

        return T();  // Return default-constructed T if index is out of bounds
    }

    int findPosition(const T& value) const {
        for (int i = 0; i < size; i++) {
            if (elements[i] == value) {
                return i;
            }
        }
        return -1;
    }
};

#endif //A45_912_DARABAN_TUDOR_DYNARR_H

#include <iostream>

template <typename T>
class SimpleVector {
private:
    T* data;              // ������ �迭
    size_t current_size;  // ���� ���� ����
    size_t max_capacity;  // �迭�� ũ��

public:
    // �⺻ ������: ũ�Ⱑ 10�� �迭 ����
    SimpleVector() : current_size(0), max_capacity(10) {
        data = new T[max_capacity];
    }

    // ũ�⸦ �����ϴ� ������
    SimpleVector(size_t capacity) : current_size(0), max_capacity(capacity) {
        data = new T[max_capacity];
    }

    // �Ҹ���: ���� �޸� ����
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: ���Ҹ� �� �ڿ� �߰�
    void push_back(const T& value) {
        if (current_size < max_capacity) {
            data[current_size++] = value;
        }
    }

    // pop_back: ������ ���� ����
    void pop_back() {
        if (current_size > 0) {
            --current_size;
        }
    }

    // size: ���� ������ ���� ��ȯ
    size_t size() const {
        return current_size;
    }

    // capacity: �迭�� ũ�� ��ȯ
    size_t capacity() const {
        return max_capacity;
    }

    // ���� ���� ������ (���� ����)
    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }
};

int main() {
    // �⺻ �����ڸ� ����� ���� ����
    SimpleVector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    std::cout << "vec1 size: " << vec1.size() << ", capacity: " << vec1.capacity() << std::endl;

    vec1.pop_back();
    std::cout << "vec1 size after pop_back: " << vec1.size() << std::endl;

    // ũ�⸦ ������ �����ڸ� ����� ���� ����
    SimpleVector<int> vec2(5);
    for (int i = 0; i < 6; ++i) {
        vec2.push_back(i);
    }
    std::cout << "vec2 size: " << vec2.size() << ", capacity: " << vec2.capacity() << std::endl;

    return 0;
}

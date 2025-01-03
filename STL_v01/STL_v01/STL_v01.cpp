#include <iostream>

template <typename T>
class SimpleVector {
private:
    T* data;              // 데이터 배열
    size_t current_size;  // 현재 원소 개수
    size_t max_capacity;  // 배열의 크기

public:
    // 기본 생성자: 크기가 10인 배열 생성
    SimpleVector() : current_size(0), max_capacity(10) {
        data = new T[max_capacity];
    }

    // 크기를 지정하는 생성자
    SimpleVector(size_t capacity) : current_size(0), max_capacity(capacity) {
        data = new T[max_capacity];
    }

    // 소멸자: 동적 메모리 해제
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: 원소를 맨 뒤에 추가
    void push_back(const T& value) {
        if (current_size < max_capacity) {
            data[current_size++] = value;
        }
    }

    // pop_back: 마지막 원소 제거
    void pop_back() {
        if (current_size > 0) {
            --current_size;
        }
    }

    // size: 현재 원소의 개수 반환
    size_t size() const {
        return current_size;
    }

    // capacity: 배열의 크기 반환
    size_t capacity() const {
        return max_capacity;
    }

    // 원소 접근 연산자 (선택 사항)
    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }
};

int main() {
    // 기본 생성자를 사용한 벡터 생성
    SimpleVector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    std::cout << "vec1 size: " << vec1.size() << ", capacity: " << vec1.capacity() << std::endl;

    vec1.pop_back();
    std::cout << "vec1 size after pop_back: " << vec1.size() << std::endl;

    // 크기를 지정한 생성자를 사용한 벡터 생성
    SimpleVector<int> vec2(5);
    for (int i = 0; i < 6; ++i) {
        vec2.push_back(i);
    }
    std::cout << "vec2 size: " << vec2.size() << ", capacity: " << vec2.capacity() << std::endl;

    return 0;
}

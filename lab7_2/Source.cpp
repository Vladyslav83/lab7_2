#include <iostream>
#include <cstring>

template <size_t N>
void shellSort(const char* (&arr)[N]) {
    size_t gap = N / 2;
    while (gap > 0) {
        for (size_t i = gap; i < N; i++) {
            const char* temp = arr[i];
            size_t j = i;

            while (j >= gap && strcmp(arr[j - gap], temp) > 0) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
        gap /= 2;
    }
}

int main() {
    const size_t arraySize = 5;
    const char* arr[arraySize] = { "apple", "banana", "grape", "orange", "kiwi" };

    shellSort(arr);

    // Print the sorted array
    for (size_t i = 0; i < arraySize; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}

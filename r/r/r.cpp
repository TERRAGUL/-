#include <iostream>
#include <vector>
#include <thread>

class MergeSort {
public:
    // Метод Sort реализует алгоритм сортировки слиянием.
    void Sort(std::vector<int>& array) {
        if (array.size() > 1) {
            // Делим массив на две части.
            std::vector<int> left(array.begin(), array.begin() + array.size() / 2);
            std::vector<int> right(array.begin() + array.size() / 2, array.end());

            std::thread leftThread(&MergeSort::Sort, this, std::ref(left));
            std::thread rightThread(&MergeSort::Sort, this, std::ref(right));

            // Ждем завершения работы потоков.
            leftThread.join();
            rightThread.join();

            Merge(array, left, right);
        }
    }

private:
    // Метод Merge объединяет два отсортированных массива в один.
    void Merge(std::vector<int>& array, const std::vector<int>& left, const std::vector<int>& right) {
        size_t i = 0, j = 0, k = 0;

        // Слияние двух частей в один отсортированный массив.
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                array[k++] = left[i++];
            }
            else {
                array[k++] = right[j++];
            }
        }

        // Копируем оставшиеся элементы из левой части, если они есть.
        while (i < left.size()) {
            array[k++] = left[i++];
        }

        // Копируем оставшиеся элементы из правой части, если они есть.
        while (j < right.size()) {
            array[k++] = right[j++];
        }
    }
};

// Функция для ввода массива пользователем
std::vector<int> inputArray(int size) {
    std::vector<int> array(size);
    std::cout << "Vvedi mne " << size << " chicel Pogaluista:" << std::endl;
    for (int& num : array) {
        std::cin >> num;
    }
    return array;
}

// Функция для вывода массива
void printArray(const std::vector<int>& array) {
    for (const int& num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Ввод массива пользователем
    std::vector<int> array = inputArray(10);

    // Создание экземпляра класса MergeSort.
    MergeSort mergeSort;

    // Определение лямбда-функции для вызова метода Sort.
    auto sortLambda = [&mergeSort](std::vector<int>& arr) {
        mergeSort.Sort(arr);
        };

    // Создание и запуск потока для выполнения сортировки.
    std::thread mergeSortThread(sortLambda, std::ref(array));

    // Ждем завершения потока.
    mergeSortThread.join();

    std::cout << "Idealniy poraydok:" << std::endl;
    printArray(array);

    return 0;
}

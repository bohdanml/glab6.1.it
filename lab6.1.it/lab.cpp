#include <iostream>
#include <cstdlib>
#include <ctime>

// Функція для генерації випадкового числа в заданому діапазоні
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Функція для створення масиву з випадковими числами
void createArray(int r[], int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        r[i] = generateRandomNumber(min, max);
    }
}

// Функція для обчислення кількості та суми додатніх елементів, крім кратних 4
void computePositiveSumAndCount(int r[], int size, int& positiveCount, int& positiveSum) {
    positiveCount = 0;
    positiveSum = 0;
    for (int i = 0; i < size; ++i) {
        if (r[i] > 0 && r[i] % 4 != 0) {
            positiveCount++;
            positiveSum += r[i];
        }
    }
}

// Функція для заміни нулями додатніх елементів, крім кратних 4
void replacePositivesWithZero(int r[], int size) {
    for (int i = 0; i < size; ++i) {
        if (r[i] > 0 && r[i] % 4 != 0) {
            r[i] = 0;
        }
    }
}

// Функція для виведення масиву на екран
void printArray(const int r[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << r[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 23;
    int r[size];
    int min = -19;
    int max = 25;

    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(nullptr)));

    createArray(r, size, min, max);
    //масив
    std::cout << "array: ";
    printArray(r, size);

    int positiveCount, positiveSum;
    computePositiveSumAndCount(r, size, positiveCount, positiveSum); 
    //Кількість додатніх, крім кратних 4:
    std::cout << "Count of positive, excluding those divisible by 4: " << positiveCount << std::endl;
    //Сума додатніх, крім кратних 4:
    std::cout << "Sum of positive, excluding those divisible by 4: " << positiveSum << std::endl;

    replacePositivesWithZero(r, size);
    //модифікований масив
    std::cout << "Modified array: ";
    printArray(r, size);

    return 0;
}

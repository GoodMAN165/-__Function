#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

// Задание 1

double power(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent > 0) {
        return base * power(base, exponent - 1);
    }
    else {
        return 1 / power(base, -exponent);
    }
}

void demonstratePower() {
    cout << "=== ЗАДАНИЕ 1: ВОЗВЕДЕНИЕ В СТЕПЕНЬ ===" << endl;

    double base;
    int exponent;

    cout << "Введите основание: ";
    cin >> base;
    cout << "Введите показатель степени: ";
    cin >> exponent;

    double result = power(base, exponent);
    cout << base << " ^ " << exponent << " = " << result << endl << endl;
}

// Задание 2

void printStars(int n) {
    if (n <= 0) {
        cout << endl;
        return;
    }
    cout << "* ";
    printStars(n - 1);
}

void demonstrateStars() {
    cout << "=== ЗАДАНИЕ 2: ВЫВОД N ЗВЕЗД В РЯД ===" << endl;

    int n;
    cout << "Введите количество звезд: ";
    cin >> n;

    if (n > 0) {
        cout << "Результат: ";
        printStars(n);
    }
    else {
        cout << "Число должно быть положительным!" << endl;
    }
    cout << endl;
}

// Задание 3

int sumRange(int a, int b) {
    if (a > b) {
        return 0;
    }
    if (a == b) {
        return a;
    }
    return a + sumRange(a + 1, b);
}

void demonstrateSumRange() {
    cout << "=== ЗАДАНИЕ 3: СУММА ЧИСЕЛ В ДИАПАЗОНЕ ===" << endl;

    int a, b;
    cout << "Введите начало диапазона (a): ";
    cin >> a;
    cout << "Введите конец диапазона (b): ";
    cin >> b;

    if (a <= b) {
        int result = sumRange(a, b);
        cout << "Сумма чисел от " << a << " до " << b << " = " << result << endl;
    }
    else {
        cout << "Ошибка: начало диапазона должно быть меньше или равно концу!" << endl;
    }
    cout << endl;
}

// Задание 4

int findMinSumSequence(int arr[], int size, int sequenceLength, int currentPos = 0) {
    // Базовый случай: если осталось меньше sequenceLength элементов
    if (currentPos > size - sequenceLength) {
        return -1; // Не найдено
    }

    // Вычисляем сумму текущей последовательности
    int currentSum = 0;
    for (int i = currentPos; i < currentPos + sequenceLength; i++) {
        currentSum += arr[i];
    }

    // Рекурсивно ищем в оставшейся части массива
    int nextPos = findMinSumSequence(arr, size, sequenceLength, currentPos + 1);

    // Если это первая найденная последовательность или текущая сумма меньше
    if (nextPos == -1) {
        return currentPos;
    }

    // Сравниваем суммы
    int nextSum = 0;
    for (int i = nextPos; i < nextPos + sequenceLength; i++) {
        nextSum += arr[i];
    }

    return (currentSum < nextSum) ? currentPos : nextPos;
}

void demonstrateMinSumSequence() {
    cout << "=== ЗАДАНИЕ 4: ПОИСК ПОСЛЕДОВАТЕЛЬНОСТИ С МИНИМАЛЬНОЙ СУММОЙ ===" << endl;

    const int SIZE = 100;
    const int SEQUENCE_LENGTH = 10;
    int arr[SIZE];

    // Заполняем массив случайными числами
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100; // числа от 0 до 99
    }

    // Находим позицию с минимальной суммой
    int position = findMinSumSequence(arr, SIZE, SEQUENCE_LENGTH);

    if (position != -1) {
        // Вычисляем сумму найденной последовательности
        int minSum = 0;
        for (int i = position; i < position + SEQUENCE_LENGTH; i++) {
            minSum += arr[i];
        }

        cout << "Позиция начала последовательности: " << position << endl;
        cout << "Минимальная сумма: " << minSum << endl;
        cout << "Последовательность: ";
        for (int i = position; i < position + SEQUENCE_LENGTH; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Последовательность не найдена!" << endl;
    }
    cout << endl;
}

// Задание 5

// Максимум в одномерном массиве
int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Максимум в двумерном массиве
int findMax(int** matrix, int rows, int cols) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Максимум в трехмерном массиве
int findMax(int*** array3D, int dim1, int dim2, int dim3) {
    int maxVal = array3D[0][0][0];
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                if (array3D[i][j][k] > maxVal) {
                    maxVal = array3D[i][j][k];
                }
            }
        }
    }
    return maxVal;
}

// Максимум двух целых чисел
int findMax(int a, int b) {
    return (a > b) ? a : b;
}

// Максимум трех целых чисел
int findMax(int a, int b, int c) {
    return findMax(a, findMax(b, c));
}

void demonstrateMaxFunctions() {
    cout << "=== ЗАДАНИЕ 5: ПЕРЕГРУЖЕННЫЕ ФУНКЦИИ ПОИСКА МАКСИМУМА ===" << endl;

    // Демонстрация для одномерного массива
    const int SIZE_1D = 5;
    int arr1D[SIZE_1D] = { 3, 7, 2, 9, 1 };
    cout << "Одномерный массив: ";
    for (int i = 0; i < SIZE_1D; i++) {
        cout << arr1D[i] << " ";
    }
    cout << "\nМаксимум: " << findMax(arr1D, SIZE_1D) << endl;

    // Демонстрация для двумерного массива
    const int ROWS = 3, COLS = 3;
    int** matrix2D = new int* [ROWS];
    for (int i = 0; i < ROWS; i++) {
        matrix2D[i] = new int[COLS];
        for (int j = 0; j < COLS; j++) {
            matrix2D[i][j] = rand() % 100;
        }
    }

    cout << "\nДвумерный массив:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix2D[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Максимум: " << findMax(matrix2D, ROWS, COLS) << endl;

    // Демонстрация для трехмерного массива
    const int DIM1 = 2, DIM2 = 2, DIM3 = 2;
    int*** array3D = new int** [DIM1];
    for (int i = 0; i < DIM1; i++) {
        array3D[i] = new int* [DIM2];
        for (int j = 0; j < DIM2; j++) {
            array3D[i][j] = new int[DIM3];
            for (int k = 0; k < DIM3; k++) {
                array3D[i][j][k] = rand() % 100;
            }
        }
    }

    cout << "\nТрехмерный массив:" << endl;
    for (int i = 0; i < DIM1; i++) {
        cout << "Слой " << i << ":" << endl;
        for (int j = 0; j < DIM2; j++) {
            for (int k = 0; k < DIM3; k++) {
                cout << array3D[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Максимум: " << findMax(array3D, DIM1, DIM2, DIM3) << endl;

    // Демонстрация для двух и трех чисел
    int x = 15, y = 27, z = 8;
    cout << "\nДва числа: " << x << " и " << y << endl;
    cout << "Максимум: " << findMax(x, y) << endl;

    cout << "\nТри числа: " << x << ", " << y << " и " << z << endl;
    cout << "Максимум: " << findMax(x, y, z) << endl;

    // Освобождение памяти
    for (int i = 0; i < ROWS; i++) {
        delete[] matrix2D[i];
    }
    delete[] matrix2D;

    for (int i = 0; i < DIM1; i++) {
        for (int j = 0; j < DIM2; j++) {
            delete[] array3D[i][j];
        }
        delete[] array3D[i];
    }
    delete[] array3D;
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    // Демонстрация всех заданий
    demonstratePower();
    demonstrateStars();
    demonstrateSumRange();
    demonstrateMinSumSequence();
    demonstrateMaxFunctions();

    return 0;
}
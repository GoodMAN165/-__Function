#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Задание 1

// Инициализация квадратной матрицы (int)
void initMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100; // случайные числа от 0 до 99
        }
    }
}

// Инициализация квадратной матрицы (double)
void initMatrix(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (rand() % 10000) / 100.0; // случайные числа от 0.00 до 99.99
        }
    }
}

// Инициализация квадратной матрицы (char)
void initMatrix(char** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 'A' + rand() % 26; // случайные буквы A-Z
        }
    }
}

// Вывод матрицы на экран (int)
void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Вывод матрицы на экран (double)
void printMatrix(double** matrix, int size) {
    cout << fixed;
    cout.precision(2);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Вывод матрицы на экран (char)
void printMatrix(char** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Определение максимального и минимального элемента на главной диагонали (int)
void findMinMaxDiagonal(int** matrix, int size, int& min, int& max) {
    min = matrix[0][0];
    max = matrix[0][0];
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
}

// Определение максимального и минимального элемента на главной диагонали (double)
void findMinMaxDiagonal(double** matrix, int size, double& min, double& max) {
    min = matrix[0][0];
    max = matrix[0][0];
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
}

// Определение максимального и минимального элемента на главной диагонали (char)
void findMinMaxDiagonal(char** matrix, int size, char& min, char& max) {
    min = matrix[0][0];
    max = matrix[0][0];
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
}

// Сортировка элементов по возрастанию для каждой строки матрицы (int)
void sortRows(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        sort(matrix[i], matrix[i] + size);
    }
}

// Сортировка элементов по возрастанию для каждой строки матрицы (double)
void sortRows(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        sort(matrix[i], matrix[i] + size);
    }
}

// Сортировка элементов по возрастанию для каждой строки матрицы (char)
void sortRows(char** matrix, int size) {
    for (int i = 0; i < size; i++) {
        sort(matrix[i], matrix[i] + size);
    }
}

// Функция для демонстрации работы с матрицами
void demonstrateMatrixFunctions() {
    cout << "=== ДЕМОНСТРАЦИЯ РАБОТЫ С МАТРИЦАМИ ===" << endl;

    const int SIZE = 4;

    // Создание и работа с int матрицей
    cout << "\n1. Матрица типа int:" << endl;
    int** intMatrix = new int* [SIZE];
    for (int i = 0; i < SIZE; i++) {
        intMatrix[i] = new int[SIZE];
    }

    initMatrix(intMatrix, SIZE);
    cout << "Исходная матрица:" << endl;
    printMatrix(intMatrix, SIZE);

    int minInt, maxInt;
    findMinMaxDiagonal(intMatrix, SIZE, minInt, maxInt);
    cout << "Минимум на главной диагонали: " << minInt << endl;
    cout << "Максимум на главной диагонали: " << maxInt << endl;

    sortRows(intMatrix, SIZE);
    cout << "Матрица после сортировки строк:" << endl;
    printMatrix(intMatrix, SIZE);

    // Освобождение памяти
    for (int i = 0; i < SIZE; i++) {
        delete[] intMatrix[i];
    }
    delete[] intMatrix;
}

// Задание 2
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void demonstrateGCD() {
    cout << "\n=== ДЕМОНСТРАЦИЯ НАХОЖДЕНИЯ НОД ===" << endl;

    int num1, num2;
    cout << "Введите два целых числа: ";
    cin >> num1 >> num2;

    int result = gcd(abs(num1), abs(num2));
    cout << "НОД(" << num1 << ", " << num2 << ") = " << result << endl;
}

// Задание 3

// Функция для генерации случайного четырехзначного числа без повторяющихся цифр
string generateSecretNumber() {
    string secret = "";
    vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Перемешиваем цифры
    for (int i = 0; i < 10; i++) {
        int j = rand() % 10;
        swap(digits[i], digits[j]);
    }

    // Берем первые 4 цифры (если первая 0, то меняем)
    for (int i = 0; i < 4; i++) {
        secret += to_string(digits[i]);
    }

    // Если первая цифра 0, меняем с другой позицией
    if (secret[0] == '0') {
        for (int i = 1; i < 4; i++) {
            if (secret[i] != '0') {
                swap(secret[0], secret[i]);
                break;
            }
        }
    }

    return secret;
}

// Рекурсивная функция для игры
void playBullsAndCows(const string& secret, int attempts = 1) {
    string guess;
    cout << "Попытка " << attempts << ". Введите ваше предположение (4 цифры): ";
    cin >> guess;

    // Проверка корректности ввода
    if (guess.length() != 4) {
        cout << "Ошибка! Введите ровно 4 цифры." << endl;
        playBullsAndCows(secret, attempts);
        return;
    }

    for (char c : guess) {
        if (!isdigit(c)) {
            cout << "Ошибка! Вводите только цифры." << endl;
            playBullsAndCows(secret, attempts);
            return;
        }
    }

    // Проверка на повторяющиеся цифры
    bool hasDuplicates = false;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (guess[i] == guess[j]) {
                hasDuplicates = true;
                break;
            }
        }
    }

    if (hasDuplicates) {
        cout << "Ошибка! Цифры не должны повторяться." << endl;
        playBullsAndCows(secret, attempts);
        return;
    }

    // Подсчет быков и коров
    int bulls = 0; // цифра на своем месте
    int cows = 0;  // цифра есть в числе, но не на своем месте

    for (int i = 0; i < 4; i++) {
        if (guess[i] == secret[i]) {
            bulls++;
        }
        else if (secret.find(guess[i]) != string::npos) {
            cows++;
        }
    }

    cout << "Быки: " << bulls << ", Коровы: " << cows << endl;

    // Проверка победы
    if (bulls == 4) {
        cout << "\nПоздравляем! Вы угадали число " << secret << " за " << attempts << " попыток!" << endl;
        return;
    }

    // Рекурсивный вызов для следующей попытки
    playBullsAndCows(secret, attempts + 1);
}

void demonstrateBullsAndCows() {
    cout << "\n=== ИГРА 'БЫКИ И КОРОВЫ' ===" << endl;
    cout << "Правила:" << endl;
    cout << "- Компьютер загадал 4-значное число с неповторяющимися цифрами" << endl;
    cout << "- Быки: цифра на своем месте" << endl;
    cout << "- Коровы: цифра есть в числе, но не на своем месте" << endl;
    cout << "- Угадайте число!" << endl;

    srand(time(0));
    string secret = generateSecretNumber();
    playBullsAndCows(secret);
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    // Демонстрация работы с матрицами
    demonstrateMatrixFunctions();

    // Демонстрация нахождения НОД
    demonstrateGCD();

    // Демонстрация игры "Быки и коровы"
    demonstrateBullsAndCows();

    return 0;
}
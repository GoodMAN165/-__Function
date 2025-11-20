#include <iostream>

using namespace std;

//Функция для вычисления степени числа
double power(double base, int exponent) {
    if (exponent == 0) return 1;

    double result = 1;
    bool negative = false;

    if (exponent < 0) {
        negative = true;
        exponent = -exponent;
    }

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    if (negative) {
        return 1.0 / result;
    }
    return result;
}

//Функция для вычисления суммы чисел в диапазоне
int sumInRange(int a, int b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int sum = 0;
    for (int i = a + 1; i < b; i++) {
        sum += i;
    }
    return sum;
}

//Функция для проверки, является ли число совершенным
bool isPerfect(int number) {
    if (number < 2) return false;

    int sum = 1;

    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    return sum == number;
}

// Функция для поиска совершенных чисел в интервале
void findPerfectNumbers(int start, int end) {
    cout << "Совершенные числа в интервале [" << start << ", " << end << "]: ";
    bool found = false;

    for (int i = start; i <= end; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "не найдено";
    }
    cout << endl;
}

//Функция для вывода игральной карты
void printCard(int value, char suit) {
    cout << " ------ " << endl;

    cout << "|";
    if (value == 1) cout << "A     |" << endl;
    else if (value == 10) cout << "10    |" << endl;
    else if (value == 11) cout << "J     |" << endl;
    else if (value == 12) cout << "Q     |" << endl;
    else if (value == 13) cout << "K     |" << endl;
    else cout << char('0' + value) << "     |" << endl;

    cout << "|      |" << endl;

    cout << "|   ";
    if (suit == 'H') cout << "♥";
    else if (suit == 'D') cout << "♦";
    else if (suit == 'C') cout << "♣";
    else if (suit == 'S') cout << "♠";
    else cout << suit;
    cout << "  |" << endl;

    cout << "|      |" << endl;

    cout << "|     ";
    if (value == 1) cout << "A";
    else if (value == 10) cout << "10";
    else if (value == 11) cout << "J";
    else if (value == 12) cout << "Q";
    else if (value == 13) cout << "K";
    else cout << char('0' + value);
    cout << "|" << endl;

    cout << " ------ " << endl;
}

//Функция для проверки "счастливого" шестизначного числа
bool isLuckyNumber(int number) {
    if (number < 100000 || number > 999999) {
        return false;
    }

    int digits[6];
    int temp = number;

    for (int i = 5; i >= 0; i--) {
        digits[i] = temp % 10;
        temp /= 10;
    }

    int firstSum = digits[0] + digits[1] + digits[2];
    int secondSum = digits[3] + digits[4] + digits[5];

    return firstSum == secondSum;
}

int main() {
    cout << "=== Задание 1: Вычисление степени ===" << endl;
    double base = 2.5;
    int exponent = 3;
    cout << base << " в степени " << exponent << " = " << power(base, exponent) << endl;

    base = 4;
    exponent = -2;
    cout << base << " в степени " << exponent << " = " << power(base, exponent) << endl;

    cout << "\n=== Задание 2: Сумма чисел в диапазоне ===" << endl;
    int a = 5, b = 10;
    cout << "Сумма чисел между " << a << " и " << b << " = " << sumInRange(a, b) << endl;

    a = 10, b = 5;
    cout << "Сумма чисел между " << a << " и " << b << " = " << sumInRange(a, b) << endl;

    cout << "\n=== Задание 3: Совершенные числа ===" << endl;
    findPerfectNumbers(1, 30);
    findPerfectNumbers(100, 1000);

    cout << "\n=== Задание 4: Игральная карта ===" << endl;
    printCard(1, 'H');  // Туз червей
    printCard(10, 'D'); // Десятка бубен
    printCard(12, 'S'); // Дама пик

    cout << "\n=== Задание 5: Счастливые числа ===" << endl;
    int lucky1 = 123321;
    int lucky2 = 123456;

    cout << "Число " << lucky1 << " является счастливым: "
        << (isLuckyNumber(lucky1) ? "Да" : "Нет") << endl;
    cout << "Число " << lucky2 << " является счастливым: "
        << (isLuckyNumber(lucky2) ? "Да" : "Нет") << endl;

    return 0;
}
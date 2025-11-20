#include <iostream>

using namespace std;

//Функция для вывода прямоугольника на экран с заданной высотой и шириной
void drawRect(int& H, int& W) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << " * ";
        }
        cout << endl;
    }
}

//Функция для вычисления факториала числа
int fact(int& numF) {
    static int numFact = 1;
    for (int i = 2; i < numF + 1; i++) {
        numFact *= i;
    }

    return numFact;
}

//Функция для проверки числа на простое
bool isPrime(int& userNum)
{
    if (userNum == 1)
        return false; 

    for (int i = 2; i <= sqrt(userNum); i++)
    {
        if (userNum % i == 0)
            return false;
    }

    return true;
}

//Функция для возведения числа в куб
int cubeNum(int& userNum) {
    return userNum * userNum * userNum;
}

//Функция для нахождения наибольшего из двух чисел
void numC(int& num1, int& num2) {
    if (num1 < num2) {
        cout << num1 << "больше" << num2;
    }
    else {
        cout << num2 << "больше" << num1;
    }
}

//Функция для проверки числа на положительное или отрицательное
bool numPosOrNeg(int& userNum) {
    if (userNum < 0) {
        return false;
    }
    else {
        return true;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    int Height;
    int Width;

    cout << "Введите ширину и высоту желаемого прямоугольника: "; cin >> Height >> Width;

    drawRect(Height, Width);

    int userNum;

    cout << "Укажите число для факториала: ";cin >> userNum;
    cout << fact(userNum) << endl;


    cout << "Введите любое число для проверки: ";cin >> userNum;
    cout << "Число является простым: " << isPrime(userNum) << endl;

    cout << "Введите любое число для возведения его в куб: ";cin >> userNum;
    cout << "Куб числа: " << cubeNum(userNum);

    int userNum1;

    cout << "Введите два любого числа: ";cin >> userNum >> userNum1;
    numC(userNum, userNum1);

    cout << "Введите любое число для проверки на положительное или отрицательное: ";cin >> userNum;
    cout << "Число положительное?: " << numPosOrNeg(userNum);

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Структура для представлення точки з координатами (x, y)
struct Point {
    double x;
    double y;
};

// Функція для перевірки, чи точка належить трикутнику ABC
bool InsideTriangle(Point A, Point B, Point C, Point P) {
    // Використовуємо формулу площі трикутника для перевірки
    double ABC = abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
    double PAB = abs((P.x * (A.y - B.y) + A.x * (B.y - P.y) + B.x * (P.y - A.y)) / 2.0);
    double PBC = abs((P.x * (B.y - C.y) + B.x * (C.y - P.y) + C.x * (P.y - B.y)) / 2.0);
    double PCA = abs((P.x * (C.y - A.y) + C.x * (A.y - P.y) + A.x * (P.y - C.y)) / 2.0);

    // Якщо сума площ PAB, PBC і PCA дорівнює площі ABC, то точка P належить трикутнику
    return PAB + PBC + PCA == ABC;
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points(n);

    char choice;
    cout << "Choose the data input method (c - console, f - file, r - random numbers): ";
    cin >> choice;

    switch (choice) {
    case 'c': // Введення даних з консолі
        cout << "Enter the coordinates of points in the format (x y):" << endl;
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        break;

    case 'f': // Введення даних з файлу
    {
        string filename;
        cout << "Enter the file name: ";
        cin >> filename;

        ifstream inputFile(filename);

        if (!inputFile) {
            cerr << "Error opening the file." << endl;
            return 1;
        }

        for (int i = 0; i < n; i++) {
            inputFile >> points[i].x >> points[i].y;
        }

        inputFile.close();
    }
    break;

    case 'r': // Введення даних за допомогою датчика випадкових чисел
        srand(time(0)); // Ініціалізуємо генератор випадкових чисел
        for (int i = 0; i < n; i++) {
            points[i].x = rand() % 100; // Генеруємо випадкові координати в діапазоні [0, 99]
            points[i].y = rand() % 100;
        }
        break;

    default:
        cout << "Invalid choice." << endl;
        return 1;
    }

    Point A, B, C;
    cout << "Enter the coordinates of triangle vertices A, B, C in the format (x y): ";
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    int countInside = 0; // Кількість точок, що належать трикутнику

    for (int i = 0; i < n; i++) {
        if (InsideTriangle(A, B, C, points[i])) {
            countInside++;
        }
    }

    cout << "Number of points inside triangle ABC: " << countInside << endl;

    return 0;
}

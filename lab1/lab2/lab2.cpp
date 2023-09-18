#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    int N;
    cout << "Enter the size of the array N:  ";
    cin >> N;

    vector<int> A(N);

    char choice;
    cout << "Choose a method for data input (c - console, f - file, r - random numbers): ";
    cin >> choice;

    switch (choice) {
    case 'c': // Введення даних з консолі
        cout << "Enter " << N << " integers: ";
        for (int i = 0; i < N; i++) {
            cin >> A[i];
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

        for (int i = 0; i < N; i++) {
            inputFile >> A[i];
        }

        inputFile.close();
    }
    break;

    case 'r': // Введення даних за допомогою датчика випадкових чисел
        srand(time(0)); // Ініціалізуємо генератор випадкових чисел
        for (int i = 0; i < N; i++) {
            A[i] = rand() % 100; // Генеруємо випадкове число в діапазоні [0, 99]
        }
        break;

    default:
        cout << "Invalid choice." << endl;
        return 1;
    }

    int NegfirstIndex = -1; // Індекс першого від'ємного елемента
    int ElementToFind = -1; // Індекс останнього мінімального парного додатного елемента

    for (int i = 0; i < N; i++) {
        if (A[i] < 0 && NegfirstIndex == -1) {
            NegfirstIndex = i; // Знайшли перший від'ємний елемент
        }

        if (A[i] % 2 == 0 && A[i] > 0) {
            if (ElementToFind == -1 || A[i] <= A[ElementToFind]) {
                ElementToFind = i; // Оновлюємо індекс мінімального парного додатного елемента
            }
        }
    }

    if (ElementToFind != -1 && NegfirstIndex != -1 && ElementToFind > NegfirstIndex) {
        cout << "The index of the last minimum even positive element to the right of the first negative element: " << ElementToFind << endl;
    }
    else {
        cout << "Such an element was not found." << endl;
    }

    return 0;
}

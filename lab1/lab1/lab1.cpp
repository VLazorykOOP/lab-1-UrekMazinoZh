#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Функція для виведення масиву на екран
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Enter size of array N: ";
    cin >> N;

    int A[N];

    char choice;
    cout << "Choose the data input method (c - console, f - file, r - random numbers): ";
    cin >> choice;

    switch (choice) {
    case 'c': // Введення даних з консолі
        cout << "Enter " << N << " integer numbers: ";
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        break;

    case 'f': // Введення даних з файлу
    {
        string filename;
        cout << "Enter the filename: ";
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

    // Розділяємо масив на дві половини і змінюємо значення
    for (int i = 0; i < N / 2; i++) {
        A[i] *= 2;
    }

    for (int i = N / 2; i < N; i++) {
        A[i] *= 3;
    }

    // Виводимо змінений масив
    cout << "Modified array: ";
    printArray(A, N);

    return 0;
}

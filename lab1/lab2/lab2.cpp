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
    case 'c': // �������� ����� � ������
        cout << "Enter " << N << " integers: ";
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        break;

    case 'f': // �������� ����� � �����
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

    case 'r': // �������� ����� �� ��������� ������� ���������� �����
        srand(time(0)); // ���������� ��������� ���������� �����
        for (int i = 0; i < N; i++) {
            A[i] = rand() % 100; // �������� ��������� ����� � ������� [0, 99]
        }
        break;

    default:
        cout << "Invalid choice." << endl;
        return 1;
    }

    int NegfirstIndex = -1; // ������ ������� ��'������ ��������
    int ElementToFind = -1; // ������ ���������� ���������� ������� ��������� ��������

    for (int i = 0; i < N; i++) {
        if (A[i] < 0 && NegfirstIndex == -1) {
            NegfirstIndex = i; // ������� ������ ��'����� �������
        }

        if (A[i] % 2 == 0 && A[i] > 0) {
            if (ElementToFind == -1 || A[i] <= A[ElementToFind]) {
                ElementToFind = i; // ��������� ������ ���������� ������� ��������� ��������
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

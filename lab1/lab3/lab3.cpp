#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ��������� ��� ������������� ����� � ������������ (x, y)
struct Point {
    double x;
    double y;
};

// ������� ��� ��������, �� ����� �������� ���������� ABC
bool InsideTriangle(Point A, Point B, Point C, Point P) {
    // ������������� ������� ����� ���������� ��� ��������
    double ABC = abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
    double PAB = abs((P.x * (A.y - B.y) + A.x * (B.y - P.y) + B.x * (P.y - A.y)) / 2.0);
    double PBC = abs((P.x * (B.y - C.y) + B.x * (C.y - P.y) + C.x * (P.y - B.y)) / 2.0);
    double PCA = abs((P.x * (C.y - A.y) + C.x * (A.y - P.y) + A.x * (P.y - C.y)) / 2.0);

    // ���� ���� ���� PAB, PBC � PCA ������� ����� ABC, �� ����� P �������� ����������
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
    case 'c': // �������� ����� � ������
        cout << "Enter the coordinates of points in the format (x y):" << endl;
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
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

        for (int i = 0; i < n; i++) {
            inputFile >> points[i].x >> points[i].y;
        }

        inputFile.close();
    }
    break;

    case 'r': // �������� ����� �� ��������� ������� ���������� �����
        srand(time(0)); // ���������� ��������� ���������� �����
        for (int i = 0; i < n; i++) {
            points[i].x = rand() % 100; // �������� �������� ���������� � ������� [0, 99]
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

    int countInside = 0; // ʳ������ �����, �� �������� ����������

    for (int i = 0; i < n; i++) {
        if (InsideTriangle(A, B, C, points[i])) {
            countInside++;
        }
    }

    cout << "Number of points inside triangle ABC: " << countInside << endl;

    return 0;
}

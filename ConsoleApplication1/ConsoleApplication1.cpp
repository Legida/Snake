#include <iostream>
#include <windows.h>
#include "conio.h"
using namespace std;

class Field {
private:
	int width;
	int X = 1;
	int Y = 1;
	char ch = 0;
	char** field = new char* [width];
	void CreateArray() {
		for (int i = 0; i < width; i++) {
			field[i] = new char[width];
		}
	}
public:
	Field(int size) : width(size) {
		CreateArray();
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < width; j++) {
				field[i][j] = 12;
			}
		}
	}
	void CreateField() {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < width; j++) {
				if ((i % (width - 1) == 0) || (j % (width - 1) == 0)) {
					field[i][j] = '#';
				}
				else {
					field[i][j] = 32;
				}
			}
		}
	}
	void CreateSnake() {
		if (_kbhit()) {
			ch = _getch();
			switch (ch) {
			case (int )'d':
				Y++;
				break;
			case (int)'w':
				X--;
				break;
			case (int)'a':
				Y--;
				break;
			case (int)'s':
				X++;
				break;
			case 0:
				break;
			}
		}
		field[X][Y] = '0';
	}
	void CreateAll() {
		CreateField();
		CreateSnake();
	}
	const char GetField(const int& i, const int& j) {
		if ((i < width) && (j < width) && (i >= 0) && (j >= 0)) {
			return field[i][j];
		}
		else {
			cout << "ошибка в значении";
			Sleep(1000);
			exit(1);
		}
	}
};

class Frame {
private:
	int width;
	const void Output(Field A) {
		A.CreateField();
		A.CreateSnake();
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < width; j++) {
				cout << A.GetField(i, j);
				if (j == width - 1) {
					cout << endl;
				}
			}
		}
	}
public:
	Frame(int size) : width(size) {};
	const void Update(Field field) {
		Output(field);
		Sleep(33);
		system("cls");
	}
};


int main() {
	Frame A(29);
	Field B(29);
	int j = 10;
	for (int i = 0; i < j; i++) {
		A.Update(B);
		j++;
	}
}

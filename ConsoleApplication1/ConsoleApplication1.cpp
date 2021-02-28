#include <iostream>
#include <windows.h>
#include "conio.h"
using namespace std;

const int width = 25;
class Array {
private:
	char array[width][width];
	char ch;
	int X;
	int Y;
	void Input() {
		if (_kbhit()) {
			ch = _getch();
			switch ((int)ch) {
			case (int)'a':
				if (X >= 2) {
					X -= 1;
				}
				break;
			case (int)'d':
				if (X <= (width - 3)) {
					X += 1;
				}
				break;
			case (int)'s':
				if (Y <= (width - 3)) {
					Y += 1;
				}
				break;
			case (int)'w':
				if (Y >= 2) {
					Y -= 1;
				}
				break;
			}
		}
	}
	void InitArray() {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < width; j++) {
				array[i][j] = ' ';
			}
		}
	}
	void DoBorder() {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < width; j++) {
				if ((i == 0) || (i == width - 1) || (j == 0) || (j == width - 1)) {
					array[i][j] = 17;
				}
			}
		}
	}
public:
	Array() : ch(0), X(width / 2), Y(width / 2) {
		InitArray();
	}
	void OutputAndUpdate() {
		Input();
		InitArray();
		DoBorder();
		array[Y][X] = '#';
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < width; j++) {
				cout << array[i][j];
				if (j == (width - 1)) {
					cout << endl;
				}
			}
		}
		cout << endl;
		Sleep(100);
		system("cls");
	}
};

int main() {
	Array Test;
	int j = width;
	for (int i = 0; i < j; i++) {
		Test.OutputAndUpdate();
		j++;
	}
	return 1;
}
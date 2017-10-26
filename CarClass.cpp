#include "CarClass.h"

void CarClass::flickerEscape() {
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void CarClass::startCheck()
{
	while (!isStarted_)
	{
		_getch();
		isStarted_ = true;
	}
}
void CarClass::crashed() {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	cout << "\n\n    You crashed!     \n" << endl;
	_getch();
}
void CarClass::carMove() {
	if (GetAsyncKeyState(VK_LEFT)) {
		if (map[carV][carH - 3] == hitch) {
			crashed();
			exit(0);
		}
		else if (map[carV][carH - 2] != 'I') {
			map[carV][carH] = ' ';
			map[carV][carH + 1] = ' ';
			map[carV][carH - 1] = ' ';
			map[carV + 1][carH - 1] = ' ';
			map[carV + 1][carH + 1] = ' ';
			map[carV - 1][carH - 1] = ' ';
			map[carV - 1][carH + 1] = ' ';
			carH -= 1;
			map[carV][carH] = '#';
			map[carV][carH + 1] = '!';
			map[carV][carH - 1] = '!';
			map[carV + 1][carH - 1] = 'o';
			map[carV + 1][carH + 1] = 'o';
			map[carV - 1][carH - 1] = 'o';
			map[carV - 1][carH + 1] = 'o';
		}
	}

	if (GetAsyncKeyState(VK_RIGHT)) {
		if (map[carV][carH + 3] == hitch) {
			crashed();
			exit(0);
		}
		else if (map[carV][carH + 2] != 'I') {
			map[carV][carH] = ' ';
			map[carV][carH + 1] = ' ';
			map[carV][carH - 1] = ' ';
			map[carV + 1][carH - 1] = ' ';
			map[carV + 1][carH + 1] = ' ';
			map[carV - 1][carH - 1] = ' ';
			map[carV - 1][carH + 1] = ' ';
			carH += 1;
			map[carV][carH] = '#';
			map[carV][carH + 1] = '!';
			map[carV][carH - 1] = '!';
			map[carV + 1][carH - 1] = 'o';
			map[carV + 1][carH + 1] = 'o';
			map[carV - 1][carH - 1] = 'o';
			map[carV - 1][carH + 1] = 'o';
		}
	}

	if (GetAsyncKeyState(VK_UP)) {
		if (map[carV - 2][carH] == hitch) {
			crashed();
			exit(0);
		}
		else if (carV - 2 != 0) {
			map[carV][carH] = ' ';
			map[carV][carH + 1] = ' ';
			map[carV][carH - 1] = ' ';
			map[carV + 1][carH - 1] = ' ';
			map[carV + 1][carH + 1] = ' ';
			map[carV - 1][carH - 1] = ' ';
			map[carV - 1][carH + 1] = ' ';
			carV -= 1;
			map[carV][carH] = '#';
			map[carV][carH + 1] = '!';
			map[carV][carH - 1] = '!';
			map[carV + 1][carH - 1] = 'o';
			map[carV + 1][carH + 1] = 'o';
			map[carV - 1][carH - 1] = 'o';
			map[carV - 1][carH + 1] = 'o';
		}
	}

	if (GetAsyncKeyState(VK_DOWN)) {
		if (map[carV + 2][carH] == hitch) {
			crashed();
			exit(0);
		}
		else if (carV + 2 != 20) {
			map[carV][carH] = ' ';
			map[carV][carH + 1] = ' ';
			map[carV][carH - 1] = ' ';
			map[carV + 1][carH - 1] = ' ';
			map[carV + 1][carH + 1] = ' ';
			map[carV - 1][carH - 1] = ' ';
			map[carV - 1][carH + 1] = ' ';
			carV += 1;
			map[carV][carH] = '#';
			map[carV][carH + 1] = '!';
			map[carV][carH - 1] = '!';
			map[carV + 1][carH - 1] = 'o';
			map[carV + 1][carH + 1] = 'o';
			map[carV - 1][carH - 1] = 'o';
			map[carV - 1][carH + 1] = 'o';
		}
	}
}
void CarClass::keyPress() {
	if (GetAsyncKeyState(VK_RETURN)) {
		if (!isPressed_) {
			system("pause");
			isPressed_ = true;
		}
		else {
			system("cls");
			isPressed_ = false;
		}
	}

	if (GetAsyncKeyState(VK_ESCAPE)) {
		exit(0);
	}
}
void CarClass::objectsCreate() {
	score++;
	map[carV][carH] = '#';
	map[carV][carH + 1] = '!';
	map[carV][carH - 1] = '!';
	map[carV + 1][carH - 1] = 'o';
	map[carV + 1][carH + 1] = 'o';
	map[carV - 1][carH - 1] = 'o';
	map[carV - 1][carH + 1] = 'o';

	map[hitH][hitV] = ' ';
	map[hitH][hitV] = ' ';
	map[hitH][hitV + 1] = ' ';
	map[hitH][hitV - 1] = ' ';
	map[hitH + 1][hitV - 1] = ' ';
	map[hitH + 1][hitV + 1] = ' ';
	map[hitH - 1][hitV - 1] = ' ';
	map[hitH - 1][hitV + 1] = ' ';
	hitH++;
	map[hitH][hitV] = hitch;
	map[hitH][hitV] = hitch;
	map[hitH][hitV + 1] = hitch;
	map[hitH][hitV - 1] = hitch;
	map[hitH + 1][hitV - 1] = hitch;
	map[hitH + 1][hitV + 1] = hitch;
	map[hitH - 1][hitV - 1] = hitch;
	map[hitH - 1][hitV + 1] = hitch;
	if (hitH > 20) {
		hitH = 0;
		hitV = rand() % 15 + 2;
	}
}
void CarClass::mapSet() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			map[i][j] = ' ';
			map[i][0] = 'I';
			map[i][18] = 'I';
		}
	}
}
void CarClass::checker() {
	if (map[carV - 2][carH] == hitch || map[carV - 2][carH - 1] == hitch || map[carV - 2][carH + 1] == hitch) {
		crashed();
		exit(0);
	}

	if (score > s && speed > 5) {
		speed -= 10;
		s += 100;
		level++;
	}
}
void CarClass::refresher() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << map[i][j];
			if (j >= 19) cout << "\n";
		}
	}
	cout << " \n   LEVEL: " << level << " \n   SCORE: " << score << endl;
	Sleep(speed);
}
#ifndef CARCLASS_H
#define CARCLASS_H
#pragma once

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

class CarClass
{
	char map[25][25];
	int carV = 16, carH = 9;
	int hitH = 0, hitV = rand() % 15 + 2;
	int score = 0;
	int speed = 105;
	int s = 100;
	int level = 1;
	char hitch = '@';
	char player = '#';
public:
	void flickerEscape();
	void startCheck();
	void crashed();
	void carMove();
	void keyPress();
	void objectsCreate();
	void mapSet();
	void checker();
	void refresher();
private:
	bool isPressed_ = false;
	bool isStarted_ = false;
	int level_;
};

#endif
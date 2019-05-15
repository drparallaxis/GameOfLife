#pragma once
#include <iostream>
#include <conio.h>
#include <random>
#include <ctime>
#include <Windows.h>
using namespace std;

class Map
{
	int size1, size2;
public:
	char** arr;
public:
	Map();
	Map(int, int);
	void zeroer();
	void assign(Map);
	void getsize(int&, int&);
	void show();
	bool find(char, int&, int&);
};
class Universe : public Map
{
	char symbol;
public:      
	Universe();
	void test();
	void add(Map);
	void BirthAndDeath(Map);
	void NewBirthAndDeath(Map);
	void buttons(Map, char sym);
	bool check(Map, int, int, int, int oldx = 0, int oldy = 0, char sym = ' ');
	void newcheck(Map, int&, int&, int&, int oldx = 0, int oldy = 0, char sym = ' ');
};


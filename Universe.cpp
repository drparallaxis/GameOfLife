#include "Universe.h"

Map::Map() {}
Map::Map(int s1, int s2)
{
	size1 = s1;
	size2 = s2;
	arr = new char*[size1];
	for (int i = 0; i < size1; i++)
		arr[i] = new char[size2];
	zeroer();
	arr[0][0] = 'A';
}
void Map::zeroer()
{
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++)
			arr[i][j] = ' ';
}
void Map::show()
{
	cout << "\n  .";
	for (int k = 0; k < size2+1; k++)
		cout << ".";
	cout << "\n";
	for (int i = 0; i < size1; i++)
	{
		cout << "  .";
		for (int j = 0; j < size2; j++)
			cout << arr[i][j];
		cout << ".\n";
	}
	cout << "  .";
	for (int k = 0; k < size2; k++)
		cout << ".";
	cout << ".\n";
}
void Map::assign(Map object)
{
	for (int i = 0; i < size1; i++)
		for (int j = 0; j < size2; j++)
			arr[i][j] = object.arr[i][j];
}
void Map::getsize(int& s1, int& s2)
{
	s1 = size1;
	s2 = size2;
}
bool Map::find(char sym, int& number1, int& number2)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{ 
			if (arr[i][j] == sym)
			{
				number1 = i;
				number2 = j;
				return true;
			}
		}
	}
}


Universe::Universe() { symbol = '0'; }
void Universe::add(Map object)
{
	int x = 0, y = 0;
	cout << "  Please, input coordinates: \n  x: ";
	cin >> y;
	y = y - 1;
	cout << "  y: ";
	cin >> x;
	x = x - 1;
	object.arr[x][y] = symbol;
}
void Universe::buttons(Map object, char sym)
{
	int x = 0, y = 0, buffer1 = 0, buffer2 = 0, status = 0;
	if (object.find('A', x, y) == true)
	{
		if (sym == 'a')
		{
			buffer1 = x, buffer2 = y - 1;
			newcheck(object, buffer1, buffer2, status, x, y, 'A');
			if (status == 0)
			{
				object.arr[x][y] = ' ';
				object.arr[x][y - 1] = 'A';
			}
			status = 0;
		}
		if (sym == 'd')
		{
			buffer1 = x, buffer2 = y + 1;
			newcheck(object, buffer1, buffer2, status, x, y, 'A');
			if (status == 0)
			{
				object.arr[x][y] = ' ';
				object.arr[x][y + 1] = 'A';
			}
			status = 0;
		}
		if (sym == 'w')
		{
			buffer1 = x - 1, buffer2 = y;
			newcheck(object, buffer1, buffer2, status, x, y, 'A');
			if (status == 0)
			{
				object.arr[x][y] = ' ';
				object.arr[x - 1][y] = 'A';
			}
			status = 0;
		}
		if (sym == 's')
		{
			buffer1 = x + 1, buffer2 = y;
			newcheck(object, buffer1, buffer2, status, x, y, 'A');
			if (status == 0)
			{
				object.arr[x][y] = ' ';
				object.arr[x + 1][y] = 'A';
			}
			status = 0;
		}
		if (sym == 'q')
		{
			buffer1 = x - 1, buffer2 = y - 1;
			newcheck(object, buffer1, buffer2, status, x, y, 'A');
			if (status == 0)
			{
				object.arr[x][y] = ' ';
				object.arr[x - 1][y-1] = 'A';
			}
		}
		if (sym == 'e')
		{
			buffer1 = x - 1, buffer2 = y + 1;
			newcheck(object, buffer1, buffer2, status, x, y, 'A');
			if (status == 0)
			{
				object.arr[x][y] = ' ';
				object.arr[x - 1][y + 1] = 'A';
			}
		}
	}
	if (sym == 'z')
		add(object);
}

void Universe::newcheck(Map object, int& x, int& y, int& status, int oldx, int oldy, char sym)
{
	int s1 = 0, s2 = 0;
	int forCells = status;
	object.getsize(s1, s2);
	if (x >= s1 || x < 0 || y >= s2 || y < 0)
	{
		status = 2;
		if (oldx == 0 && oldy == 0 && x == oldx - 1 && y == oldy - 1)
		{
			x = s1 - 1;
			y = s2 - 1;
		}
		if (oldx == s1 - 1 && oldy == s2 - 1 && x == oldx + 1 && y == oldy + 1)
		{
			x = 0;
			y = 0;
		}
		if (oldx == 0 && oldy == s2 - 1 && x == oldx - 1 && y == oldy + 1)
		{
			x = s1 - 1;
			y = 0;
		}
		if (oldx == s1 - 1 && oldy == 0 && x == oldx + 1 && y == oldy - 1)
		{
			x = 0;
			y = s2 - 1;
		}

		if (x == oldx - 1 && y == oldy)
		{
			x = s1 - 1;
		}
		if (x == oldx + 1 && y == oldy)
		{
			x = 0;
		}
		if (x == oldx && y == oldy - 1)
		{
			y = s2 - 1;
		}
		if (x == oldx && y == oldy + 1)
		{
			y = 0;
		}
		if(forCells != 1)
		{ 
			object.arr[oldx][oldy] = ' ';
			object.arr[x][y] = sym;
		}
	}
}

void Universe::BirthAndDeath(Map object)
{
	int s1 = 0, s2 = 0;
	object.getsize(s1, s2);
	Map ChangeObject(s1, s2);
	ChangeObject.zeroer();
	ChangeObject.assign(object);
	int counter = 0;

	for (int i = 0; i < s1; i++)
		for (int j = 0; j < s2; j++)
			if (ChangeObject.arr[i][j] == ' ' || ChangeObject.arr[i][j] == symbol)
			{
				if (check(ChangeObject, i, j + 1, 1) == true)
					if (ChangeObject.arr[i][j + 1] == symbol)
						++counter;
				if (check(ChangeObject, i, j - 1, 1) == true)
					if (ChangeObject.arr[i][j - 1] == symbol)
						++counter;
				if (check(ChangeObject, i - 1, j, 1) == true)
					if (ChangeObject.arr[i - 1][j] == symbol)
						++counter;
				if (check(ChangeObject, i + 1, j, 1) == true)
					if (ChangeObject.arr[i + 1][j] == symbol)
						++counter;
				if (check(ChangeObject, i - 1, j - 1, 1) == true)
					if (ChangeObject.arr[i - 1][j - 1] == symbol)
						++counter;
				if (check(ChangeObject, i + 1, j + 1, 1) == true)
					if (ChangeObject.arr[i + 1][j + 1] == symbol)
						++counter;
				if (check(ChangeObject, i - 1, j + 1, 1) == true)
					if (ChangeObject.arr[i - 1][j + 1] == symbol)
						++counter;
				if (check(ChangeObject, i + 1, j - 1, 1) == true)
					if (ChangeObject.arr[i + 1][j - 1] == symbol)
						++counter;

				if (counter == 3 && object.arr[i][j] == ' ')
					object.arr[i][j] = symbol;
				if ((counter < 2 || counter > 3) && object.arr[i][j] == symbol)
					object.arr[i][j] = ' ';
				counter = 0;
			}
}

void Universe::NewBirthAndDeath(Map object)
{
	int s1 = 0, s2 = 0, buffer1 = 0, buffer2 = 0, status = 1;
	object.getsize(s1, s2);
	Map ChangeObject(s1, s2);
	ChangeObject.zeroer();
	ChangeObject.assign(object);
	int counter = 0;

	for (int i = 0; i < s1; i++)
		for (int j = 0; j < s2; j++)
			if (ChangeObject.arr[i][j] == ' ' || ChangeObject.arr[i][j] == symbol)
			{
				if (check(ChangeObject, i, j + 1, 1) == false)
				{
					buffer1 = i, buffer2 = j + 1;
					newcheck(ChangeObject, buffer1, buffer2, status, i, j);
					status = 1;
					if (ChangeObject.arr[buffer1][buffer2] == symbol)
						++counter;
				}
				else if (check(ChangeObject, i, j + 1, 1) == true)
				{
					if (ChangeObject.arr[i][j + 1] == symbol)
						++counter;
				}
				if (check(ChangeObject, i, j - 1, 1) == false)
				{
					buffer1 = i, buffer2 = j - 1;
					newcheck(ChangeObject, buffer1, buffer2, status, i, j);
					status = 1;
					if (ChangeObject.arr[buffer1][buffer2] == symbol)
						++counter;
				}
				else if (check(ChangeObject, i, j - 1, 1) == true)
				{
					if (ChangeObject.arr[i][j - 1] == symbol)
						++counter;
				}
				if (check(ChangeObject, i - 1, j, 1) == false)
				{
					buffer1 = i - 1, buffer2 = j;
					newcheck(ChangeObject, buffer1, buffer2, status, i, j);
					status = 1;
					if (ChangeObject.arr[buffer1][buffer2] == symbol)
						++counter;
				}
				else if (check(ChangeObject, i - 1, j, 1) == true)
				{
					if (ChangeObject.arr[i - 1][j] == symbol)
						++counter;
				}
				if (check(ChangeObject, i + 1, j, 1) == false)
				{
					buffer1 = i + 1, buffer2 = j;
					newcheck(ChangeObject, buffer1, buffer2, status, i, j);
					status = 1;
					if (ChangeObject.arr[buffer1][buffer2] == symbol)
						++counter;
				}
				else if (check(ChangeObject, i + 1, j, 1) == true)
				{
					if (ChangeObject.arr[i + 1][j] == symbol)
						++counter;
				}
				/*if (check(ChangeObject, i - 1, j - 1, 1) == false)
				{
					buffer1 = i - 1, buffer2 = j - 1;
					newcheck(ChangeObject, buffer1, buffer2, status, i, j);
					status = 1;
					if (ChangeObject.arr[buffer1][buffer2] == symbol)
						++counter;
				}*/
				else if (check(ChangeObject, i - 1, j - 1, 1) == true)
				{
					if (ChangeObject.arr[i - 1][j - 1] == symbol)
						++counter;
				}
				/*if (check(ChangeObject, i + 1, j + 1, 1) == false)
				{
					buffer1 = i + 1, buffer2 = j + 1;
					newcheck(ChangeObject, buffer1, buffer2, status, i, j);
					status = 1;
					if (ChangeObject.arr[buffer1][buffer2] == symbol)
						++counter;
				}*/
				else if (check(ChangeObject, i + 1, j + 1, 1) == true)
				{
					if (ChangeObject.arr[i + 1][j + 1] == symbol)
						++counter;
				}
				/*if (check(ChangeObject, i - 1, j + 1, 1) == false)
				{
					buffer1 = i - 1, buffer2 = j + 1;
					newcheck(ChangeObject, buffer1, buffer2, status, i, j);
					status = 1;
					if (ChangeObject.arr[buffer1][buffer2] == symbol)
						++counter;
				}*/
				else if (check(ChangeObject, i - 1, j + 1, 1) == true)
				{
					if (ChangeObject.arr[i - 1][j + 1] == symbol)
						++counter;
				}
				/*if (check(ChangeObject, i + 1, j - 1, 1) == false)
				{
					buffer1 = i + 1, buffer2 = j - 1;
					newcheck(ChangeObject, buffer1, buffer2, status, i, j);
					status = 1;
					if (ChangeObject.arr[buffer1][buffer2] == symbol)
						++counter;
				}*/
				if (check(ChangeObject, i + 1, j - 1, 1) == true)
				{
					if (ChangeObject.arr[i + 1][j - 1] == symbol)
						++counter;
				}

				if (counter == 3 && object.arr[i][j] == ' ')
					object.arr[i][j] = symbol;
				if ((counter < 2 || counter > 3) && object.arr[i][j] == symbol)
					object.arr[i][j] = ' ';
				counter = 0;
			}
}

bool Universe::check(Map object, int x, int y, int status, int oldx, int oldy, char sym)
{
	int s1 = 0, s2 = 0;
	object.getsize(s1, s2);
	if ((x < 0 || y < 0 || x >= s1 || y >= s2) && status == 1)
		return false;
	else
	{
		if (status == 1)
			return true;
	}
}




void Universe::test()
{
	int a = 24, b = 114;
	//int a = 10, b = 20;
	Map A(a, b);
	char button = ' ';
	srand(time(NULL));
	int x = 0, y = 0;
	
	for (int i = 0; i < 1300; i++)
	{
		x = rand() % a; 
		y = rand() % b;
		if(A.arr[x][y] == ' ')
			A.arr[x][y] = '0';
	}
	
	while (1)
	{
		A.show();
		BirthAndDeath(A);
		button = (char)_getch();
		buttons(A, button);
		system("cls");
	}
}



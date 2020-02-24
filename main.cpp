#include<iostream>
#include<deque>
#include<utility>
#include<cstdlib>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include"snake.h"

int speedform[11] = { 10000,500,400,300,250,200,150,100,75,50,40 };

void form_map(Snake s, char situ)
{
	system("cls");
	int map[WIDTH][HEIGHT] = { 0 };
	for (deque<pair<int, int>>::iterator i = s.body.begin(); i != s.body.end(); i++)
	{
		map[(*i).first - 1][(*i).second - 1] = 1;
	}
	map[s.food.first - 1][s.food.second - 1] = 2;
	cout << "©°";
	for (int i = 0; i < WIDTH; i++)cout << "©¤©¤";
	cout << "©Ð©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´" << endl;
	for (int i = 0; i < HEIGHT; i++)
	{
		cout << "©¦";
		for (int j = 0; j < WIDTH; j++)
		{
			if (map[j][i] == 0)cout << "  ";
			if (map[j][i] == 1)cout << "¡ö";
			if (map[j][i] == 2)cout << "¡õ";
		}
		if (i == 0)cout << "©¦    SNAKE   ©¦" << endl;
		else if (i == 1)cout << "©¦    V1.01   ©¦" << endl;
		else if (i == 2 || i == 6 || i == HEIGHT - 3)cout << "©À©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©È" << endl;
		else if (i == 3)cout << "©¦ SCORE:" << setw(5) << s.body.size() - 3 << "©¦" << endl;
		else if (i == 4)cout << "©¦ SPEED:" << setw(5) << s.speed << "©¦" << endl;
		else if (i == 5 && situ == 0)cout << "©¦ DIRECTION:" << s.direction << "©¦" << endl;
		else if (i == 5 && situ == 1)cout << "©¦  GAME OVER " << "©¦" << endl;
		else if (i == HEIGHT - 2)cout << "©¦   AUTHOR:  ©¦" << endl;
		else if (i == HEIGHT - 1)cout << "©¦   YURIHOU  ©¦"<<endl;
		else cout << "©¦            ©¦" << endl;
	}
	cout << "©¸";
	for (int i = 0; i < WIDTH; i++)cout << "©¤©¤";
	cout << "©Ø©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼" << endl;
}

int main()
{
	Snake snake;
	char a = 0;
	DWORD timer = ::GetTickCount64();
	timer = ::GetTickCount64();
	form_map(snake, 0);
	system("pause");

	while (1)
	{
		if (_kbhit())
		{
			a = _getch();
			snake.change_dir(a);
			form_map(snake, 0);
		}
		if (::GetTickCount64() - timer > speedform[snake.speed])
		{
			timer = ::GetTickCount64();
			if (a == 'x')break;
			else if (a == 'p')
			{
				a = snake.direction;
				system("pause");
			}
			else if (snake.walk_forward() == 1)
			{
				form_map(snake, 1);
				cout << "Game Over!" << endl;
				break;
			}
			form_map(snake, 0);
		}
	}
	system("pause");
	return 0;
}
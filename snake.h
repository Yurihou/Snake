#ifndef _SNAKE_H_
#define _SNAKE_H_

#include<deque>
#include<utility>

using namespace std;

#define WIDTH 21 //地图的宽度
#define HEIGHT 21 //地图的高度

class Snake
{
public:
	deque<pair<int, int>> body;
	pair<int, int> food;
	char direction;
	int speed;

	Snake();
	pair<int, int> head();
	pair<int, int> tail();

	void change_dir(char dir);
	int walk_forward();
};

char oppo_dir(char dir);

#endif
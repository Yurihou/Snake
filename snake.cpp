#include<ctime>
#include"snake.h"

using namespace std;

char oppo_dir(char dir)//防止直接转向相反方向导致游戏结束的判断函数
{
	if (dir == 'a')return 'd';
	if (dir == 'd')return 'a';
	if (dir == 'w')return 's';
	if (dir == 's')return 'w';
}

Snake::Snake()
{
	pair<int, int> first_1(9, 10), first_2(10, 10), first_3(11, 10);
	body.push_back(first_1);
	body.push_back(first_2);
	body.push_back(first_3);

	srand(time(0));
	food.first = rand() % WIDTH + 1;
	food.second = rand() % HEIGHT + 1;

	direction = 'a';
	speed = 1;
}

pair<int, int> Snake::head()
{
	return *body.begin();
}

pair<int, int> Snake::tail()
{
	return *(body.end() - 1);
}

void Snake::change_dir(char dir)
{
	if ((dir == 'w' || dir == 'a' || dir == 's' || dir == 'd') && dir != oppo_dir(direction))direction = dir;//判断输入代码一致且不向相反方向行驶
}

int Snake::walk_forward()
{
	pair<int, int>movement = head();//提取头部

	if(speed<=10)speed = (body.size()-3) / 8 + 1;

	if (direction == 'w')movement.second -= 1;
	else if (direction == 's')movement.second += 1;
	else if (direction == 'a')movement.first -= 1;
	else if (direction == 'd')movement.first += 1;//判断移动方向
	if (movement.first<1 || movement.first>WIDTH || movement.second<1 || movement.second>HEIGHT)return 1;//判断蛇是否与边界相撞
	for (deque<pair<int, int>>::iterator i = body.begin(); i != body.end(); i++)//判断蛇是否和自己相撞
	{
		if (*i == movement)return 1;
	}
	body.push_front(movement);//头部增加一格

	if (movement != food)body.pop_back();//判断头部是否和食物重合，如果不是，尾部消失
	else//否则尾部不消失（即蛇增长）且更新食物位置
	{
		while (1)
		{
			char on_snake = 0;
			srand(time(0));
			food.first = rand() % WIDTH + 1;
			food.second = rand() % WIDTH + 1;
			for (deque<pair<int, int>>::iterator i = body.begin(); i != body.end(); i++)//判断蛇是否和自己相撞
			{
				if ((*i) == food)
				{
					on_snake = 1;
					break;
				}
			}
			if (on_snake == 0)break;
		}
	}
	return 0;
}

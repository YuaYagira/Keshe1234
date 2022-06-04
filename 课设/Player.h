#pragma once
#include "common.h"
class Player
{
public:
	Player(void) {};
	~Player(void) {};
	void loadData();//读取角色信息文件
	void changePlayer();//维护角色信息
	void findPlayer();//查询角色信息
	vector<int> level;
	vector<int> HP;
	vector<int> MP;
	vector<int> ATK;
	vector<string> ID;
};
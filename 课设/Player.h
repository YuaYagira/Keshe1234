#pragma once
#include "common.h"
class Player
{
public:
	Player(void) {};
	~Player(void) {};
	void loadData();//��ȡ��ɫ��Ϣ�ļ�
	void changePlayer();//ά����ɫ��Ϣ
	void findPlayer();//��ѯ��ɫ��Ϣ
	vector<int> level;
	vector<int> HP;
	vector<int> MP;
	vector<int> ATK;
	vector<string> ID;
};
#pragma once
#include"common.h"
#include"DoUser.h"
#include"Player.h"
#define FILENAME "player.txt"
#define FILENAME2 "users.txt"
class playerManager
{
public:
	playerManager(void) { showWindows0(); };
	~playerManager(void) {};
	void welcome();//��¼����
	void adminWindows();//����Ա����
	void userWindows();//�û�����
	void showWindows0();//��ʾ����1
	void showWindows1();
	void showWindows2();
	void Login();//��¼����
	bool Register();//ע�����
	int checkPassword(string name);
	string name;
	string password;
	DoUser visitor;
	Player player;

};
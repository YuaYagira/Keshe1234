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
	void welcome();//登录界面
	void adminWindows();//管理员界面
	void userWindows();//用户界面
	void showWindows0();//显示函数1
	void showWindows1();
	void showWindows2();
	void Login();//登录程序
	bool Register();//注册程序
	int checkPassword(string name);
	string name;
	string password;
	DoUser visitor;
	Player player;

};
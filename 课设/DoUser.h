#pragma once
#include "common.h"
class DoUser
{
public:
	DoUser() 
	{ 
		void loadData();
	}
	 ~DoUser() {}
	 vector <string>UserName;
	 vector <string>UserPassword;
	 vector <int> UserGrade;
	 void loadData();//加载用户数据	 
	 bool checkUser();//检查用户名和密码
	 bool checkRegisterName(string oName);//检查注册用户名是否重复
	 void showUser();//显示用户信息
	 void changeUser();//修改用户信息
	 string username;
	 string userpassword;
	 int usergrade;
	 
};

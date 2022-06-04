#include"DoUser.h"
#include "common.h"
#define FILENAME "player.txt"
#define FILENAME2 "users.txt"
void DoUser::loadData()
{
	ifstream userFile("users.txt");
		if (!userFile)
		{
			cout << "打开用户信息文件失败！"<<endl;
			exit(1);
		}
		else
			while (userFile.peek() != EOF)
			{
				int inGrade;
				string  inName, inPassword;
				userFile>>  inName >> inPassword>> inGrade;
				UserName.push_back(inName);
				UserPassword.push_back(inPassword);
				UserGrade.push_back(inGrade);
				userFile.clear();
			}
			userFile.close();
}
void DoUser::showUser()
{
    cout << "您的用户名是：" << username<< endl;
    cout << "您的密码是：" << userpassword << endl;
}
void DoUser::changeUser()
{

}
bool DoUser::checkUser()
{
	string name, password;
	cout << "输入您的用户名:" << endl;
	cin >> name;
	cout << "输入您的密码:" << endl;
	cin >> password;	
	for (unsigned int i = 0;i < UserName.size(); i++)
	{
		if (name== UserName[i] && password== UserPassword[i])
		{
			username=name;
			userpassword = password;
			usergrade = UserGrade[i];
			cout << "欢迎登录！" << endl;
			return true;
		}

	}
	cout << "您输入的用户名或密码有误，请重新输入" << endl;
	return false;
}
bool DoUser::checkRegisterName(string oName)
{
	for (unsigned int i = 0;i < UserName.size(); i++)
	{
		if (UserName[i] == oName)
		{
			return false;
			break;
		}
		else
		{
			return true;
		}
	}
}
#include"DoUser.h"
#include "common.h"
#define FILENAME "player.txt"
#define FILENAME2 "users.txt"
void DoUser::loadData()
{
	ifstream userFile("users.txt");
		if (!userFile)
		{
			cout << "���û���Ϣ�ļ�ʧ�ܣ�"<<endl;
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
    cout << "�����û����ǣ�" << username<< endl;
    cout << "���������ǣ�" << userpassword << endl;
}
void DoUser::changeUser()
{

}
bool DoUser::checkUser()
{
	string name, password;
	cout << "���������û���:" << endl;
	cin >> name;
	cout << "������������:" << endl;
	cin >> password;	
	for (unsigned int i = 0;i < UserName.size(); i++)
	{
		if (name== UserName[i] && password== UserPassword[i])
		{
			username=name;
			userpassword = password;
			usergrade = UserGrade[i];
			cout << "��ӭ��¼��" << endl;
			return true;
		}

	}
	cout << "��������û�����������������������" << endl;
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
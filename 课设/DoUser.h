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
	 void loadData();//�����û�����	 
	 bool checkUser();//����û���������
	 bool checkRegisterName(string oName);//���ע���û����Ƿ��ظ�
	 void showUser();//��ʾ�û���Ϣ
	 void changeUser();//�޸��û���Ϣ
	 string username;
	 string userpassword;
	 int usergrade;
	 
};

#include"PlayerManager.h"
#include"DoUser.h"
#define FILENAME "player.txt"
#define FILENAME2 "users.txt"
void playerManager::showWindows0()
{
    while (1)
    {
        int choose0;
        welcome();
        cin >> choose0;
        switch (choose0)
        {
          case 1:// ��¼
          {
            Login();
            break;
          }
          case 2://ע��
          {
            while (!Register())
            {
            }           
            system("cls");
            continue;

          }
         case 0://�˳�
          {
            cout << "��ӭ�´�ʹ�ã�" << endl;
            return;
          }
        }
    
    }
}
void playerManager::showWindows1()
{
    int choose1;
    adminWindows();//չʾ����Ա����
    cin >> choose1;
    switch (choose1)
    {
      case'1'://�鿴������Ϣ
     {
          visitor.showUser();
          break;
     }
      case'2'://�޸ĸ�����Ϣ
     {
          break;
     }
     case'3'://��ѯ��ɫ��Ϣ
     {
         break;
     }
     case'4'://�޸Ľ�ɫ��Ϣ
     {
         break;
     }
     case'0'://�˳�ϵͳ
     {
         cout << "��ӭ�´�ʹ�ã�" << endl;
         return;
     }
    }

    

}
void playerManager::showWindows2()
{
    int choose2;
    userWindows();//չʾ�û�����  
    cin >> choose2;
    switch (choose2)
    {
      case'1'://�鿴������Ϣ
      {
          visitor.showUser();
          break;
      }
      case'2'://�޸ĸ�����Ϣ
      {
          break;
      }
      case'3'://��ѯ��ɫ��Ϣ
      {
          break;
      }
      case'0'://�˳�ϵͳ
      {
          cout << "��ӭ�´�ʹ�ã�" << endl;
          return;
      }
    }
}
void playerManager::welcome()
{
    cout << "\t\t***************************************************" << endl;
    cout << "\t\t*---------����ӭʹ��xx��Ϸ��ɫ����ϵͳ��----------*" << endl;
    cout << "\t\t*           ���Ʋ�����Ϸ���ܾ�������Ϸ            *" << endl;
    cout << "\t\t*           ע�����ұ����������ϵ���ƭ            *" << endl;
    cout << "\t\t*           �ʶ���Ϸ���ԣ�������Ϸ����            *" << endl;
    cout << "\t\t*           ������ʱ�䣬���ܽ�������            *" << endl;
    cout << "\t\t*-------------------------------------------------*" << endl;
    cout << "\t\t*                 ��¼�ʺ��밴1                   *" << endl;
    cout << "\t\t*                 ע���˺��밴2                   *" << endl;
    cout << "\t\t*----------------- �˳�ϵͳ��0 -------------------*" << endl;
    cout << "\t\t***************************************************" << endl;
}
void playerManager::Login()//��¼����
{
    while (!visitor.checkUser())//����DoUser��ĺ���������û���������
    {                   
    }
    if (visitor.usergrade == 0)
    {
        showWindows1();//ʹ�ù���Ա����
    }
    else
    {
        showWindows2();//ʹ���û�����
    }
}
bool playerManager::Register()//ע�����
{
    while (1)
    {

        ofstream out("users.txt", ios::app);
        if (!out)
        {
            cout << "�����û���Ϣ�ļ�" << endl;
        }
        ofstream pout("player.txt", ios::app);
        if (!pout)
        {
            cout << "�����ɫ��Ϣ�ļ�" << endl;
        }
        string oID, oName, oPassword;
        int ograde, olevel = 1, oHP = 200, oATK = 10, oMP = 200;
        cout << "��������Ҫע����û����ͣ�" << endl;
        cin >> ograde;
        cout << "��������Ҫע����û�����" << endl;
        cin >> oName;
        if (visitor.checkRegisterName(oName))
        {
            cout << "��������û������ظ�������������"<<endl;
            return false;
            system("cls");
        }
        
            cout << "�������������룺" << endl;
            cin >> oPassword;
            cout << "��������ϲ������Ϸ�ǳƣ�" << endl;
            cin >> oID;
            out << "\n" << " " << oName << " " << oPassword << " " << ograde;
            pout << "\n" << oID << " " << olevel << " " << oHP << " " << oMP << " " << oATK;
            visitor.UserName.push_back(oName);
            visitor.UserPassword.push_back(oPassword);
            visitor.UserGrade.push_back(ograde);
            player.ID.push_back(oID);
            player.level.push_back(olevel);
            player.HP.push_back(oHP);
            player.MP.push_back(oMP);
            player.ATK.push_back(oATK);
            out.close();
            break;

    }


}

void playerManager::adminWindows()
{
    cout << "\t\t-------------------------------" << endl;
    cout << "\t\t+++++  �����˻�Ϊ����Ա   +++++" << endl;
    cout << "\t\t+++++  �鿴������Ϣ�밴1  +++++" << endl;
    cout << "\t\t+++++  �޸ĸ�����Ϣ�밴2  +++++" << endl;
    cout << "\t\t+++++  ��ѯ��ɫ��Ϣ�밴3  +++++" << endl;
    cout << "\t\t+++++  ά����ɫ��Ϣ�밴4  +++++" << endl;
    cout << "\t\t+++++  �˳�����ϵͳ�밴0  +++++" << endl;
    cout << "\t\t-------------------------------" << endl;
}
void  playerManager::userWindows()
{
    cout << "\t\t-------------------------------" << endl;
    cout << "\t\t+++++  �����˻�Ϊ��ͨ�û� +++++" << endl;
    cout << "\t\t+++++  �鿴������Ϣ�밴1  +++++" << endl;
    cout << "\t\t+++++  �޸ĸ�����Ϣ�밴2  +++++" << endl;
    cout << "\t\t+++++  ��ѯ��ɫ��Ϣ�밴3  +++++" << endl;
    cout << "\t\t+++++  �˳�����ϵͳ�밴0  +++++" << endl;
    cout << "\t\t-------------------------------" << endl;
}
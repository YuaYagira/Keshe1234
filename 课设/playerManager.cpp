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
          case 1:// 登录
          {
            Login();
            break;
          }
          case 2://注册
          {
            while (!Register())
            {
            }           
            system("cls");
            continue;

          }
         case 0://退出
          {
            cout << "欢迎下次使用！" << endl;
            return;
          }
        }
    
    }
}
void playerManager::showWindows1()
{
    int choose1;
    adminWindows();//展示管理员界面
    cin >> choose1;
    switch (choose1)
    {
      case'1'://查看个人信息
     {
          visitor.showUser();
          break;
     }
      case'2'://修改个人信息
     {
          break;
     }
     case'3'://查询角色信息
     {
         break;
     }
     case'4'://修改角色信息
     {
         break;
     }
     case'0'://退出系统
     {
         cout << "欢迎下次使用！" << endl;
         return;
     }
    }

    

}
void playerManager::showWindows2()
{
    int choose2;
    userWindows();//展示用户界面  
    cin >> choose2;
    switch (choose2)
    {
      case'1'://查看个人信息
      {
          visitor.showUser();
          break;
      }
      case'2'://修改个人信息
      {
          break;
      }
      case'3'://查询角色信息
      {
          break;
      }
      case'0'://退出系统
      {
          cout << "欢迎下次使用！" << endl;
          return;
      }
    }
}
void playerManager::welcome()
{
    cout << "\t\t***************************************************" << endl;
    cout << "\t\t*---------【欢迎使用xx游戏角色管理系统】----------*" << endl;
    cout << "\t\t*           抵制不良游戏，拒绝盗版游戏            *" << endl;
    cout << "\t\t*           注意自我保护，谨防上当受骗            *" << endl;
    cout << "\t\t*           适度游戏益脑，沉迷游戏伤身            *" << endl;
    cout << "\t\t*           合理安排时间，享受健康生活            *" << endl;
    cout << "\t\t*-------------------------------------------------*" << endl;
    cout << "\t\t*                 登录帐号请按1                   *" << endl;
    cout << "\t\t*                 注册账号请按2                   *" << endl;
    cout << "\t\t*----------------- 退出系统按0 -------------------*" << endl;
    cout << "\t\t***************************************************" << endl;
}
void playerManager::Login()//登录程序
{
    while (!visitor.checkUser())//调用DoUser里的函数来检查用户名和密码
    {                   
    }
    if (visitor.usergrade == 0)
    {
        showWindows1();//使用管理员界面
    }
    else
    {
        showWindows2();//使用用户界面
    }
}
bool playerManager::Register()//注册程序
{
    while (1)
    {

        ofstream out("users.txt", ios::app);
        if (!out)
        {
            cout << "请检查用户信息文件" << endl;
        }
        ofstream pout("player.txt", ios::app);
        if (!pout)
        {
            cout << "请检查角色信息文件" << endl;
        }
        string oID, oName, oPassword;
        int ograde, olevel = 1, oHP = 200, oATK = 10, oMP = 200;
        cout << "请输入您要注册的用户类型：" << endl;
        cin >> ograde;
        cout << "请输入您要注册的用户名：" << endl;
        cin >> oName;
        if (visitor.checkRegisterName(oName))
        {
            cout << "您输入的用户名已重复，请重新输入"<<endl;
            return false;
            system("cls");
        }
        
            cout << "请设置您的密码：" << endl;
            cin >> oPassword;
            cout << "请输入您喜欢的游戏昵称：" << endl;
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
    cout << "\t\t+++++  您的账户为管理员   +++++" << endl;
    cout << "\t\t+++++  查看个人信息请按1  +++++" << endl;
    cout << "\t\t+++++  修改个人信息请按2  +++++" << endl;
    cout << "\t\t+++++  查询角色信息请按3  +++++" << endl;
    cout << "\t\t+++++  维护角色信息请按4  +++++" << endl;
    cout << "\t\t+++++  退出管理系统请按0  +++++" << endl;
    cout << "\t\t-------------------------------" << endl;
}
void  playerManager::userWindows()
{
    cout << "\t\t-------------------------------" << endl;
    cout << "\t\t+++++  您的账户为普通用户 +++++" << endl;
    cout << "\t\t+++++  查看个人信息请按1  +++++" << endl;
    cout << "\t\t+++++  修改个人信息请按2  +++++" << endl;
    cout << "\t\t+++++  查询角色信息请按3  +++++" << endl;
    cout << "\t\t+++++  退出管理系统请按0  +++++" << endl;
    cout << "\t\t-------------------------------" << endl;
}
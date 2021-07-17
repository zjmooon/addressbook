#include<iostream>
#include<unistd.h>
#include<string>

#define MAX 1000
using namespace std;

#define MAX 1000

//定义两个结构体
struct person 
{
    string name;
    int sex;
    int age;
    string phone;
    string addr; 
};

struct addressbooks
{
    struct person personArray[MAX];
    int size;
};
//进入系统先显示菜单
void showMenu()
{
    cout << "*********************************************" << endl;
    cout <<" \t\t\t菜单" << endl;
    cout << "\t\t1.添加联系人" << endl;
    cout << "\t\t2.显示联系人" << endl;
    cout << "\t\t3.删除联系人" << endl;
    cout << "\t\t4.查找联系人" << endl;
    cout << "\t\t5.修改联系人" << endl;
    cout << "\t\t6.清空联系人" << endl;
    cout << "\t\t0.退出" << endl;
    cout << "请选择功能" << endl;
    cout << "*********************************************" << endl;    
};


//添加联系人
void addPerson(struct addressbooks  * abs)
{
    if (abs->size == MAX)
    {
        cout << "  通讯录已满，无法添加"<< endl;
        return;
    }
    else
    {
        cout << "请输入姓名" << endl;
        cin >> abs->personArray[abs->size].name;  //"->"用在地址abs，"."用于值
      
        cout << "请输入性别" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;     //循环外输入，循环内判断
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->size].sex =  sex;
                break;
            }
            else
            {
                cout << "参数错误！请输入1或2" << endl;
            }
                

        }
        
        cout << "请输入年龄" << endl;
        cin >> abs->personArray[abs->size].age;

        cout << "请输入电话" << endl;
        cin >> abs->personArray[abs->size].phone;

        cout << "请输入住址" << endl;
        cin >> abs->personArray[abs->size].addr;

        abs->size++;         //更新通讯录人数
        cout << "添加成功" << endl;
        //system("pause");
        //system("clear");
    }
};

// 显示所有联系人
void displayPerson(struct addressbooks * abs)
{
    //判断通讯录中人数是否为0
    if (abs->size == 0)
    {
        cout << "没有联系人" << endl;
    }
    else
    {
        for (int i=0; i<abs->size; i++)
        {
            cout << abs->personArray[i].name<< "\t";
            cout << (abs->personArray[i].sex == 1 ? "男" : "女" ) << "\t";
            cout << abs->personArray[i].age<< "\t";
            cout << abs->personArray[i].phone<< "\t";
            cout << abs->personArray[i].addr << endl;
        }
        
    }
    //system("pause");
    //system("clear");
};
int isExited(struct addressbooks * abs, string a_name)
{
    for (int i=0; i<abs->size; i++)
    {
        if (abs->personArray[i].name == a_name)
        {
            return i;
        }
   
    }
    return -1;   //最开始放在循环内部导致错误：IsExited恒返回0
};
void deletePerson(struct addressbooks * abs)
{
    string d_name;
    cout << "请输入想删除的联系人："<< endl;
    cin >> d_name;
    int ret = isExited(abs, d_name); 
    if (ret == -1)
    {
        cout << "未找到此人" << endl;
    }
    else
    {
        abs->size --;
        cout << "正在删除：" << abs->personArray[ret].name << endl;
        for (int i=ret; i<abs->size; i++)
        {
            abs->personArray[i] = abs->personArray[i+1];
        }
        cout << "删除完成" << endl;

    }
};
void searchPerson(addressbooks * abs)
{
    string s_name;
    cout << "输入查找的联系人" << endl;
    cin >> s_name;
    int ret = isExited(abs, s_name);
    if (ret == -1)
    {
        cout <<"未找到此人"<< endl;
    }
    else
    {
        cout << "查找结果如下："<< endl;
        cout << abs->personArray[ret].name<< "\t";
        cout << (abs->personArray[ret].sex == 1 ? "男" : "女" ) << "\t";
        cout << abs->personArray[ret].age<< "\t";
        cout << abs->personArray[ret].phone<< "\t";
        cout << abs->personArray[ret].addr << endl;
    }
};
void modifyPerson(addressbooks * abs)
{
     string m_name;
    cout << "输入要修改的联系人" << endl;
    cin >> m_name;
    int ret = isExited(abs, m_name);
    if (ret == -1)
    {
        cout <<"未找到此人"<< endl;
    }
    else
    {
        cout << "请输入姓名" << endl;
        cin >> abs->personArray[ret].name;  //"->"用在地址abs，"."用于值
      
        cout << "请输入性别" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;     //循环外输入，循环内判断
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].sex =  sex;
                break;
            }
            else
            {
                cout << "参数错误！请输入1或2" << endl;
            }
                

        }
        
        cout << "请输入年龄" << endl;
        cin >> abs->personArray[ret].age;

        cout << "请输入电话" << endl;
        cin >> abs->personArray[ret].phone;

        cout << "请输入住址" << endl;
        cin >> abs->personArray[ret].addr;

    }
}
void clearPerson(addressbooks * abs)
{
    abs->size = 0;
    cout << "已清空联系人" << endl;
}






int main()
{
  
    string a_name;
    int select = 10;
    addressbooks abs;   //创建通讯录结构体变量
    abs.size = 0;   //初始化通讯录中当前人员个数

    while(true)
    { 
        showMenu();    
        cin >> select;

        switch(select)
        {
            case 0:
                return 0;
                break;
            case 1:  //添加联系人
                addPerson(&abs);
                break;
            case 2:  //显示联系人
                displayPerson(&abs);
                break;
            case 3:  //删除联系人
                deletePerson(&abs);
                break;
            case 4:  //查找联系人
                searchPerson(&abs);
                break;
            case 5:  //修改联系人
                modifyPerson(&abs);
                break;
            case 6:  //清空联系人
                clearPerson(&abs);
                break;
            default:
                break;

        }
    }
    

    return 0;
}
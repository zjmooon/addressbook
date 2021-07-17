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
                cout << "请输入1或2" << endl;

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
void displayPerson(addressbooks * abs)
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
            cout << abs->personArray[i].addr <<endl;
        }
        
    }
    //system("pause");
    //system("clear");
}

int main()
{
  

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
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                break;

        }
    }
    

    return 0;
}
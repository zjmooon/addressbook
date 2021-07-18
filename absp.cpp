#include<iostream>
#include<string>
 #define MAX 1000

 using namespace std;

//创建通讯录结构体
struct person
{
    string name;
    int sex;
    int age;   //1:男；   2：女
    string phone;
    string address;
};

//创建通讯录结构体
struct addrbooks
{
    person addrperson[MAX];
    int size = 0; 
};

//显示菜单
void showMenu()
{    
    cout << "*****************" << endl;
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.删除联系人" << endl;
    cout << "4.查找联系人" << endl;
    cout << "5.修改联系人" << endl;
    cout << "6.清空联系人" << endl;
    cout << "0.退出" << endl;
    cout << "*****请选择功能" << endl;
    cout << "*****************" << endl;
};


//添加联系人
void addPerson(addrbooks * abs)
{
    int a_sex = 0;

    if (abs->size == MAX)
    {
        cout << "人数已满" << endl;
    }
    else
    {
        cout <<  "请输入联系人姓名：" << endl;
        cin >> abs->addrperson[abs->size].name;
        cout <<  "请输入联系人性别：" << endl;
        cout <<  "1:男" << endl;
        cout <<  "2:女" << endl;
        while (true)
        {
            cin >>  a_sex;
            if (a_sex == 1 || a_sex == 2)
            {
                abs->addrperson[abs->size].sex = a_sex;
                break;
            }
            cout << "参数错误！请输入1或2" << endl;
        }
   
    cout <<  "请输入联系人年龄：" << endl;
    cin >>  abs->addrperson[abs->size].age;

    cout <<  "请输入联系人电话：" << endl;
    cin >>  abs->addrperson[abs->size].phone;

    cout <<  "请输入联系人住址：" << endl;
    cin >>  abs->addrperson[abs->size].address;
    
    abs ->size++;
    }
    
};


//显示联系人
void showPerson(addrbooks * abs)
{
    if (abs->size == 0)
    {
        cout << "联系人为空" << endl;
    }
    else 
    {
        for (int i=0; i<abs->size; i++)
        {
            cout << "姓名：" << abs->addrperson[i].name << "\t";
            cout << "性别：" << (abs->addrperson[i].sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->addrperson[i].age << "\t";
            cout << "电话：" << abs->addrperson[i].phone << "\t";
            cout << "地址：" << abs->addrperson[i].address << endl;
        }

    }
};

//是否存在某联系人
int isExited(addrbooks * abs, string e_name)
{
    for (int i=0; i<abs->size; i++)
    {
        if (abs->addrperson[i].name == e_name)
        {
            return i;
        }
    }
    return -1;

};

//删除联系人
void deletePerson(addrbooks * abs)
{
    string name;
    int ret;

    cout << "请输入需删除的联系人" << endl;
    cin >> name;
    ret = isExited(abs, name);

    if (ret == -1)
    {
        cout << "没有此联系人" << endl;
    }
    else 
    {
        cout << "正在删除" << abs->addrperson[ret].name<< endl;
        for (ret; ret<abs->size; ret++)
        {
            abs->addrperson[ret] = abs->addrperson[ret + 1];
        }
        abs->size--;
        cout << "删除完成" << endl;
    }
}

 //查找联系人
void searchPerson( addrbooks * abs)
{
    string name;
    int ret;

    cout << "请输入需查找的联系人" << endl;
    cin >> name;
    ret = isExited(abs, name);

    if (ret == -1)
    {
        cout << "没有此联系人" << endl;
    }
    else 
    {
        cout << "正在查找" << abs->addrperson[ret].name<< endl;

        cout << "姓名：" << abs->addrperson[ret].name << "\t";
        cout << "性别：" << (abs->addrperson[ret].sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->addrperson[ret].age << "\t";
        cout << "电话：" << abs->addrperson[ret].phone << "\t";
        cout << "地址：" << abs->addrperson[ret].address << endl;

    }
};
//修改联系人
void modifyPerson(addrbooks * abs)
{
    string name;
    int ret;
    int m_sex = 0;

    cout << "请输入需修改的联系人" << endl;
    cin >> name;
    ret = isExited(abs, name);

    if (ret == -1)
    {
        cout << "没有此联系人" << endl;
    }
    else
    {
        cout << "修改姓名：" << endl;
        cin >> abs->addrperson[ret].name;

        cout << "修改性别：" << endl;
        cout << "1:男" << endl;
        cout << "2:女" << endl;
        while (true)
        {
            cin >>  m_sex;
            if (m_sex == 1 || m_sex == 2)
            {
                abs->addrperson[ret].sex = m_sex;
                break;
            }
            cout << "参数错误！请输入1或2" << endl;
        }
   
        cout <<  "修改年龄：" << endl;
        cin >>  abs->addrperson[ret].age;

        cout <<  "修改电话：" << endl;
        cin >>  abs->addrperson[ret].phone;

        cout <<  "修改住址：" << endl;
        cin >>  abs->addrperson[ret].address;
    }

};


//清空联系人
void clearPerson(addrbooks * abs)
{
    abs->size = 0;
    cout << "已清空联系人" << endl;
}



int main(void)
{
    addrbooks abs;    //数据类型为结构体的变量 abs
    int select = 0;     

    while (true)
    {
        showMenu();
        cin >> select;

        switch(select)
        {
            case 1:  //添加联系人
                addPerson(&abs);
                break;
            case 2:  //显示联系人
                showPerson(&abs);
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
            case 0:   //退出程序
                return 0;
                break;
            default:
                break;
        }
    }
    

    return 0;
}
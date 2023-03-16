#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student{
public:
    string name;
    int age{'0'},num{'0'};
    string gender;
    string address;
};
vector<Student> students; // 创建一个名为students的vector容器，其中存储的元素类型是Student类的对象
void addStudent() {
    Student student;
    cout << "请输入学生姓名：";
    cin >> student.name;
    cout << "请输入学生学号：";
    cin >> student.num;
    cout << "请输入学生年龄：";
    cin >> student.age;
    cout << "请输入学生性别：";
    cin >> student.gender;
    cout << "请输入学生地址：";
    cin >> student.address;
    students.push_back(student);
    cout << "添加成功！" << endl;
}
void deleteStudent(){
    bool flag = false;
    char ch;
    string name;
    cout << "请输入要删除的学生姓名：";
    cin >> name;
    for (int i = 0; i < students.size(); i++){
        if (students[i].name == name){
            flag = true;
            cout << "确认是否进行删除，请输入y/n.";
            cin >> ch;
            if (ch == 'y' || ch == 'Y'){
                students.erase(students.begin() + i);
                cout << "删除成功！" << endl;
            }
            else{
                cout << "放弃本次删除操作" << endl;
            }
        }
        if (!flag){
            cout << "未找到该学生！" << endl;
            break;
        }
    }
}
void modifyStudent(){
    int type;
    string name;
    system("cls");
    cout << "请输入要修改的学生姓名：";
    cin >> name;
    for (auto & student : students){  //遍历student容器中的元素  &表示引用传递，在遍历的过程中直接修改容器中元素的值
        if (student.name == name){
            cout << "-----------------------------------------------" << endl;
            cout << "   1.姓名                      2.学号          " << endl;
            cout << "   3.性别                      4.年龄          " << endl;
            cout << "   5.地址                      0.返回          " << endl;
            cout << "          请输入相应编号做相应修改。                " << endl;
            cout << "-----------------------------------------------" << endl;
            cin >> type;
            switch (type){
                case 1:{
                    cout << "请输入学生新的姓名：";
                    cin >> student.name;
                    cout << "修改成功！" << endl;
                    break;
                }
                case 2:{
                    cout << "请输入学生新的学号：";
                    cin >>student.num;
                    cout << "修改成功！" << endl;
                    break;
                }
                case 3:{
                    cout << "请输入学生新的性别：";
                    cin >> student.gender;
                    cout << "修改成功！" << endl;
                    break;
                }
                case 4:{
                    cout << "请输入学生新的年龄：";
                    cin >> student.age;
                    cout << "修改成功！" << endl;
                    break;
                }
                case 5:{
                    cout << "请输入学生新的地址：";
                    cin >> student.address;
                    cout << "修改成功！" << endl;
                    break;
                }
                case 0:{
                    return;
                }
                default:
                    cout << "输入错误" << endl;
            }
        }
        else cout << "未找到您所输入的学生。" << endl;
    }
}
void queryStudent(){
    string name;
    system("cls");
    cout << "请输入要查询的学生姓名：";
    cin >> name;
    for (auto & student : students){
        if (student.name == name){
            cout << "姓名：" << student.name << endl;
            cout << "年龄：" << student.age << endl;
            cout << "学号：" << student.num << endl;
            cout << "性别：" << student.gender << endl;
            cout << "地址：" << student.address << endl;
            break;
        } else cout << "未找到该学生！" << endl;
    }
}
int main(){
    while (true){
        cout << "-----------------------------------------------" << endl;
        cout << "             六年级二班学生信息系统               " << endl;
        cout << "    1.添加学生信息             2.删除学生信息      " << endl;
        cout << "    3.修改学生信息             4.查询学生信息       " << endl;
        cout << "                  0.退出系统                    " << endl;
        cout << "            请输入相应编号做相应修改。             " << endl;
        cout << "-----------------------------------------------" << endl;
        int n;
        cin >> n;
        switch (n){
            case 0:
                exit(0);
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                modifyStudent();
                break;
            case 4:
                queryStudent();
                break;
            default:
                cout << "输入错误！" << endl;
                break;
        }
    }
}
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
vector<Student> students; // ����һ����Ϊstudents��vector���������д洢��Ԫ��������Student��Ķ���
void addStudent() {
    Student student;
    cout << "������ѧ��������";
    cin >> student.name;
    cout << "������ѧ��ѧ�ţ�";
    cin >> student.num;
    cout << "������ѧ�����䣺";
    cin >> student.age;
    cout << "������ѧ���Ա�";
    cin >> student.gender;
    cout << "������ѧ����ַ��";
    cin >> student.address;
    students.push_back(student);
    cout << "��ӳɹ���" << endl;
}
void deleteStudent(){
    bool flag = false;
    char ch;
    string name;
    cout << "������Ҫɾ����ѧ��������";
    cin >> name;
    for (int i = 0; i < students.size(); i++){
        if (students[i].name == name){
            flag = true;
            cout << "ȷ���Ƿ����ɾ����������y/n.";
            cin >> ch;
            if (ch == 'y' || ch == 'Y'){
                students.erase(students.begin() + i);
                cout << "ɾ���ɹ���" << endl;
            }
            else{
                cout << "��������ɾ������" << endl;
            }
        }
        if (!flag){
            cout << "δ�ҵ���ѧ����" << endl;
            break;
        }
    }
}
void modifyStudent(){
    int type;
    string name;
    system("cls");
    cout << "������Ҫ�޸ĵ�ѧ��������";
    cin >> name;
    for (auto & student : students){  //����student�����е�Ԫ��  &��ʾ���ô��ݣ��ڱ����Ĺ�����ֱ���޸�������Ԫ�ص�ֵ
        if (student.name == name){
            cout << "-----------------------------------------------" << endl;
            cout << "   1.����                      2.ѧ��          " << endl;
            cout << "   3.�Ա�                      4.����          " << endl;
            cout << "   5.��ַ                      0.����          " << endl;
            cout << "          ��������Ӧ�������Ӧ�޸ġ�                " << endl;
            cout << "-----------------------------------------------" << endl;
            cin >> type;
            switch (type){
                case 1:{
                    cout << "������ѧ���µ�������";
                    cin >> student.name;
                    cout << "�޸ĳɹ���" << endl;
                    break;
                }
                case 2:{
                    cout << "������ѧ���µ�ѧ�ţ�";
                    cin >>student.num;
                    cout << "�޸ĳɹ���" << endl;
                    break;
                }
                case 3:{
                    cout << "������ѧ���µ��Ա�";
                    cin >> student.gender;
                    cout << "�޸ĳɹ���" << endl;
                    break;
                }
                case 4:{
                    cout << "������ѧ���µ����䣺";
                    cin >> student.age;
                    cout << "�޸ĳɹ���" << endl;
                    break;
                }
                case 5:{
                    cout << "������ѧ���µĵ�ַ��";
                    cin >> student.address;
                    cout << "�޸ĳɹ���" << endl;
                    break;
                }
                case 0:{
                    return;
                }
                default:
                    cout << "�������" << endl;
            }
        }
        else cout << "δ�ҵ����������ѧ����" << endl;
    }
}
void queryStudent(){
    string name;
    system("cls");
    cout << "������Ҫ��ѯ��ѧ��������";
    cin >> name;
    for (auto & student : students){
        if (student.name == name){
            cout << "������" << student.name << endl;
            cout << "���䣺" << student.age << endl;
            cout << "ѧ�ţ�" << student.num << endl;
            cout << "�Ա�" << student.gender << endl;
            cout << "��ַ��" << student.address << endl;
            break;
        } else cout << "δ�ҵ���ѧ����" << endl;
    }
}
int main(){
    while (true){
        cout << "-----------------------------------------------" << endl;
        cout << "             ���꼶����ѧ����Ϣϵͳ               " << endl;
        cout << "    1.���ѧ����Ϣ             2.ɾ��ѧ����Ϣ      " << endl;
        cout << "    3.�޸�ѧ����Ϣ             4.��ѯѧ����Ϣ       " << endl;
        cout << "                  0.�˳�ϵͳ                    " << endl;
        cout << "            ��������Ӧ�������Ӧ�޸ġ�             " << endl;
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
                cout << "�������" << endl;
                break;
        }
    }
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Human {
public:
    string surname;
    string name;
    string bat;
    int age;
    int grade;
    string sex;
    Human() {

    }

    Human(string surname, string name, string bat, int age, int grade, string sex) {
        this->surname = surname;
        this->name= name;
        this->bat= bat;
        this->age = age;
        this->grade = grade;
        this->sex = sex;
    }

    void print() {
        cout << endl << surname << endl << name << endl << bat << endl << age << endl << grade << endl << sex << endl;
    }
};




int main()
{

    char surname[30];
    char name[20];
    char bat[20];
    char age[5];
    char grade[2];
    char sex[2];
    char buf[300];
    int agei, gradei;
    vector<Human>names;
    ifstream file("A.txt");//прочитать


    
    if (file.is_open()) {
        cout << "Opened"<<endl;
    }
    else cout << "Not opened";


    while (file.getline(buf,200, ';')) {


        char* pointer = strtok(buf, ",");
        strcpy(surname, pointer);


        pointer = strtok(NULL, ",");
        strcpy(name, pointer);


        pointer = strtok(NULL, ",");
        strcpy(bat, pointer);


        pointer = strtok(NULL, ",");
        strcpy(age, pointer);


        pointer = strtok(NULL, ",");
        strcpy(grade, pointer);


        pointer = strtok(NULL, ",");
        strcpy(sex, pointer);


        int agei = atoi(age);
        int gradei = atoi(grade);
        string surnames=surname;
        string namess=name;
        string bats=bat;
        string sexs = sex;
        names.push_back(Human(surnames, namess, bats, agei, gradei, sex));

    }

    sort(names.begin(), names.end(), [](Human left, Human right) {
        return left.surname < right.surname;
        });

    for (int i = 0; i < names.size(); i++)
    {
        names[i].print();
    }

    

    sort(names.begin(), names.end(), [](Human left, Human right) {
        return left.age < right.age;
        });

    int max = 0;
    int cur = 1;
    int ans;
    for (int i = 0; i < names.size()-1; i++) {
        if (names[i].age == names[i + 1].age) {
            cur++;
            if (cur > max) {
                max = cur;
                ans = names[i].age;
            }
        }
        else cur = 0;
    }

    cout << endl << "Most common age: " <<ans<< endl;
    cout << endl << "Initials of students whose age the most common: " << endl;
    for (int i = 0; i < names.size() - 1; i++) {
        if (names[i].age == ans) {
            
            names[i].print();

        }

    }
}


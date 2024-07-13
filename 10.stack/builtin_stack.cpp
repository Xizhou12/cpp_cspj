#include <stack>
#include <iostream>
#include <string>

using namespace std;
//https://en.cppreference.com/w/cpp/container/stack

struct Student{
    int age;
    string name;
    float avg_score;

    string toString(){
        return "他是" + name + " 今年" + to_string(age) + "岁\n";
    }

    Student(int a, const std::string& n, float avg) 
        : age(a), name(n), avg_score(avg) {
        // Constructor logic
    }
};



int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    stack<Student> s2;
    s2.emplace(25, "xizhou", 100.0);
    s2.emplace(18, "小陈", 72.5);
    cout << "顶部数据" << s2.top().toString() << endl;
    cout << s2.size() << endl;
    return 0;
}
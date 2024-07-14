#include <iostream>
#include <queue>
#include <string>

using namespace std;
//https://en.cppreference.com/w/cpp/container/queue
struct Customer{
    int id;
    string order;
};

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    return 0;
}
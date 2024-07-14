#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Customer{
    int id;
    string order;

    Customer(int i, string o){
        id = i;
        order = o;
    }
    
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
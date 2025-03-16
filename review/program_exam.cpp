/*
    有一个学生的成绩名单, 由名字和分数组成 名字和分数之间都会由一个或多个空格分开
    最后一个分数后面会有一个句号

    格式类似如下（可能会有很多组名字和成绩，下面只是示例）
    michael 97  rachael 78 lileilei 85 James 67.

    1. 打印所有的学生名字，并且所有名字的首字母需要大写
    2. 统计所有学生的分数，并且打印排序后的分数 （如果能够从大到小排列+10）
    3. 打印所有是质数的分数
*/
#include <bits/stdc++.h>
using namespace std;
int compare(int a, int b){
    return a > b;
}
int is_prime(int n){
    if(n == 1) return 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
int main(){
    string name;
    string score;
    int scores[100];
    int number = 0;
    while(1){
        cin >> name;
        cin >> score;
        
        if(score[score.size()-1] == '.'){
            score = score.substr(0, score.size()-1);
            scores[number++] = stoi(score);
            break;
        }
        scores[number++] = stoi(score);
        name[0] = toupper(name[0]);
        cout << name << " ";
    }
    cout << endl;
    sort(scores, scores+number, compare);
    for(int i = 0; i < number; i++){
        cout << scores[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < number; i++){
        if(is_prime(scores[i])) 
            cout << scores[i] << " ";
    }
}
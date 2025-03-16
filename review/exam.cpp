<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

=======
/*
  有一个学生的成绩名单 有名字和分数组成 名字和分数之间都会有一个或多个空格分开
  最后一个分数后面会有一个句号
  格式类似如下（可能会有多组名字和成绩，不超过100组，下面只是示范, 总长度不超过20000字符）
  michael 97 rachael 78 lileilei  85 James 67.

  1. 打印所有学生的名字，要求首字母大写
  2. 统计所有学生的分数，打印排序后的分数（如果能够从大到小排列+10）
  3. 打印所有是质数的分数

  int x = stoi("123"); // x会是123

*/

#include <bits/stdc++.h>
using namespace std;
int compare(int a, int b){
  return a > b;
}
int isprime(int n){
  /*
    97 2..自身-1
    不能是因子 == 余除不为0
  */
 for(int i = 2; i <= n-1; i++){
  if(n % i == 0){
    return false;
  }
 }
 return true;
}
int main(){
  string name;
  string score;

  int scores[100]; //存所有的分数
  int number = 0;  //分数的下标，最后也代表一共多少组数据
  /*
    getline 
    1. 你看见字符 看见空格，可以输出name，把首字母大写
    isalpha(char c) 字母
    isdigit(char c) 数字
  */
  while(1){
    cin >> name;
    cin >> score; // "1234." 
    name[0] = toupper(name[0]);
    cout << name << " ";
    scores[number] = stoi(score);
    number++;
    if(score[score.size()-1] == '.'){
      score = score.substr(0, score.size()-1); // "1234"
      scores[number] = stoi(score);
      break;
    }
  }
  /*
    默认从小到大排序
  */
  cout << endl;
  sort(scores, scores+number, compare); //地址 pointer
  for(int i =0; i<number; i++){
    cout << scores[i] << " ";
  }
  cout << endl;
  for(int i =0; i<number; i++){
    if(isprime(scores[i])){
      cout << scores[i] << " ";
    }
  }
}
>>>>>>> e178c0a (update2)

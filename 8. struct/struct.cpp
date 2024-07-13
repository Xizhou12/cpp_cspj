#include <cstdio>
#include <iostream>
#include <string>

using namespace std;


int create_struct(){
  struct student{ // 数据类型 int double
    string name; 
    int age;     
    int chinese, math;
    int total_score;
  } a[3]; // 3个学生的数据
  a[0].name = "李老师";
  cout << a[0].name << endl;

  student x = {"lxz", 28, 150, 150, 300}; // 固定大小的栈

  student *p = new student;               // 堆
  p -> name = "lxz";
  p -> age = 28;
  p -> math = 150;
  cout << x.age <<  " " << p->math << endl;
  return 0;
}

int pointer(){
  int x = 3;
  int *p = NULL; //  空指针
  int *p = &x;
  int x;            // 我向内存索要了一个int大小的内存吧         栈 stack 

  x = 200;
  int *p = new int; // 通过指针 我向内存索要了一个int大小的内存吧  堆 heap
  *p = 130;
  *p = 10;
  cout << *p << endl;
  cout << p << endl;
  return 0;
}

int main(){
  // pointer();
  create_struct();
  // struct student {
  //   string name;
  //   int age;
  //   int math,chinese;
  //   int total_score;
  // } a[3];

  
  // for(int i = 0; i < 5; i++){
  //   cin >> a[i].name;
  //   cin >> a[i].age;
  //   cin >> a[i].math >> a[i].chinese ;
  //   a[i].total_score = a[i].math + a[i].chinese;
  // }

  // for(int i = 0; i < 5; i++){
  //   cout << a[i].name << "'s total score: " << a[i].total_score << endl;
  // }

  // student* x = new student;
  // x -> name = "李老师";
  // x -> age = 20;
  // x -> math = 100;
  // x -> chinese = 80;
  // x -> total_score = x -> math + x -> chinese;

  // cout << x << endl;
  // cout << x -> age << endl;


  // return 0;
}

/*
   name
   telephone

*/

// struct 结构体

#include <cstdio>
#include <iostream>

using namespace std;

/*
  scanf printf 的返回值
  scanf 返回 成功读取的个数
  printf 返回 打印的字符个数
*/
int cal_sum();
int fibonacci();
int main(){
  // 要求输入一个整数数字 然后 去判断这个数字是不是偶数
  // 如果是的话 我们打印它是偶数 它不是
  /*
    2. if else 语句
      条件:
        a > 3 -> true  1
              -> false 0      
        例如我是否是一个男孩
        所有答案可以分为对或错的问句都属于是条件
    if (条件){
      满足条件的时候执行的语句
    } else {
      不满足条件的时候执行的语句
    }
    e.g. 判断输入是不是偶数
  */
  int x;
  scanf("%d", &x);
  if (x % 2 == 0){
    printf("x 是偶数");
  } else {
    printf("x 是奇数");
  }
  // cal_sum();
  // fibonacci();
}

int cal_sum()
{
  /*
    1. int i = 0; 初始化 循环，这一部分只会运行一次
    2. i < 10 循环的条件 看是否满足, 不满足的话退出循环       
    3. 运行循环{}内的指令
    4. 递增i这个值 通过这个控制循环次数 来满足退出的循环的条件，回到步骤2

    for ( 初始化; 循环条件; 递增){
      循环内的操作
        1. 这里面可以跟任何语句 例如 调用函数，if 语句,再嵌套一个for 循环等等
    }
    e.g. 输出 1 到 100 的奇数和
  */
  int i, sum = 0;
  for (i = 1; i<101 ;i++){ 
    // i 从 1 每次循环 + 1 直到 101, 不再满足条件后退出循环， 注意 i 作为101 并没有被加到 sum 中去
    if (i % 2 == 1){
      sum = sum + i;
    }
  }
  printf("%d", sum);
  return 0;
}
// 1071：菲波那契数: http://ybt.ssoier.cn:8088/problem_show.php?pid=1071
int fibonacci(){
  int k;
  scanf("%d", &k);
  /*
    1 1 2 3 5 8 13 21 34 55 89 144
    解题思路 可以 用两个变量 a b 分别代表 计算fibonacci 当前数字的前两个数
    第一次循环 a = 0 b = 1 -> a = 1 b = 1 
    第二次循环 a = 1 b = 1 -> a = 1 b = 2
    第三次循环 a = 1 b = 2 -> a = 2 b = 3
    可以发现i次循环结束后a的值就是第i个fibonacci的值
    要让 a的值为b b的值为a+b我们需要用下面的方法
    int temp = a + b;
    a = b;
    b = temp; 这就是每次循环的内容
  */
  int a = 0, b = 1; // fibonacci 的前两个数
  for( int i = 0; i < k; i++){ // i 从 0 开始 每次循环 + 1 直到 k, 一共循环了k次
    int temp = a + b;
    a = b;
    b = temp;
  }
  printf("%d", a);
  return 0;
}
//信奥题库：http://ybt.ssoier.cn:8088
//打字：https://dazi.kukuw.com
//打字：https://www.typingclub.com/sportal/program-48.game
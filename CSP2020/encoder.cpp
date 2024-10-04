#include <cstdlib>
#include <iostream>
using namespace std;

char encoder[26] = {'C','S','P','A','B','D','E','F','G','H','I','J','K','L','M','N','O','Q','R','T','U','V','W','X','Y','Z'}; // 26 null terminator = 0
                        //   C(2)                                        P(15)Q          S(18)T
               //输入A   B   C   D   E   F   G   H   I  J    K   L   M   N   O   P   Q   R   S  'T','U','V','W','X','Y','Z'
char decoder[26] = {'D','E','A','F','G','H','I','J','K','L','M','N','O','P','Q','C','R','S','B','T','U','V','W','X','Y','Z'}; // 26 'S' - 'A' 输出

/*
密码编码器
x: A - Z
  i: 0 - 25
    x == 'A', flag = true, i=0 ,k=3
    encoder[i] == x? cuo
    i = 1,2,3,4....25 cuo

    flag = true
    在encoder3的位置上加上A 同时k++
*/

string st;

int main()  {
  int k = 0;

  for (int i = 0; i < 26; ++i)
    if (encoder[i] != 0) ++k; // k = 3 encoder中不为0的个数
  for (char x ='A'; x <= 'Z'; ++x) {
    bool flag = true;
    for (int i = 0; i < 26; ++i)
      if (encoder[i] ==x) {
        flag = false;
        break;
      }
    if (flag) {
        encoder[k]= x;
        ++k;
    }
  }
  //encoder 被填充完毕
  for (int i = 0; i < 26; ++i)
     decoder[encoder[i]- 'A'] = i + 'A';

  //  你的输入和encoder decoder没有关系
  cin >> st;
  for (int i = 0; i < st.length( ); ++i)
  // A=0 B=1
    st[i] = decoder[st[i] -'A'];
  cout << st;
  return 0;
}
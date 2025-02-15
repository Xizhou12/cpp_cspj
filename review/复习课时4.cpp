
#include<bits/stdc++.h>

using namespace std;
int main(){
    /*
        字符数组 - char * 需要定义长度
        char s[100];
        sizeof(s) 字符刷组的长度
        strlen(s) 字符串的长度
        输入可以用cin，也可以用scanf
    */
    /*
        c++ string 不需要定义长度
        string s; 
        s.size() 字符串的长度
        输入只可以用cin，不可以用scanf
    */

    string s = "hello, world";
    string new_s = s.substr(1,4); // 从下标1开始，长度为4 ello

    if (s >= "iello, world"){
        /*
            string s 可以直接和字符串比较, 比较方法是按照字母拍序 abcd...xyz
        */
        cout << "success" << endl;
    }

    /*
        string s 类型可以直接进行加法运算
    */
    new_s = s + "!!!"; // hello, world!!! 
    s.append("!!!");   // hello, world!!! append 指在末尾进行添加 和+效果一样但是是在原来的字符串s上进行添加 不会生成新的字符串

    /*
        可以通过find 函数寻找第一个出现的字符位置
    */
    char find_char = s.find('o'); // 4 第一个出现o的位置
    /*
        s.begin() 返回一个指向第一个字符的迭代器
        s.end() 返回一个指向最后一个字符的下一个位置的迭代器
        了解就好
    */
    sort(s.begin(), s.end()); // 对字符串进行排序
    stable_sort(s.begin(), s.end()); // 对字符串进行排序

    string countries[5] = {"China", "America", "Japan", "Korea", "France"};
    sort(countries, countries+5); // 对字符串数组进行排序



    /*
        关于字符的方法
        isupper(char c) 判断是否是大写字母
        islower(char c) 判断是否是小写字母
        isdigit(char c) 判断是否是数字
        isalpha(char c) 判断是否是字母
        isalnum(char c) 判断是否是字母或者数字
        tolower(char c) 将大写字母转换为小写字母
        toupper(char c) 将小写字母转换为大写字母
        atoi(char* s) 将字符串转换为整数 只能用作字符数组
    */
    int i = isupper('A'); // 1 true
    i = islower('A'); // 0 false
    i = isdigit('1'); // 1 true
    i = isalpha('A'); // 1 true
    i = isalpha('z'); // 1 true
    i = isalnum('C'); // 1 true
    i = isalnum('8'); // 1 true
    char c = tolower('A'); // 'a'
    int number = atoi("123"); // 123

}






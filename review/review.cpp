#include <bits/stdc++.h>

using namespace std;
// int compare(int x, int y){

// };

int main() {
    // char s[20];
    // char s1[20] = {'a', 'b', 'c', 'd', 'e'}; //自动把0补齐
    // char s2[6] = "abcde";
    // char s3[] = "abcde";
    // char s4[5] = {'a', 'b', 'c', 'd', '\0'};

    int x[20] = {1,2,3};// 他会自动把0补齐
    /*
        字符串和普通字符数组的区别
        他的结尾有一个 \0 NULL terminator 字符 对应了ascii里的第一个字符 0
        Hello \0 \n \t
    */

    // char s[] = "abcde"; //如果是字符串的话 我们是不需要用for循环来读
    
    // cout << s << endl;
    // printf("%s\n", s);
    // puts(s); //自动加回车的一个专门用来读字符串的方法

    /*
        cin, scanf: 如果遇到空格 换行还有tab的时候都会自动停止
        fgets \n
    */
   
    char s1[20];
//    cin >> s1;
//    cout << s1 << endl;
    scanf("%s", s1); // 取地址
    cout << s1 << endl;

    // (char *)
    fgets(s1, 20, stdin); // 读取一行
    cin.getline(s1, 20);  // 读取一行

    string s;
    getline(cin, s);      //读取一行

    /*
        EOF end of line
        cin, scanf, fgets
        cin >> n
        int n;
        scanf("%s", &n); 
        int x = scanf("%d %s %f", &n, s, &f); 3
            1. 读取成功的时候返回的是成功读取的个数
            2. 读取失败了返回的是-1
            3. 没有东西让我读取返回的就是EOF
        cin 的返回值 0，1 false true
    */
    int n;
    if(scanf("%d", &n) != EOF){
        cout << n << endl;
    }
    
    char s2[20] = "abcde";

    /*
        char *: strcmp(s1, s2) == 0
        string: > < == !=
        sort()

        char *: strlen(s)
        string: s.size()

        string: s1 + s2

        string s = "abcde";
        char s2[20] = "ghijk";
        
    */
   string str[25];//字符串数组
   cin >> n;
   for(int i = 0; i < n; i++){
         getline(cin, str[i]);
   }
   /*
    sort 如果是只给两个参数的话 只能作用于string 因为string 可以用 > < == !=进行比较而char *不行
   */
   sort(str, str + n);
    for(int i = 0; i < n; i++){
         cout << str[i] << endl;
    }
    return 0;
}
    

//dazikukuw.com
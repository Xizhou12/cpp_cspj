#include <iostream>
#include <queue>
#include <string>


/*
    常用处理输入总结：
    cin.getline(cpp_s, 100) 读取一行字符串           // -> string s; 
    fgets(c_s, 100, stdin) 读取一行字符串        // -> char c_s[100];
    cin >> s 读取一个字符串 遇到tab space 就结束, scanf("%s", s) 读取字符串 非整行 遇到tab space 就结束 完全一样的作用 cin用起来更方便除非有特殊格式要求
    "I am a student"
    scanf("%d", &n) 读取一个整数
    
    对于不知道有多少个输入的情况，可以用while(cin.getline(c_s, 100)) 或者 while(fgets(c_s, 100, stdin))
*/
using namespace std;
int main(){
    char s[100];
    fgets(s, 100, stdin);  // 只能用于c的字符数组/字符串
    cin.getline(s, 100);   // 可以用于c++的string

    string s2;
    cin.getline(s2.data(), 100);

    // 各个输入的返回值
    int n, m, k;
    int x = scanf("%d", &n); // 返回值是读取的个数, 读取失败返回-1 (EOF)
    int x2 = scanf("%d %d %d", &n, &m, &k); // 如果成功读取两个数字，并未成功读取第三个数字返回2

    /*
        int x; 读取字符串 scanf("%s", &x); 会报错
        什么是EOF = end of file
        在文件读取中，EOF是一个宏，它表示文件结束符。在C语言中，EOF是一个负整数，通常是-1
        在读取键盘输入时，当按下Ctrl+D（Linux）或enter 以后Ctrl+Z（Windows）时，会产生EOF 是用户想要停止输入的结果
    */
    int x3 = 0;
    while(cin.getline(s, 100)){ // 会在读取到EOF时停止 或者读取输入失败（不是对应的类型）
        x++;
    }

    while(fgets(s, 100, stdin)){ // 会在读取到EOF时或读取失败停止
        x++;
    }

    while(cin >> n){ // 会在读取到EOF或错误的input时停止 错误的input例如向整数读取abc
        x++;
    }

    while(scanf("%d", &n)!= EOF ){ // 会在读取到EOF时停止
    /*
        成功读取 返回值是读取的个数
    */
        x++;
    }

    while(scanf("%d %d %d", &n, &m, &k) != 3){ // 如果我们预期读取三个数字，却只成功读取两个我们也可以通过判断丢弃这个输入
        x++;
    }

/*
    c++ string和cstring常用函数 
    string s  |   char s[]
    ------------------------
    s.size()  |   strlen(s)       字符串的size 多少个字符直到 \0 注意不要用 sizeof(s) 这会把\0后面的无效字符也算进去 sizeof(s)
    == !=     |   strcmp(s1, s2)  比较两个字符串是否相等
              |
              |
              |
              |
    char s[100] = {'1', 'a' ,'\0'}; strlen(s) = 3 . sizeof(s) = 100
*/

/* STL 容器 
1. list
   双重链表
   获取元素 O(n)
   插入/删除 O(1)
   适合频繁插入删除的场景
2. vector （* 重点）c++用来代替c的数组 int x[][100] -> vector<vector<int>> x
    动态数组 优点与普通的数组 
        - 不需要在定义固定的大小， 可以动态增长
        - 多维数组传参时不需要指定第二维的大小
    获取元素 O(1)
    插入/删除 O(n)
    适合频繁访问的场景
3. deque
    双端队列
    获取元素 O(1)
    插入/删除 O(1)
    适合频繁在两端插入删除的场景
4. stack （* 重点）
    栈
    先进后出
    push/pop O(1) 插入和删除
    通常是由vector或deque实现的
5. queue （* 重点）
    队列
    先进先出
    push/pop O(1) 插入和删除 [1 3 5 4]
    通常是由deque实现的
6. priority_queue （** 重点）
    优先队列
    获取元素 O(1)
    插入/删除 O(logn) 会自动排序 [1 3 5 4] -> 5,4,3,1
    通常是由vector实现的
7. unordered_set （** 重点）
    无序集合
    插入/删除/查找 O(1) python set
    通常是由哈希表实现的
8. unordered_map （** 重点）
    无序映射
    插入/删除/查找 O(1)
    通常是由哈希表实现的 key->value 
使用方法
根据该题目要求，容器的特点选择合适的容器 
1. 创建容器
    vector<int> v; struct People
    unordered_map<int, int> m; //相当于python 的字典 需要存储key value pair 有映射关系
2. 方法 请查看 Cpp中文帮助文档.chm
通常都是 v.push_back() 容器.方法(参数) 参数根据函数可有可无
    

*/
    
}
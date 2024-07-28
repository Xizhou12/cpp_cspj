/*
【题目描述】
大数学家高斯小时候偶然间发现一种有趣的自然数集合Blah，对于以a为基的集合Ba定义如下：

(1)a是集合Ba的基，且a是Ba的第一个元素；

(2)如果x在集合Ba中，则2x+1和3x+1也都在集合Ba中；

(3)没有其他元素在集合Ba中了。

现在小高斯想知道如果将集合Ba中元素按照升序排列，第N个元素会是多少？

【输入】
输入包括很多行，每行输入包括两个数字，集合的基a(1≤a≤50))以及所求元素序号n(1≤n≤1000000)。

【输出】
对于每个输入，输出集合Ba的第n个元素值。

【输入样例】
1 100
28 5437
【输出样例】
418
900585

{1,3，4，7，10，9，13，15，22，  } 2*x+1 3x+1 对于集合 这里面不会有重复的数字
【题目难点】
1. 处理输入 需要处理EOF
2. 如何实现升序 从小到大排列
3. 数据重复问题 
两个队列来做
1->1 2x+1 3x+1
2->q1{3} head1 -> pop 3 -> 7 10 //2x+1 > x
   q2{4} head2                  //3x+1 > x >= 3
3->q1{7}    head1
   q2{4,10} head2 -> pop 4 -> 9 13
4->q1{7, 9}    head1 pop 7
   q2{10,13}   head2 
*/

#include <queue>
#include <iostream>
#include <set>
using namespace std;

struct Compare{
    bool operator()(int a, int b){
        return a > b;
    }
};

int solution_priority_queue(){
    int cur, element, pos, j=0;
    /* 
        这里我们还使用了std::set来记录已经出现过的数字 set是一个集合，它的特点是里面的元素不重复
    */
    set<int> s; 
    /*
        priority_queue 是一个优先队列，它的特点是每次取出的元素是队列中优先级最高的元素(默认是最大，你可以通过Compare自定义优先级)
        题目要求是升序，所以我们需要定义一个struct Compare，使得每次取出的元素是最小的
        它的原理是堆排序 每次插入一个元素，都会重新排序
        priority_queue<类型，容器，比较函数> pq; (容器 可以是std::vector, std::deque，std::list, 以后再重点讲）
    */
    priority_queue<int, vector<int>, Compare> pq, empty_pq;
    while(cin >> element >> pos){ //当输入结束时，cin会返回false
        pq.push(element);
        for(int i = 0; i < pos; i ++){
            cur = pq.top();
            pq.pop();
            cout << cur << endl;
            int num1 = 2*cur+1;
            int num2 = 3*cur+1;
            if(!s.count(num1)){ 
                pq.push(num1);
                s.insert(num1);
            }
            if(!s.count(num2)){
                pq.push(num2);
                s.insert(num2);
            }
        }
        s.clear();         // 清空set
        pq.swap(empty_pq); // 清空队列 
    }

}  
// 更优解
int solution_compare2queue(){
    /*
        两个队列 1 - 2x+1  3x+1
        {103 ..} -> head1 -> pop 拿出来 3 - 7 10
        {103 .. } -> head2 
        这个方法保证了这两个队列是顺序排列的
    
    */
	queue<int> q2, q3;
	int a, n;
	while(cin >> a >> n){
		q2 = queue<int>(); //清空队列 
		q3 = queue<int>();
		for(int i = 2; i <= n; ++i) //求第i小的值，初始情况a是第1小的值 
		{
			q2.push(2*a+1); // {3}
			q3.push(3*a+1); // {4}
			if(q2.front() > q3.front())//如果3x+1队列队首更小 
			{
				a = q3.front();
				q3.pop();
			}
			else if(q2.front() < q3.front())//如果2x+1队列队首更小
			{
				a = q2.front();
				q2.pop();
			}
			else
			{
				a = q2.front();
				q2.pop();
				q3.pop(); //做到两个数字并不会重复
			}
		}
		cout << a << endl;
	} 
    return 0;
}

int main(){
    solution_priority_queue();
    solution_compare2queue();
}

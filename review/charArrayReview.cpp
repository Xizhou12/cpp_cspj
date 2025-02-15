#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctype.h>

using namespace std;
//-std=c++11
int main(){
    char A[100];
    char B[100];
    char c;
    int nxt = 0;
    while(scanf("%c", &c) != EOF){
        if (c == '\n' || c == '\0'){
            break;
        }
        if(c == ' ' ){
            continue;
        }else{
            if(isupper(c)){
                A[nxt++] = tolower(c);
            }else{
                A[nxt++] = c;
            }
        }
    }
    A[nxt] = '\0';
    nxt = 0;
    while(scanf("%c", &c) != EOF){
        if (c == '\n' || c == '\0'){
            break;
        }
        if(c == ' '){
            continue;
        }else{
            if(isupper(c)){
                B[nxt++] = tolower(c);
            }else{
                B[nxt++] = c;
            }
        }
    }
    B[nxt] = '\0';

    if (strcmp(A, B) == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
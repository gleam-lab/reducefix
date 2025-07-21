#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<map>
#include<cmath>
#include<math.h>
#include<queue>
#include <iomanip> //setprecisionを使うため
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    set<int> s; // 使用set来存储不同的整数，自动去重且有序
    int q;
    cin >> q;

    int ans=0;
    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            s.insert(x); // 插入新元素到set中，如果已经存在则不会改变大小
        }else if(n==2){
            cin >> x;
            s.erase(x); // 从set中删除元素，如果不存在则不会改变大小
        }else{
            cout << s.size() << endl; // 直接输出set的大小即为不同整数的数量
        }
    }

    return 0;
}
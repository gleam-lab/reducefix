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
    set<int> s; // 使用set来存储球的值，自动去重并且有序
    int q;
    cin >> q;

    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            s.insert(x); // 将球插入到集合中
        }else if(n==2){
            cin >> x;
            s.erase(s.find(x)); // 从集合中移除球
        }else{
            cout << s.size() << endl; // 输出集合的大小，即不同整数的数量
        }
    }
    return 0;
}
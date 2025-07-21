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
    set<int> s; // 使用集合来存储不同整数的球，自动去重
    int q;
    cin >> q;

    int ans=0;
    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            s.insert(x); // 插入新球，如果已存在则不会重复计数
        }else if(n==2){
            cin >> x;
            s.erase(s.find(x)); // 删除指定球
        }else{
            cout << s.size() << endl; // 输出当前集合中不同整数的数量
        }
    }

    return 0;
}
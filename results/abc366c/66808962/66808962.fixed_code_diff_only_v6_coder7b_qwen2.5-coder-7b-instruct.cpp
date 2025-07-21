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
    set<int> s;
    int q;
    cin >> q;

    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            s.insert(x); //直接集合に挿入することで重複を自動的に排除
        }else if(n==2){
            cin >> x;
            s.erase(s.find(x)); //集合から削除する際はfindで位置を先に取得
        }else{
            cout << s.size() << endl; //集合のサイズ（異なる整数の数）を出力
        }
    }
    return 0;
}
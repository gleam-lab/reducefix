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

    int ans=0;
    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            if(s.find(x) == s.end()) { //まだそのボールが1個もなかった時
                s.insert(x);
            }
        }else if(n==2){
            cin >> x;
            s.erase(x);
        }else{
            cout << s.size() << endl;
        }
    }
    // cout << m.size() << endl;
    return 0;
}
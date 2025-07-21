#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i < (n); i++)
typedef long long ll;

int main() {
    int n; cin >> n;
    ll t = 0;
    while(true){
        bool flag = false;
        rep(i, n){
            if(h[i] > 0){
                flag = true;
                if((t+1)%3 == 0) h[i] -= 3;
                else h[i]--;
            }
        }
        t++;
        if(!flag) break;
    }
    cout << t-1 << '\n';
    return 0;
}
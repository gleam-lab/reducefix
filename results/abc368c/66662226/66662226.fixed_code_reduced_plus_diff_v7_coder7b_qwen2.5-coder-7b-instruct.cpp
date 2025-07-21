#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n){
        cin >> v[i];
    }

    ll t = 0;
    while(true){
        bool flag = false;
        rep(i,n){
            if(v[i]>0){
                flag = true;
                if(t%3==0) v[i]-=3;
                else v[i]-=1;
                t++;
                if(v[i]<=0) v[i]=0;
            }
        }
        if(!flag) break;
    }
    cout << t << "\n";
}
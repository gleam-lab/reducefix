#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,m,K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        K -= a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    vector<ll> ans(n);
    for(int i=0;i<n;i++){
        ll need = 0;
        for(int j=i+1;j<n;j++){
            if(m-j+i+1 <= 0) break;
            need += max(0LL, a[i] + need - a[j]);
        }
        if(need > K) ans[i] = -1;
        else ans[i] = need;
    }

    for(auto x: ans) cout << x << " ";
    return 0;
}
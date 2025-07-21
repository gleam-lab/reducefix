#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, ll m, vector<ll> &a, vector<ll> &b) {
    set<ll> sa, sb;
    for(auto x : a) sa.insert(x);
    for(auto x : b) sb.insert(x);

    ll ans = n*n;
    
    // Rows and Columns
    for(auto x : sa) ans -= n;
    for(auto x : sb) ans -= n;

    // Diagonals
    unordered_set<ll> diag1, diag2;
    for(int i=0;i<m;++i){
        diag1.insert(a[i]+b[i]);
        diag2.insert(a[i]-b[i]);
    }
    for(auto x : diag1) ans -= n;
    for(auto x : diag2) ans -= n;

    return max(0LL, ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    for(int i=0;i<m;++i){
        cin >> a[i] >> b[i];
    }

    cout << solve(n,m,a,b) << '\n';
    return 0;
}
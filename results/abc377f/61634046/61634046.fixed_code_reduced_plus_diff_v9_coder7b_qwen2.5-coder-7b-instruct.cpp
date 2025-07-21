#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<int> row(n+1), col(n+1);
    map<int, set<int>> diag1, diag2;
    
    for(int i=1;i<=m;++i){
        int a, b;
        cin >> a >> b;
        row[a]++;
        col[b]++;
        diag1[a+b].insert(b);
        diag2[a-b].insert(b);
    }
    
    ll ans = (ll)n*n - (ll)m*m;
    
    for(int i=1;i<=n;++i){
        ans -= (ll)(n-row[i])*(n-col[i]);
    }
    
    for(auto &[_, st]: diag1){
        int sz = st.size();
        ans -= (ll)(n-sz)*(n-sz);
    }
    
    for(auto &[_, st]: diag2){
        int sz = st.size();
        ans -= (ll)(n-sz)*(n-sz);
    }
    
    cout << ans << endl;
    
    return 0;
}
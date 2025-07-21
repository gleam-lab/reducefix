#include <bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    int n, m; cin >> n >> m;
    set<pair<int, int>> st;
    for(int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        st.insert({x, y});
    }
    
    LL res = (LL)n*n - m;
    
    for(auto [x, y]: st) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(st.count({x, i})) ++cnt;
            if(st.count({i, y})) ++cnt;
            if(st.count({i, 2*x+y-i})) ++cnt;
            if(st.count({i, 2*y-x+i})) ++cnt;
        }
        res -= cnt;
    }
    
    cout << res << endl;
    return 0;
}
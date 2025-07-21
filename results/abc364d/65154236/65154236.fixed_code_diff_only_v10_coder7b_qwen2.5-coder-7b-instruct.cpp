#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
vector<int> a[MAXN], b[MAXN];

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[x].push_back(i);
    }
    for(int i = 1; i <= q; i++) {
        int x, y; cin >> x >> y;
        b[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++)
        sort(a[i].begin(), a[i].end());
    
    for(int i = 1; i <= q; i++) {
        int ans = INT_MAX;
        for(auto& pos : b[i]) {
            int idx = upper_bound(a[pos].begin(), a[pos].end(), q) - a[pos].begin() - 1;
            if(idx >= 0 && idx < n)
                ans = min(ans, abs(pos - a[pos][idx]));
        }
        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
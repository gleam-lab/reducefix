#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
ll a[N], b[N];

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= q; i++){
        int x, y; cin >> x >> y;
        auto it = lower_bound(a + 1, a + n + 1, x - y);
        if(it == a + n + 1) cout << abs(*prev(it) - x) << endl;
        else cout << min(abs(*it - x), abs(*prev(it) - x)) << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
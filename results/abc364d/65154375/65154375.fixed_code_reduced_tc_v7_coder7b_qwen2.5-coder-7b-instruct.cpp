#include <bits/stdc++.h>
using namespace std;

vector<long long> a, b;

void solve() {
    int n, q; cin >> n >> q;
    a.resize(n + 1); b.resize(q + 1);
    
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= q; ++i) {
        cin >> b[i] >> a[i];
    }

    sort(a.begin(), a.end());

    for(int i = 1; i <= q; ++i) {
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        int index = it - a.begin();
        long long dist = abs(b[i] - a[index]);
        if(index > 0 && dist > abs(b[i] - a[index - 1])) --index;
        cout << dist << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1; // Uncomment below line for multiple test cases
    // cin >> t;
    while(t--) solve();

    return 0;
}
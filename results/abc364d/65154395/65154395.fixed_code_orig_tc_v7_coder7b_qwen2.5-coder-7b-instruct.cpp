#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    int n, q;
    cin >> n >> q;
    v.resize(n + 1);
    for(int i = 1; i <= n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 1; i <= q; ++i) {
        int x, k;
        cin >> x >> k;
        auto it = lower_bound(v.begin(), v.end(), x);
        int idx = it - v.begin();
        if(k > idx) cout << "INF\n";
        else cout << abs(x - v[idx - k]) << '\n';
    }
    return 0;
}
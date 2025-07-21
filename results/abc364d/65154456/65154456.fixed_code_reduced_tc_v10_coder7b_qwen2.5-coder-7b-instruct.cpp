#include<bits/stdc++.h>
using namespace std;

vector<int> a;

void solve() {
    int n, q; cin >> n >> q;
    a.resize(200000001);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x + 100000000]++;
    }
    partial_sum(a.begin(), a.end(), a.begin());
    for(int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        int pos = lower_bound(a.begin(), a.end(), y) - a.begin();
        cout << pos - x + 100000000 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
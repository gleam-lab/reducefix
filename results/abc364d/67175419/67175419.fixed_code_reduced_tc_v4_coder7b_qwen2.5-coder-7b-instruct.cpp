#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

void solve() {
    cin >> n >> m;
    vector<int> b(m), kth(m);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    for(int i = 0; i < m; ++i) {
        cin >> b[i] >> kth[i];
    }

    for(int i = 0; i < m; ++i) {
        int target = b[i], pos = kth[i];
        auto it = lower_bound(a, a + n, target);
        int dist = abs(target - *it);
        if(it != a && abs(target - *(it - 1)) < dist) {
            dist = abs(target - *(it - 1));
        }
        cout << dist << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
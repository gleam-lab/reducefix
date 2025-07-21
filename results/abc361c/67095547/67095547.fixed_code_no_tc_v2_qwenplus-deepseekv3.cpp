#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int min_diff = LLONG_MAX;
    for (int i = 0; i <= k; i++) {
        int j = n - k + i - 1;
        if (j >= i) {
            min_diff = min(min_diff, a[j] - a[i]);
        }
    }
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
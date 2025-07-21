#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define rep(i, x) for (int i = 0; i < (int)(x); i++)
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int min_diff = INT_MAX;
    for (int i = 0; i <= k; i++) {
        int j = i + (n - k) - 1;
        if (j >= n) break;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    cout << min_diff << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
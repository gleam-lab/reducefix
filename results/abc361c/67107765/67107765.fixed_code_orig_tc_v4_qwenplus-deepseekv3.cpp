#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = LLONG_MAX;
    for (int i = 0; i <= k; i++) {
        int j = n - 1 - (k - i);
        ans = min(ans, (ll)a[j] - a[i]);
    }
    cout << ans << endl;
    return 0;
}
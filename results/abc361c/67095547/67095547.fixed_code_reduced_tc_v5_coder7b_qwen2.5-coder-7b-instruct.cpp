#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll min_range = LLONG_MAX;
    for (int i = 0; i <= n - k; ++i) {
        ll current_range = a[i + k - 1] - a[i];
        min_range = min(min_range, current_range);
    }

    cout << min_range << endl;

    return 0;
}
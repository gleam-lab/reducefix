#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long min_diff = LLONG_MAX;
    for (int i = 0; i <= n - k; ++i) {
        min_diff = min(min_diff, a[i + k - 1] - a[i]);
    }

    cout << min_diff << endl;

    return 0;
}
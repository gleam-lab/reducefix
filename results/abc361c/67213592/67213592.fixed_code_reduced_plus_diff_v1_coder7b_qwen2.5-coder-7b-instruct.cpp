#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto& val : v) {
        cin >> val;
    }

    sort(v.begin(), v.end());

    int ans = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, v[n - k + i] - v[i]);
    }

    cout << ans << endl;
    return 0;
}
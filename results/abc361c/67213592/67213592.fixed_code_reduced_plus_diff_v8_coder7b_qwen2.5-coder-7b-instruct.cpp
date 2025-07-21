#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long min_value = LLONG_MAX;
    for (int i = 0; i <= n - k; ++i) {
        min_value = min(min_value, static_cast<long long>(v[i + k - 1]) - v[i]);
    }

    cout << min_value << endl;

    return 0;
}
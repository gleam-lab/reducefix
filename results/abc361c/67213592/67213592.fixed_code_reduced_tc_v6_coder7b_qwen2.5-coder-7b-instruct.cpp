#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &val : v) {
        cin >> val;
    }

    sort(v.begin(), v.end());

    long long min_diff = LLONG_MAX;
    for (int i = 0; i <= k; ++i) {
        min_diff = min(min_diff, (long long)v[i + n - 1 - k] - v[i]);
    }

    cout << min_diff << endl;

    return 0;
}
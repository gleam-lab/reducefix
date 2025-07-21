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
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long min_diff = LLONG_MAX;

    for (int i = 0; i <= n - k; ++i) {
        long long current_diff = v[i + k - 1] - v[i];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }

    cout << min_diff << endl;

    return 0;
}
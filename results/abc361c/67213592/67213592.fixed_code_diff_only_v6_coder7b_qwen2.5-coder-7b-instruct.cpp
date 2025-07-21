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
    for (auto& val : v) {
        cin >> val;
    }

    sort(v.begin(), v.end());

    int best_diff = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        best_diff = min(best_diff, v[n - 1 - i] - v[i]);
    }

    cout << best_diff << endl;

    return 0;
}
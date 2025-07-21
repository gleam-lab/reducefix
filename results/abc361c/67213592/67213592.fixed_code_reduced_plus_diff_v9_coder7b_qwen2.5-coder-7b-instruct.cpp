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

    int min_diff = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        int current_diff = v[min(n - 1, i + k)] - v[i];
        min_diff = min(min_diff, current_diff);
    }

    cout << min_diff << endl;

    return 0;
}
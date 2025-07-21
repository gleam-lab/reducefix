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
    int result = v.back() - v.front(); // Initialize with the worst case
    for (int i = 0; i <= k; ++i) {
        int j = k - i;
        int current_diff = v[n - 1 - j] - v[i];
        if (current_diff < result) {
            result = current_diff;
        }
    }
    cout << result << endl;
    return 0;
}
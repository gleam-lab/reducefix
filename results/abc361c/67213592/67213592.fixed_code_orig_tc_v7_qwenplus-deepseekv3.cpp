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
    int result = v[n - 1] - v[0]; // Initialize with the worst case
    for (int i = 0; i <= k; ++i) {
        int left = i;
        int right = n - 1 - (k - i);
        if (left <= right) {
            result = min(result, v[right] - v[left]);
        }
    }
    cout << result << endl;
    return 0;
}
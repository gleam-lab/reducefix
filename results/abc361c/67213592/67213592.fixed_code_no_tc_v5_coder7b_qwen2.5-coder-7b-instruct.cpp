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

    // Calculate the initial difference
    int best = v[n - 1] - v[0];

    // Try removing one element at a time from both ends
    for (int i = 0; i <= k; ++i) {
        best = min(best, max(v[n - 1 - i], v[k]) - min(v[i], v[n - k]));
    }

    cout << best;
    return 0;
}
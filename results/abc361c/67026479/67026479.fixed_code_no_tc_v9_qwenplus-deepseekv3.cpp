#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int m = n - k;
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<pair<int, int>> indexed_a(n);
    for (int i = 0; i < n; ++i) indexed_a[i] = {a[i], i};
    sort(indexed_a.begin(), indexed_a.end());
    
    int min_diff = INT_MAX;
    vector<int> indices;
    for (int i = 0; i <= n - m; ++i) {
        int current_diff = indexed_a[i + m - 1].first - indexed_a[i].first;
        if (current_diff < min_diff) {
            min_diff = current_diff;
            indices.clear();
            for (int j = i; j < i + m; ++j) {
                indices.push_back(indexed_a[j].second);
            }
            sort(indices.begin(), indices.end());
            bool valid = true;
            for (int j = 1; j < indices.size(); ++j) {
                if (indices[j] != indices[j-1] + 1) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                min_diff = current_diff;
                break;
            }
        }
    }
    
    if (min_diff != INT_MAX) {
        cout << min_diff << endl;
        return 0;
    }
    
    min_diff = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int left = i;
        int right = i + m - 1;
        if (right >= n) break;
        int current_min = a[i];
        int current_max = a[i];
        for (int j = i; j <= right; ++j) {
            current_min = min(current_min, a[j]);
            current_max = max(current_max, a[j]);
        }
        min_diff = min(min_diff, current_max - current_min);
    }
    
    cout << min_diff << endl;
    return 0;
}
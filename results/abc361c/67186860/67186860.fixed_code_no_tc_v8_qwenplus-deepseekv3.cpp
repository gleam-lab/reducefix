#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int window_size = n - k;
    int min_diff = INT_MAX;
    
    for (int i = 0; i + window_size - 1 < n; i++) {
        int current_diff = a[i + window_size - 1] - a[i];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    
    cout << min_diff << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // We remove exactly K elements, so we keep (n - k) elements.
    // The optimal way is to take a contiguous subarray of length (n - k)
    // from the sorted array, because any non-contiguous selection can be improved.
    long long min_diff = 1e18;
    int window_size = n - k;
    
    for (int i = 0; i + window_size - 1 < n; i++) {
        int j = i + window_size - 1;
        min_diff = min(min_diff, (long long)a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}
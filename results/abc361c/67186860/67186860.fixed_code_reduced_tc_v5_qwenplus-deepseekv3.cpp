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
    
    int min_diff = INT_MAX;
    for (int i = 0; i <= k; i++) {
        int left = i;
        int right = k - i;
        if (left + right > k) continue;
        if (left + right > n) continue;
        int current_diff = a[n - 1 - right] - a[left];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    cout << min_diff << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
    int min_diff = INT_MAX;
    for (int i = 0; i <= k; i++) {
        int current_window_min = a[i];
        int current_window_max = a[i + (n - k) - 1];
        min_diff = min(min_diff, current_window_max - current_window_min);
    }
    cout << min_diff << endl;
    return 0;
}
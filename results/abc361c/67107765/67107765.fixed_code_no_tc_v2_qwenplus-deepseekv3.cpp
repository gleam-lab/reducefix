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
        int j = i + (n - k) - 1;
        if (j >= n) break;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    cout << min_diff << endl;
    return 0;
}
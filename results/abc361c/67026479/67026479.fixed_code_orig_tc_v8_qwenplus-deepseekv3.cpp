#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int m = n - k;
    int min_diff = INT_MAX;
    for (int i = 0; i + m - 1 < n; ++i) {
        min_diff = min(min_diff, a[i + m - 1] - a[i]);
    }
    cout << min_diff << endl;
    return 0;
}
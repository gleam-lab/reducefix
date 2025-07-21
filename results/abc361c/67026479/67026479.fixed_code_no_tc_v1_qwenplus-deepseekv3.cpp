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
    int m = n - k;
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    int dmin = INT_MAX;
    for (int i = 0; i + m <= n; i++) {
        dmin = min(dmin, a[i + m - 1] - a[i]);
    }
    cout << dmin << endl;
    return 0;
}
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
    int dmin = INT_MAX;
    for (int i = 0; i + m - 1 < n; ++i) {
        dmin = min(dmin, a[i + m - 1] - a[i]);
    }
    cout << dmin << endl;
    return 0;
}
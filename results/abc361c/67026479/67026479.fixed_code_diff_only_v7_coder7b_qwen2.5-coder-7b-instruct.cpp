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

    long long dmin = INT_MAX;
    for (int i = 0; i <= n - k; ++i) {
        long long d = a[i + k - 1] - a[i];
        dmin = min(dmin, d);
    }

    cout << dmin << endl;
    return 0;
}
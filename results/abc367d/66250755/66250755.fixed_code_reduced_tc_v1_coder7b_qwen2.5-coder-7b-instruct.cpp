#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n);
    vector<int> t(m, 0);
    long long an = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];
    }

    for (int i = 0; i < 2 * n; ++i) {
        a[i] %= m;
        if (i >= n) {
            an += t[a[i - n]];
        }
        t[a[i]]++;
    }

    cout << an << endl;
    return 0;
}
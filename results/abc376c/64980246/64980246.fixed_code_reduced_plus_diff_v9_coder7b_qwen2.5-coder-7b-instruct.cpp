#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int x = -1;
    for (int i = 0, j = 0; i < n && j < n - 1; ++i) {
        if (a[i] <= b[j]) {
            x = a[i];
            break;
        } else
            ++j;
    }

    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
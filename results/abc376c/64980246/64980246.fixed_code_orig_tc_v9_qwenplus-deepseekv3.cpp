#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a) cin >> tt;
    for (auto &tt : b) cin >> tt;
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    int x = -1;
    int i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            ++i;
            ++j;
        } else {
            x = a[i];
            ++i;
        }
    }
    if (i < n) {
        x = a[i];
    }
    
    if (x == -1) {
        x = 1; // All toys can be placed in existing boxes, x can be any positive integer, smallest is 1
    }
    
    // Verify if x is sufficient by counting the number of toys that can't be placed in existing boxes
    // If more than one toy needs x, then it's impossible
    int count = 0;
    i = 0; j = 0;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            ++i;
            ++j;
        } else {
            ++count;
            if (count > 1) {
                cout << -1 << endl;
                return;
            }
            ++i;
        }
    }
    if (i < n) {
        ++count;
    }
    if (count > 1) {
        cout << -1 << endl;
        return;
    }
    
    cout << x << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
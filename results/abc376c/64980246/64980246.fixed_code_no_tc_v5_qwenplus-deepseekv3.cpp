#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &val : a) cin >> val;
    for (auto &val : b) cin >> val;
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    int i = 0, j = 0;
    int count = 0;
    int required_x = -1;
    
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            if (required_x == -1) {
                required_x = a[i];
                i++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (i < n) {
        if (required_x == -1) {
            required_x = a[i];
        } else {
            cout << -1 << endl;
            return;
        }
    }
    
    if (required_x == -1) {
        required_x = 1;  // all toys fit, but we need exactly N boxes, so x can be any >=1, smallest is 1
    }
    
    cout << required_x << endl;
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
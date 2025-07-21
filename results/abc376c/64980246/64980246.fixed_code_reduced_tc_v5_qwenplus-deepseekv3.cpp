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
    
    vector<int> matched_a(n, 0);
    vector<int> matched_b(n - 1, 0);
    
    int i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            matched_a[i] = 1;
            matched_b[j] = 1;
            i++;
            j++;
        } else {
            i++;
        }
    }
    
    int x = -1;
    for (int k = 0; k < n; ++k) {
        if (!matched_a[k]) {
            x = a[k];
            break;
        }
    }
    
    if (x == -1) {
        x = 1; // All toys can be placed in existing boxes, so x can be any size >= 1, but smallest is 1.
    }
    
    // Verify if x works
    vector<int> new_b = b;
    new_b.push_back(x);
    sort(new_b.begin(), new_b.end(), greater<int>());
    
    bool possible = true;
    i = 0, j = 0;
    while (i < n && j < n) {
        if (a[i] <= new_b[j]) {
            i++;
            j++;
        } else {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
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
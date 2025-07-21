#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (auto &tt : a) cin >> tt;
    for (auto &tt : b) cin >> tt;
    
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    
    multiset<ll> boxes(b.begin(), b.end());
    ll x = -1;
    bool possible = true;
    
    for (int i = 0; i < n; ++i) {
        auto it = boxes.lower_bound(a[i]);
        if (it != boxes.end()) {
            boxes.erase(it);
        } else {
            if (x == -1) {
                x = a[i];
            } else {
                possible = false;
                break;
            }
        }
    }
    
    if (possible) {
        cout << (x == -1 ? *min_element(b.begin(), b.end()) : x) << endl;
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
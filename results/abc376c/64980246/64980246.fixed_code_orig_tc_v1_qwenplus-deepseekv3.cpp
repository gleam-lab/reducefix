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
    
    multiset<int> boxes(b.begin(), b.end());
    int x = -1;
    
    for (int i = 0; i < n; ++i) {
        auto it = boxes.lower_bound(a[i]);
        if (it != boxes.end()) {
            boxes.erase(it);
        } else {
            if (x == -1) {
                x = a[i];
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (x != -1) {
        cout << x << endl;
    } else {
        // All toys fit in existing boxes, so the new box can be of size 1
        cout << 1 << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
    return 0;
}
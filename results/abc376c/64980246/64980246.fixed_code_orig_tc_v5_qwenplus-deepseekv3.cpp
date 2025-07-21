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
    vector<int> unmatched;
    
    for (int toy : a) {
        auto it = boxes.lower_bound(toy);
        if (it != boxes.end()) {
            boxes.erase(it);
        } else {
            unmatched.push_back(toy);
        }
    }
    
    if (unmatched.empty()) {
        cout << 1 << endl;
    } else if (unmatched.size() == 1) {
        cout << unmatched[0] << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
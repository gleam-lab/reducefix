#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 100005;
vector<int> a(N), b(M);

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    while (m--) {
        int x, k;
        cin >> x >> k;
        
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it == a.begin()) {
            cout << abs(*it - x) << '\n';
        } else if (it == a.end()) {
            cout << abs(*(it - 1) - x) << '\n';
        } else {
            int prev = *(it - 1), next = *it;
            if (k > 1 && k <= it - a.begin() + 1) {
                cout << abs(prev - x) << '\n';
            } else {
                cout << abs(next - x) << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
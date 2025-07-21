#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, q; cin >> n >> q;
    vi a(n), b(q), k(q);
    rep(i, n) cin >> a[i];
    rep(j, q) cin >> b[j] >> k[j];

    sort(a.begin(), a.end());

    rep(j, q) {
        int target = k[j] - 1; // Convert to zero-based index
        auto it = lower_bound(a.begin(), a.end(), b[j]);
        
        if (it == a.begin()) {
            cout << abs(*it - b[j]) << '\n';
        } else if (it == a.end()) {
            cout << abs(*(it - 1) - b[j]) << '\n';
        } else {
            int dist1 = abs(*it - b[j]);
            int dist2 = abs(*(it - 1) - b[j]);
            if (dist1 <= dist2 && target >= dist1 || target < dist2) {
                cout << dist1 << '\n';
            } else {
                cout << dist2 << '\n';
            }
        }
    }

    return 0;
}
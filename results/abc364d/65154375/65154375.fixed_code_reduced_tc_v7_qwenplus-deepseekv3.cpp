#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (q--) {
        ll b;
        int k;
        cin >> b >> k;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] < b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // left is the first position >= b
        int l = left - 1;
        int r = left;
        vector<ll> distances;
        while (distances.size() < k && (l >= 0 || r < n)) {
            if (l >= 0 && r < n) {
                if (abs(a[l] - b) <= abs(a[r] - b)) {
                    distances.push_back(abs(a[l] - b));
                    l--;
                } else {
                    distances.push_back(abs(a[r] - b));
                    r++;
                }
            } else if (l >= 0) {
                distances.push_back(abs(a[l] - b));
                l--;
            } else {
                distances.push_back(abs(a[r] - b));
                r++;
            }
        }
        cout << distances[k - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
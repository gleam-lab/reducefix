#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k, int n) {
    // We will use binary search on the answer (distance)
    ll low = 0, high = 2e8; // max possible distance is 2*1e8
    ll answer = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        // Find number of elements in [b-mid, b+mid]
        ll left = lower_bound(a, a + n, b - mid) - a;
        ll right = upper_bound(a, a + n, b + mid) - a;
        ll count = right - left;

        if (count >= k) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a, a + n);
    
    for (int i = 0; i < q; ++i) {
        ll b, k;
        cin >> b >> k;
        cout << query(b, k, n) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}
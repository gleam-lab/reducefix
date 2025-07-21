#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k, int n) {
    // We will use binary search on answer (distance)
    ll low = 0, high = 2e8; // max possible distance is 2*1e8
    ll result = -1;

    while (low <= high) {
        ll mid = (low + high) / 2;
        
        // Count how many elements are in [b-mid, b+mid]
        ll left = b - mid;
        ll right = b + mid;

        // Use lower_bound and upper_bound to count
        ll cnt = upper_bound(a, a + n, right) - lower_bound(a, a + n, left);
        
        if (cnt >= k) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a, a + N);

    for (int i = 0; i < Q; ++i) {
        ll b, k;
        cin >> b >> k;
        cout << query(b, k, N) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k, int n) {
    ll left = 0, right = 2e8;
    while (left < right) {
        ll mid = (left + right) / 2;
        // Find number of elements in a whose distance to b is <= mid
        int l = lower_bound(a, a + n, b - mid) - a;
        int r = upper_bound(a, a + n, b + mid) - a;
        if ((ll)r - l >= k)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    sort(a, a + N);
    
    for (int q = 0; q < Q; ++q) {
        ll b, k;
        cin >> b >> k;
        cout << query(b, k, N) << "\n";
    }
    
    return 0;
}
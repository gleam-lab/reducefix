#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search helper to find k-th smallest distance
ll query_kth_distance(ll b, int k, int n) {
    // We want to find the k-th smallest |a[i] - b|
    ll low = 0, high = 2e8; // Max possible distance is ~2*1e8
    ll answer = 0;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll count = 0;
        
        // For each a[i], find how many a[i] satisfy |a[i] - b| <= mid
        // This can be done using binary search on the sorted array
        count = upper_bound(a, a + n, b + mid) - lower_bound(a, a + n, b - mid);
        
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
    
    for (int j = 0; j < q; ++j) {
        ll b;
        int k;
        cin >> b >> k;
        cout << query_kth_distance(b, k, n) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}
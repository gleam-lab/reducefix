#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> A;

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k) {
    // We want to find the minimal d such that there are at least k points in A with |a_i - b| <= d
    
    ll low = 0, high = 2 * 1e8;
    ll result = -1;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        
        // Count number of elements in A where |a_i - b| <= mid
        ll count = upper_bound(A.begin(), A.end(), b + mid) - lower_bound(A.begin(), A.end(), b - mid);
        
        if (count >= k) {
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
    
    A.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    sort(A.begin(), A.end());
    
    for (int i = 0; i < Q; ++i) {
        ll b, k;
        cin >> b >> k;
        cout << query(b, k) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}
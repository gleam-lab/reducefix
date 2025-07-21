#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> A;

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k) {
    // We will find left bound and right bound such that exactly k elements are within [b - d, b + d]
    ll left = 0, right = 2e8;  // max possible distance is up to 2e8 (from constraints)
    while (left < right) {
        ll mid = (left + right) / 2;
        auto lb = lower_bound(A.begin(), A.end(), b - mid);
        auto ub = upper_bound(A.begin(), A.end(), b + mid);
        int count = ub - lb;
        if (count >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < Q; ++i) {
        ll b, k;
        cin >> b >> k;
        cout << query(b, k) << endl;
    }

    return 0;
}
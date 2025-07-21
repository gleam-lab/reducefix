#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> A;

// Binary search to find the k-th smallest distance from b
ll query(ll b, int k) {
    // Find the position where b would be inserted (to get closest elements)
    auto it = lower_bound(A.begin(), A.end(), b);
    
    // Use two pointers to simulate a heap-like behavior
    deque<int> left, right;
    
    // Initialize with nearby elements
    int i = it - A.begin() - 1;
    int j = it - A.begin();
    
    while (k--) {
        ll d_left = (i >= 0) ? abs(A[i] - b) : LLONG_MAX;
        ll d_right = (j < A.size()) ? abs(A[j] - b) : LLONG_MAX;
        
        if (d_left < d_right) {
            if (k == 0) return d_left;
            i--;
        } else {
            if (k == 0) return d_right;
            j++;
        }
    }
    return -1; // Should not reach here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        cout << query(b, k) << "\n";
    }
    
    return 0;
}
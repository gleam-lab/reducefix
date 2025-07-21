#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> A;

// Binary search to find k-th smallest distance from b
ll query(ll b, int k) {
    // Find the position where b would be inserted (first index >= b)
    int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
    
    int left = pos - 1;
    int right = pos;
    
    // Use a min heap to find k smallest distances
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    
    if (left >= 0) {
        pq.push({abs(A[left] - b), left});
    }
    if (right < A.size()) {
        pq.push({abs(A[right] - b), right});
    }
    
    ll result = 0;
    for (int i = 0; i < k; ++i) {
        auto [dist, idx] = pq.top();
        pq.pop();
        result = dist;
        
        int l_idx = idx - 1;
        int r_idx = idx + 1;
        
        if (A[idx] <= b && left >= 0) {
            if (l_idx >= 0 && (pos == idx || l_idx < pos)) {
                pq.push({abs(A[l_idx] - b), l_idx});
            }
        } else if (A[idx] >= b && right < A.size()) {
            if (r_idx < A.size() && (pos == idx || r_idx >= pos)) {
                pq.push({abs(A[r_idx] - b), r_idx});
            }
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    for (int i = 0; i < Q; ++i) {
        ll b;
        int k;
        cin >> b >> k;
        cout << query(b, k) << endl;
    }
    
    return 0;
}
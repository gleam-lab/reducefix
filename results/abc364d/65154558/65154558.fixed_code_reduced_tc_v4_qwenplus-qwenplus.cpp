#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> A;

// Binary search to find the k-th smallest distance from b
ll query(ll b, int k) {
    // Find the insertion point
    int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
    
    // Two pointers for the closest elements around b
    int l = pos - 1, r = pos;
    
    // Min heap to keep track of distances and their corresponding values
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    
    // Initially add the closest candidates
    if (l >= 0) pq.emplace(b - A[l], A[l]);
    if (r < A.size()) pq.emplace(A[r] - b, A[r]);
    
    ll result = 0;
    for (int i = 0; i < k; ++i) {
        auto [dist, val] = pq.top();
        pq.pop();
        result = dist;
        
        // Move left pointer if possible
        if (l > 0) {
            --l;
            pq.emplace(b - A[l], A[l]);
        }
        
        // Move right pointer if possible
        if (r + 1 < A.size()) {
            ++r;
            pq.emplace(A[r] - b, A[r]);
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
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        cout << query(b, k) << "\n";
    }
    
    return 0;
}
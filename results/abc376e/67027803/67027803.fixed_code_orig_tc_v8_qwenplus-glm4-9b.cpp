#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<ll>());  // Sort A in descending order
    priority_queue<ll, vector<ll>, greater<ll>> pq;  // Min-heap for smallest B_i
    ll sum = 0;
    
    for (int i = 0; i < n; i++) {
        if (A[i] == A[k-1]) {  // If A_i equals the current max A_k
            pq.push(B[i]);
            sum += B[i];
        } else if (!pq.empty() && pq.top() > B[i]) {
            // If the smallest B_i in the heap is larger than B_i of A_i
            sum = sum - pq.top() + B[i];
            pq.pop();
            pq.push(B[i]);
        }
    }
    
    // If the size of S is less than K, we need to take more elements from the heap
    while (k > pq.size()) {
        sum += pq.top();
        pq.pop();
    }
    
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        
        int left = 0;
        int right = N - 1;
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        
        priority_queue<pair<ll, int>> pq;
        int start = max(0, pos - k);
        int end = min(N - 1, pos + k);
        
        for (int i = start; i <= end; ++i) {
            pq.push({abs(A[i] - b), i});
            if (pq.size() > k) pq.pop();
        }
        
        while (pq.size() < k && start > 0) {
            start--;
            pq.push({abs(A[start] - b), start});
            if (pq.size() > k) pq.pop();
        }
        
        while (pq.size() < k && end < N - 1) {
            end++;
            pq.push({abs(A[end] - b), end});
            if (pq.size() > k) pq.pop();
        }
        
        cout << pq.top().first << '\n';
    }
    
    return 0;
}
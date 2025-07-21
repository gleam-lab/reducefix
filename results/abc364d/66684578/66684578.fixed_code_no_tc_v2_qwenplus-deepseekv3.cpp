#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    
    sort(A.begin(), A.end());
    
    rep(_, Q) {
        ll b, k;
        cin >> b >> k;
        
        int left = 0, right = N - 1;
        vector<ll> distances;
        distances.reserve(N);
        
        // Binary search to find the position where b would be inserted
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        
        int i = pos - 1, j = pos;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        
        if (i >= 0) pq.push({abs(A[i] - b), i});
        if (j < N) pq.push({abs(A[j] - b), j});
        
        ll result = 0;
        while (k--) {
            auto top = pq.top();
            pq.pop();
            result = top.first;
            int idx = top.second;
            
            if (idx > 0 && idx - 1 < i) {
                pq.push({abs(A[idx - 1] - b), idx - 1});
                i = idx - 1;
            }
            if (idx < N - 1 && idx + 1 > j) {
                pq.push({abs(A[idx + 1] - b), idx + 1});
                j = idx + 1;
            }
        }
        cout << result << '\n';
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        int left = 0, right = N - 1;
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        
        int l = pos - 1, r = pos;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        
        if (l >= 0) {
            pq.push({abs(A[l] - b), l});
        }
        if (r < N) {
            pq.push({abs(A[r] - b), r});
        }
        
        ll res = 0;
        for (int i = 0; i < k; ++i) {
            auto top = pq.top();
            pq.pop();
            res = top.first;
            int idx = top.second;
            if (idx > 0 && idx - 1 > l) {
                pq.push({abs(A[idx - 1] - b), idx - 1});
                l = idx - 1;
            }
            if (idx < N - 1 && idx + 1 < r) {
                pq.push({abs(A[idx + 1] - b), idx + 1});
                r = idx + 1;
            }
        }
        cout << res << "\n";
    }
    
    return 0;
}
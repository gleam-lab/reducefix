#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    
    sort(all(A));
    
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        
        int idx = lower_bound(all(A), b) - A.begin();
        
        int left = idx - 1;
        int right = idx;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        
        if (idx < N) {
            pq.push({abs(A[right] - b), right});
            right++;
        }
        if (left >= 0) {
            pq.push({abs(A[left] - b), left});
            left--;
        }
        
        ll ans = 0;
        while (k--) {
            auto top = pq.top();
            pq.pop();
            ans = top.first;
            
            int pos = top.second;
            if (pos > left + 1 && right < N) {
                pq.push({abs(A[right] - b), right});
                right++;
            } else if (pos < right - 1 && left >= 0) {
                pq.push({abs(A[left] - b), left});
                left--;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
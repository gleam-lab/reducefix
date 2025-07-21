#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2 * 1e5 + 5;

ll A[MAXN];

bool check(vector<ll>& B, vector<int>& S, int m, int k, ll sum, int& res) {
    int n = B.size();
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    
    // Initialize priority queue with initial values
    for(int i = 0; i < n; ++i) {
        if(B[i] > S[i]) {
            pq.push({B[i] - S[i], i});
        }
    }

    while(!pq.empty() && k >= pq.top().first) {
        auto [diff, idx] = pq.top(); pq.pop();
        diff -= S[idx];
        if(diff <= 0) continue;
        
        if(pq.empty()) break;
        auto [nextDiff, nextIdx] = pq.top();
        if(nextDiff > diff) {
            res += diff;
            pq.push({nextDiff - diff, nextIdx});
        } else {
            pq.pop();
            pq.push({nextDiff - diff, nextIdx});
            pq.push({diff - nextDiff, idx});
        }
        k -= diff;
    }

    return pq.empty() || k >= pq.top().first;
}

void solve() {
    int n, m; ll k; cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> A[i];
        k -= A[i];
    }

    vector<int> S(n);
    for(int i = 0; i < n; ++i) {
        S[i] = min(A[i], k / (n - i));
    }

    vector<ll> B(n);
    for(int i = 0; i < n; ++i) {
        B[i] = A[i] + S[i];
    }

    int res = 0;
    if(check(B, S, m, k, accumulate(A, A + n + 1, 0LL), res)) {
        cout << res << " ";
    } else {
        cout << "-1 ";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
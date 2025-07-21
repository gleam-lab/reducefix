#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(int n, int k, vector<int>& A, vector<int>& B) {
    vector<pair<int, int>> pairs(n);
    for(int i = 0; i < n; ++i) {
        pairs[i] = {A[i], B[i]};
    }

    sort(pairs.begin(), pairs.end());

    priority_queue<int, vector<int>, greater<>> pq;
    ll sum = 0;
    for(int i = 0; i < k; ++i) {
        pq.push(pairs[i].second);
        sum += pairs[i].second;
    }

    ll res = LLONG_MAX;
    for(int i = k; i < n; ++i) {
        int mx = pairs[i].first;
        res = min(res, (sum + pairs[i].second) * mx);

        if(pq.top() > pairs[i].second) {
            sum -= pq.top();
            sum += pairs[i].second;
            pq.pop();
            pq.push(pairs[i].second);
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> A(n), B(n);
        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < n; ++i) cin >> B[i];

        cout << solve(n, k, A, B) << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(int n, int k, vector<int>& a, vector<int>& b) {
    vector<pair<int, int>> ab(n);
    for(int i = 0; i < n; ++i)
        ab[i] = {a[i], b[i]};
    
    sort(ab.begin(), ab.end(), [&](auto& x, auto& y){
        if(x.first != y.first) return x.first > y.first;
        else return x.second < y.second;
    });

    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum = 0, res = LLONG_MAX;
    for(int i = 0; i < n; ++i) {
        pq.push(ab[i].second);
        sum += ab[i].second;
        if(i >= k-1) {
            res = min(res, (ll)ab[i].first * sum);
            if(pq.top() < ab[i-k+1].second) {
                sum -= pq.top();
                pq.pop();
                pq.push(ab[i-k+1].second);
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i)
            cin >> b[i];

        cout << solve(n, k, a, b) << '\n';
    }
    return 0;
}
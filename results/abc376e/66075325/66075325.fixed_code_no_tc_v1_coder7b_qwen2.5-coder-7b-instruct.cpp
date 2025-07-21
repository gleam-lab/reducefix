#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

ll solve(ll n, ll k, vector<ll>& A, vector<ll>& B) {
    vector<pair<ll, ll>> AB(n);
    for (ll i = 0; i < n; ++i) AB[i] = {A[i], B[i]};
    sort(AB.begin(), AB.end());
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0, res = LLONG_MAX;
    for (ll i = 0; i < n; ++i) {
        pq.push(AB[i].second);
        sum += AB[i].second;
        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == k) 
            res = min(res, sum * AB[i].first);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> A(n), B(n);
        for(auto &a : A) cin >> a;
        for(auto &b : B) cin >> b;
        cout << solve(n, k, A, B) << '\n';
    }
    return 0;
}
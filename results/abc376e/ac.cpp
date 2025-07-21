#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll K, const vector<ll> &A, const vector<ll> &B)
{
    vector<pair<ll, ll>> P;
    ll n = A.size();
    for(ll i = 0; i < n; ++i) P.push_back({A[i], B[i]});
    sort(P.begin(), P.end());
    priority_queue<ll, vector<ll>> que;
    ll sum = 0;
    for(ll i = 0; i < K; ++i)
    {
        que.push(P[i].second);
        sum += P[i].second;
    }

    ll ans = P[K - 1].first * sum;
    for(ll i = K; i < n; ++i)
    {
        if(P[i].second < que.top())
        {
            sum -= que.top();
            que.pop();
            que.push(P[i].second);
            sum += P[i].second;
            ans = min(ans, sum * P[i].first);
        }
    }

    return ans;
}

int main()
{
    ll T;
    cin >> T;
    for(ll i = 0; i < T; ++i)
    {
        ll N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        for(auto &a : A) cin >> a;
        for(auto &b : B) cin >> b;
        ll ans = f(K, A, B);
        cout << ans << endl;
    }
    return 0;
}
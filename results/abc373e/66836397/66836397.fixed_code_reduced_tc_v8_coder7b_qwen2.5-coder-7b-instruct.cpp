#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll midpoint(ll a, ll b) {
    return (a + b) / 2;
}

bool can_win(vector<ll>& A, ll M, ll K, ll i, ll x) {
    ll na = A[i] + x;
    ll r = upper_bound(begin(A), end(A), na) - begin(A);
    ll uppercnt = A.size() - r;
    ll rem = K - (x + accumulate(begin(A), end(A), 0LL));
    ll required_votes = (M - uppercnt) * (na + 1) - (r > 0 ? accumulate(begin(A) + r - 1, end(A), 0LL) : 0);
    return rem >= required_votes;
}

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> A(n);
    for (ll& a : A) cin >> a;
    sort(begin(A), end(A));

    vector<ll> C(n, -1);
    for (ll i = 0; i < n; ++i) {
        ll ok = K, ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = midpoint(ng, ok);
            if (can_win(A, m, K, i, mid)) ok = mid;
            else ng = mid;
        }
        if (can_win(A, m, K, i, ok)) C[i] = ok;
    }

    for (ll c : C) cout << c << " ";
    cout << endl;

    return 0;
}
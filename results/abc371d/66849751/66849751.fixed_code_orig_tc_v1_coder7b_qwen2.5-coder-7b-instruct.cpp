#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for(int i=0;i<n;++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];

    vector<pair<ll,ll>> ab(N);
    rep(i,N) ab[i] = {A[i]+B[i],A[i]-B[i]};
    sort(all(ab));

    vector<ll> prefix_sum(N+1);
    prefix_sum[0] = 0;
    rep(i,N) prefix_sum[i+1] = prefix_sum[i] + ab[i].first;

    int Q;
    cin >> Q;
    while(Q--) {
        ll L, R;
        cin >> L >> R;
        auto itL = lower_bound(all(ab),make_pair(L,LLONG_MIN));
        auto itR = upper_bound(all(ab),make_pair(R,LLONG_MAX));
        ll sum = prefix_sum[itR-ab.begin()] - prefix_sum[itL-ab.begin()];
        cout << sum << endl;
    }
    return 0;
}
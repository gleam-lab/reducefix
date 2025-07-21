#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define repr1(i,n) for(int i=n;i>=1;--i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug2(x,y) cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<endl
#define debug3(x,y,z) cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<", "<<#z<<": "<<z<<endl
#define chmax(x,y) ((x)=max((x),(y)))
#define chmin(x,y) ((x)=min((x),(y)))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> X(N), P(N);
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i] = (i > 0 ? P[i - 1] : 0) + p;
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int L, R;
        cin >> L >> R;
        auto it_L = lower_bound(all(X), L);
        auto it_R = upper_bound(all(X), R);
        int idx_L = it_L - X.begin();
        int idx_R = it_R - X.begin() - 1;
        if(idx_L == N || X[idx_L] > R) --idx_L;
        if(idx_R == -1 || X[idx_R] < L) ++idx_R;
        cout << (idx_R >= idx_L ? P[idx_R] - (idx_L > 0 ? P[idx_L - 1] : 0) : 0) << '\n';
    }

    return 0;
}
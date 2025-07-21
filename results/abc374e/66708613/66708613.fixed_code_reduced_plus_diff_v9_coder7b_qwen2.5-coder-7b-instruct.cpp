#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<cassert>
#include<random>
#include<set>
#include<map>
#include<cassert>
#include<unordered_map>
#include<bitset>
#include<numeric>
#include<algorithm>
using namespace std;
using ll = long long;
const int inf=1<<30;
const ll INF=1LL<<62;
using P = pair<ll,int>;
using PP = pair<int,P>; 
const ll MOD=998244353;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};

bool check(const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q, ll X, ll target) {
    for(int i = 0; i < A.size(); ++i) {
        ll cost = INF;
        for(ll s = 0; s <= B[i]; ++s) {
            ll t = (max(0LL, target - A[i] * s) + B[i] - 1) / B[i];
            cost = min(cost, s * P[i] + t * Q[i]);
        }
        for(ll t = 0; t <= A[i]; ++t) {
            ll s = (max(0LL, target - B[i] * t) + A[i] - 1) / A[i];
            cost = min(cost, t * Q[i] + s * P[i]);
        }
        if(cost == INF || cost > X) {
            return false;
        }
        X -= cost;
    }
    return true;
}

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    if(check(A, P, B, Q, X, 0)) {
        cout << 0 << endl;
        return 0;
    }

    ll ub = 1LL << 60, lb = 0;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        if(check(A, P, B, Q, X, mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    cout << lb << endl;
}
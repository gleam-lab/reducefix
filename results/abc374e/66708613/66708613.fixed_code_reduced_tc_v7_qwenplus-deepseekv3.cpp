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


int main(){
    int N;
    ll X;
    cin>>N>>X;
    vector<ll> A(N),P(N),B(N),Q(N);

    for(int i=0;i<N;i++){
        cin>>A[i]>>P[i]>>B[i]>>Q[i];
    }

    auto f=[&](ll x){
        ll total_cost = 0;
        for(int i=0;i<N;i++){
            ll min_cost = INF;
            // Case 1: Buy s of A[i] machines, then some B[i] machines
            for(ll s = 0; s <= 100; s++){ // Limiting s to a reasonable range to prevent excessive computation
                if (A[i] * s >= x) {
                    min_cost = min(min_cost, s * P[i]);
                    continue;
                }
                ll remaining = x - A[i] * s;
                ll t = (remaining + B[i] - 1) / B[i];
                t = max(t, 0LL);
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            // Case 2: Buy t of B[i] machines, then some A[i] machines
            for(ll t = 0; t <= 100; t++){ // Limiting t to a reasonable range
                if (B[i] * t >= x) {
                    min_cost = min(min_cost, t * Q[i]);
                    continue;
                }
                ll remaining = x - B[i] * t;
                ll s = (remaining + A[i] - 1) / A[i];
                s = max(s, 0LL);
                min_cost = min(min_cost, t * Q[i] + s * P[i]);
            }
            if (min_cost == INF) {
                return false;
            }
            total_cost += min_cost;
            if (total_cost > X) {
                return false;
            }
        }
        return total_cost <= X;
    };

    ll ub = 1LL << 60, lb = 0;
    while (ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        if (f(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    // Edge case: check if lb = 0 is achievable
    if (lb == 0) {
        bool can_achieve_zero = true;
        for (int i = 0; i < N; i++) {
            if (P[i] > X && Q[i] > X) {
                can_achieve_zero = false;
                break;
            }
        }
        if (!can_achieve_zero) {
            lb = -1;
        }
    }

    cout << max(0LL, lb) << endl;
}
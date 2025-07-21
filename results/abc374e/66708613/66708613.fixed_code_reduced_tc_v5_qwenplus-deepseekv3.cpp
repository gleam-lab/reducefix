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
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for(int i=0;i<N;i++){
        cin>>A[i]>>P[i]>>B[i]>>Q[i];
    }

    if (X == 0) {
        cout << 0 << endl;
        return 0;
    }

    auto f=[&](ll x){
        ll res = X;
        for(int i=0;i<N;i++){
            ll min_cost = INF;
            // We need to find s and t such that A[i]*s + B[i]*t >= x, while minimizing s*P[i] + t*Q[i]
            // Iterate over possible s and compute minimal t, and vice versa
            for(ll s=0; s <= min((x + A[i] - 1) / A[i], 100LL); s++){
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            for(ll t=0; t <= min((x + B[i] - 1) / B[i], 100LL); t++){
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            if (min_cost == INF) {
                return false;
            }
            res -= min_cost;
            if (res < 0) {
                return false;
            }
        }
        return res >= 0;
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
   
    cout << lb << endl;
}
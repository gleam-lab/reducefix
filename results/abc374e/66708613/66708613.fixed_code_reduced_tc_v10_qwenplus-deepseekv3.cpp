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

    if (X == 0) {
        cout << 0 << endl;
        return 0;
    }

    auto f=[&](ll x){
        ll res = X;
        for(int i=0;i<N;i++){
            ll val = INF;
            // Check all possible s (number of type A machines) up to the point where A[i]*s >= x or cost exceeds
            ll max_s = min((x + A[i] - 1) / A[i], B[i] + 1);
            for(ll s = 0; s <= max_s; ++s) {
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];
                if (t >= 0) {
                    val = min(val, s * P[i] + t * Q[i]);
                }
            }
            // Similarly for type B machines
            ll max_t = min((x + B[i] - 1) / B[i], A[i] + 1);
            for(ll t = 0; t <= max_t; ++t) {
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];
                if (s >= 0) {
                    val = min(val, t * Q[i] + s * P[i]);
                }
            }
            if(val == INF) return false;
            if (res < val) return false;
            res -= val;
        }
        return true;
    };

    ll lb = 0, ub = 1;
    // Find a suitable upper bound
    while (f(ub)) {
        ub *= 2;
    }

    // Binary search to find the maximum x where f(x) is true
    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        if (f(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
   
    cout << lb << endl;
    
}
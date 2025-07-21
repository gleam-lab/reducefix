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
        cin>>A[i]>> P[i]>> B[i] >> Q[i];
    }

    // Check if X is zero or negative, output 0 immediately
    if (X <= 0) {
        cout << 0 << endl;
        return 0;
    }

    auto f=[&](ll x){
        ll total_cost = 0;
        for(int i=0;i<N;i++){
            ll min_cost = INF;
            // Check for possible numbers of type A machines (s)
            // The upper bound for s can be derived from (x + A[i] - 1) / A[i] to cover all possible s values
            ll max_s = min((x + A[i] - 1) / A[i], B[i]);
            for(ll s=0; s <= max_s; s++){
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];
                if (t >= 0 && s * P[i] + t * Q[i] >= 0) {
                    min_cost = min(min_cost, s * P[i] + t * Q[i]);
                }
            }
            // Similarly for type B machines (t)
            ll max_t = min((x + B[i] - 1) / B[i], A[i]);
            for(ll t=0; t <= max_t; t++){
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];
                if (s >= 0 && t * Q[i] + s * P[i] >= 0) {
                    min_cost = min(min_cost, t * Q[i] + s * P[i]);
                }
            }
            if (min_cost == INF) {
                return false;
            }
            total_cost += min_cost;
            if (total_cost > X) {
                return false;
            }
        }
        return true;
    };

    ll lb = 0, ub = 1LL << 60;
    while (lb < ub) {
        ll mid = lb + (ub - lb + 1) / 2;
        if (f(mid)) {
            lb = mid;
        } else {
            ub = mid - 1;
        }
    }
   
    cout << lb << endl;
}
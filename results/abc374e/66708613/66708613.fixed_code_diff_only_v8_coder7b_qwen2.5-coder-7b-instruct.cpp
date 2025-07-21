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
        cin>>A[i]>> P[i]>> B[i] >> Q[i];
    }

    auto f=[&](ll x){
        // Check if it's possible to achieve at least processing capacity x with budget X
        ll remaining_budget = X;
        for(int i=0;i<N;i++){
            ll cost_to_achieve_capacity = INF;
            for(ll s=0;s<=B[i];s++){// Using machine s up to B[i] times
                ll t = (max(0LL, x - A[i]*s) + B[i] - 1) / B[i];
                cost_to_achieve_capacity = min(cost_to_achieve_capacity, s * P[i] + t * Q[i]);
            }

            for(ll t=0;t<=A[i];t++){// Using machine t up to A[i] times
                ll s = (max(0LL, x - B[i]*t) + A[i] - 1) / A[i];
                cost_to_achieve_capacity = min(cost_to_achieve_capacity, t * Q[i] + s * P[i]);
            }

            if(cost_to_achieve_capacity == INF){
                return false; // If we cannot achieve the required processing capacity with the given budget, return false.
            }
            remaining_budget -= cost_to_achieve_capacity;
        }
        return remaining_budget >= 0;
    };

    ll ub = 1LL << 60, lb = 0; // Initialize upper and lower bounds for binary search
    while(ub - lb > 1){
        ll mid = (ub + lb) / 2;
        if(f(mid)){ // Check if we can achieve at least processing capacity mid with budget X
            lb = mid;
        } else {
            ub = mid;
        }
    }
   
    cout<<lb<<endl; // Output the minimum processing capacity that can be achieved within budget X.
}
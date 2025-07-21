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
        // Check if it's possible to achieve at least processing capacity x with the given budget X.
        ll res=X;
        for(int i=0;i<N;i++){
            ll costS = (x + A[i] - 1) / A[i] * P[i]; // Cost of using machine S_i
            ll costT = (x + B[i] - 1) / B[i] * Q[i]; // Cost of using machine T_i
            res -= min(costS, costT); // Choose the cheaper option
            if(res < 0){
                return false; // If the budget runs out before reaching the required processing capacity, return false.
            }
        }
        return true;
    };

    ll ub=1LL<<60,lb=0; // Initialize upper bound to a large value and lower bound to 0
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        if(f(mid)){ // If achieving processing capacity mid is possible within budget X
            lb=mid;
        }else{
            ub=mid;
        }
    }
   
    cout<<lb<<endl; // Output the minimum processing capacity that can be achieved within budget X.
}
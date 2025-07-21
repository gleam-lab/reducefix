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
        // Check if we can achieve at least processing capacity x with the given budget X
        ll res=X;
        for(int i=0;i<N;i++){
            ll val=INF;
            for(ll s=0;s*B[i]<=x*s+A[i]*(x/s);s++){// Calculate cost for using machine S_i up to s units
                ll t=(x-A[i]*s+B[i]-1)/B[i];// Calculate remaining days needed for machine T_i
                val=min(val,s*P[i]+t*Q[i]); // Update the minimum cost to achieve capacity x
            }

            for(ll t=0;t*A[i]<=x*t+B[i]*(x/t);t++){// Calculate cost for using machine T_i up to t units
                ll s=(x-B[i]*t+A[i]-1)/A[i];// Calculate remaining days needed for machine S_i
                val=min(val,t*Q[i]+s*P[i]); // Update the minimum cost to achieve capacity x
            }
            if(val==INF){
                return false; // If we cannot achieve the processing capacity with the given budget, return false.
            }
            res-=val;
        }
        return res>=0;
    };

    ll ub=1LL<<60,lb=0;// Initialize upper and lower bounds for binary search
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        if(f(mid)){// If processing capacity mid can be reached within budget X
            lb=mid;
        }else{
            ub=mid;
        }
    }
   
    cout<<lb<<endl; // Output the minimum processing capacity that can be achieved within budget X.
}
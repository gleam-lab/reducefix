#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<bitset>
#include<numeric>
#include<algorithm>
using namespace std;
using ll = long long;
const int inf=1<<30;
const ll INF=1LL<<62;
using P = pair<ll,int>;

int main(){
    int N;
    ll X;
    cin>>N>>X;
    vector<ll> A(N),P(N),B(N),Q(N);
    
    for(int i=0;i<N;i++){
        cin>>A[i]>> P[i]>> B[i] >> Q[i];
    }

    auto f=[&](ll x){
        ll res=X;
        for(int i=0;i<N;i++){
            ll val=INF;
            // Try to use machine s from 0 to B[i]
            for(ll s=0;s<=B[i];s++){
                ll t=(max(0LL,x-A[i]*s)+B[i]-1)/B[i];
                val=min(val,s*P[i]+t*Q[i]);
            }
            // Try to use machine t from 0 to A[i]
            for(ll t=0;t<=A[i];t++){
                ll s=(max(0LL,x-B[i]*t)+A[i]-1)/A[i];
                val=min(val,t*Q[i]+s*P[i]);
            }
            if(val==INF){
                return false; // Cannot achieve the processing capacity with the given budget
            }
            res-=val;
        }
        return res>=0;
    };

    ll ub=1LL<<62, lb=0;
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        if(f(mid)){
            ub=mid;
        }else{
            lb=mid;
        }
    }
   
    cout<<lb<<endl;
}
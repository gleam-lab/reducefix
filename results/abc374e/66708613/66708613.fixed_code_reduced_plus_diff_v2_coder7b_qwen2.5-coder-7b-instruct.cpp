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

bool canAchieveProcessingCapacity(const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q, ll X, ll target) {
    for(int i=0;i<A.size();i++) {
        ll remainingBudget = X;
        ll machineCost = min(target / A[i], B[i]) * P[i];
        remainingBudget -= machineCost;
        
        if(remainingBudget < 0) continue;
        
        ll additionalTimeNeeded = (target % A[i] + B[i] - 1) / B[i];
        ll additionalMachineCost = additionalTimeNeeded * Q[i];
        
        if(machineCost + additionalMachineCost > remainingBudget) {
            return false;
        }
    }
    return true;
}

int main(){
    int N;
    ll X;
    cin>>N>>X;
    vector<ll> A(N),P(N),B(N),Q(N);
    
    for(int i=0;i<N;i++){
        cin>>A[i]>> P[i]>> B[i] >> Q[i];
    }

    ll left = 0, right = INF;

    while(left < right) {
        ll mid = left + (right - left) / 2;
        if(canAchieveProcessingCapacity(A, P, B, Q, X, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl; // Output the minimum processing capacity that can be achieved within budget X.
}
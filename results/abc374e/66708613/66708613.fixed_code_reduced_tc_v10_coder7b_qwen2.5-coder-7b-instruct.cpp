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

bool check(vector<ll>& A, vector<ll>& P, vector<ll>& B, vector<ll>& Q, ll X, ll target) {
    for (int i = 0; i < A.size(); ++i) {
        ll need = target;
        ll cost = INF;
        
        for (ll s = 0; s <= B[i]; ++s) {
            ll t = (need + A[i] * s - 1) / A[i];
            cost = min(cost, s * P[i] + t * Q[i]);
        }
        
        for (ll t = 0; t <= B[i]; ++t) {
            ll s = (need + B[i] * t - 1) / B[i];
            cost = min(cost, t * Q[i] + s * P[i]);
        }
        
        if (cost > X) return false;
    }
    return true;
}

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll left = 0, right = INF;
    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (check(A, P, B, Q, X, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
}
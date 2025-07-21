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
    for(int i = 0; i < A.size(); ++i) {
        ll total_cost = INF;
        for(ll s = 0; s <= B[i]; ++s) { // Using machine s up to B[i] times
            ll t = (max(0LL, target - A[i] * s) + B[i] - 1) / B[i];
            total_cost = min(total_cost, s * P[i] + t * Q[i]);
        }
        for(ll t = 0; t <= A[i]; ++t) { // Using machine t up to A[i] times
            ll s = (max(0LL, target - B[i] * t) + A[i] - 1) / A[i];
            total_cost = min(total_cost, t * Q[i] + s * P[i]);
        }
        if(total_cost == INF || total_cost > X) return false;
        X -= total_cost;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;

    vector<ll> A(N), P(N), B(N), Q(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll left = 0, right = X + 1;
    while(left < right) {
        ll mid = (left + right) / 2;
        if(check(A, P, B, Q, X, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
}
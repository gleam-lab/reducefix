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
    for(int i=0;i<A.size();i++) {
        ll need = max(0LL, target - A[i] * B[i]) / B[i] + max(0LL, target - B[i] * A[i]) / A[i];
        if (need * P[i] + ((need + B[i] - 1) / B[i]) * Q[i] > X) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);

    for(int i=0;i<N;i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    if(N == 0 || X == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll lb = 0, ub = INF;

    while(lb < ub) {
        ll mid = lb + (ub - lb) / 2;
        if(check(A, P, B, Q, X, mid)) {
            ub = mid;
        } else {
            lb = mid + 1;
        }
    }

    cout << lb << endl;
}
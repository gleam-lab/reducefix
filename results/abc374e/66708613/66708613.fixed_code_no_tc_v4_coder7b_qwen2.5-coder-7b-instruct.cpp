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

bool check(const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q, ll budget, ll target) {
    for (size_t i = 0; i < A.size(); ++i) {
        ll max_cost = INF;
        for (ll s = 0; s <= B[i]; ++s) {
            ll t = (target - A[i] * s + B[i] - 1) / B[i];
            max_cost = min(max_cost, s * P[i] + t * Q[i]);
        }
        if (max_cost > budget) {
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

    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll left = 0, right = INF;
    while (left < right) {
        ll mid = left + (right - left + 1) / 2;
        if (check(A, P, B, Q, X, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;

    return 0;
}
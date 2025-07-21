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

ll binary_search(ll l, ll r, function<bool(ll)> can_buy) {
    while (r - l > 1) {
        ll mid = l + (r - l) / 2;
        if (can_buy(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

bool can_achieve_capacity(ll capacity) {
    ll cost = 0;
    for (int i = 0; i < N; i++) {
        ll max_s = (max(0LL, capacity - A[i]) + B[i] - 1) / B[i];
        ll max_t = (max(0LL, capacity - B[i]) + A[i] - 1) / A[i];
        ll min_cost = min(max_s * P[i] + max_t * Q[i], max_t * Q[i] + max_s * P[i]);
        if (min_cost == INF) {
            return false; // Cannot achieve the capacity with any combination of machines
        }
        cost += min_cost;
    }
    return cost <= X;
}

int main() {
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll min_capacity = binary_search(0, INF, can_achieve_capacity);
    cout << min_capacity << endl;
    
    return 0;
}
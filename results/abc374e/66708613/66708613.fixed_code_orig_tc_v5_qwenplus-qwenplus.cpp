#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<cassert>
#include<random>
#include<set>
#include<map>
#include<unordered_map>
#include<bitset>
#include<numeric>
#include<algorithm>
using namespace std;
using ll = long long;
const int inf = 1 << 30;
const ll INF = 1LL << 62;
using P = pair<ll, int>;
using PP = pair<int, P>;
const ll MOD = 998244353;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Check if any step cannot be satisfied at all (i.e., both machines are more expensive than X)
    bool possible = true;
    for(int i = 0; i < N; i++) {
        if (P[i] > X && Q[i] > X) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << 0 << endl;
        return 0;
    }

    auto f = [&](ll x) {
        ll remaining = X;
        for(int i = 0; i < N; i++) {
            ll min_cost = INF;

            // Try buying s units of machine 1 and compute required t units of machine 2
            for(ll s = 0; s <= B[i]; s++) {
                ll needed = max(0LL, x - A[i] * s);
                ll t = (needed + B[i] - 1) / B[i]; // ceil division
                if(t >= 0 && t <= A[i]) { // Ensure within limits
                    ll cost = s * P[i] + t * Q[i];
                    min_cost = min(min_cost, cost);
                }
            }

            // Try buying t units of machine 2 and compute required s units of machine 1
            for(ll t = 0; t <= A[i]; t++) {
                ll needed = max(0LL, x - B[i] * t);
                ll s = (needed + A[i] - 1) / A[i]; // ceil division
                if(s >= 0 && s <= B[i]) { // Ensure within limits
                    ll cost = t * Q[i] + s * P[i];
                    min_cost = min(min_cost, cost);
                }
            }

            if (min_cost == INF) {
                return false;
            }
            remaining -= min_cost;
            if (remaining < 0) {
                return false;
            }
        }
        return true;
    };

    ll lb = 0, ub = 1LL << 60;
    while (lb < ub) {
        ll mid = (lb + ub + 1) / 2;
        if (f(mid)) {
            lb = mid;
        } else {
            ub = mid - 1;
        }
    }

    cout << lb << endl;
}
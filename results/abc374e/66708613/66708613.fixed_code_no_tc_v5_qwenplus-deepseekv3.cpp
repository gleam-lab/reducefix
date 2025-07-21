#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(){
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for(int i = 0; i < N; i++){
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    auto f = [&](ll x) {
        ll total_cost = 0;
        for(int i = 0; i < N; i++) {
            ll min_cost = INF;
            // Try all possible numbers of A machines (s) and calculate required B machines (t)
            // We limit s to x/A[i] + 1 to avoid excessive iterations
            ll max_s = min((x + A[i] - 1) / A[i], B[i]);
            for(ll s = 0; s <= max_s; s++) {
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];
                t = min(t, A[i]); // Can't use more than A[i] machines of type B
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            // Also try all possible numbers of B machines (t) and calculate required A machines (s)
            ll max_t = min((x + B[i] - 1) / B[i], A[i]);
            for(ll t = 0; t <= max_t; t++) {
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];
                s = min(s, B[i]); // Can't use more than B[i] machines of type A
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            if(min_cost == INF) return false;
            total_cost += min_cost;
            if(total_cost > X) return false;
        }
        return true;
    };

    ll left = 0, right = INF;
    while(left < right) {
        ll mid = (left + right + 1) / 2;
        if(f(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
   
    cout << left << endl;
}
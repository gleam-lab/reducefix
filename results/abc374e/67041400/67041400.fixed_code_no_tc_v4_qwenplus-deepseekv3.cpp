#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        ll best = X + 1;

        // Base cases
        ll all_S = (W + A[i] - 1) / A[i];
        ll all_T = (W + B[i] - 1) / B[i];
        best = min(best, P[i] * all_S);
        best = min(best, Q[i] * all_T);

        // Optimal mixed case
        if (A[i] != 0 && B[i] != 0) {
            ll x = (W * Q[i] + B[i] * P[i] - A[i] * Q[i] - B[i] * P[i]) / 
                   (A[i] * Q[i] + B[i] * P[i]);
            for (ll dx = -2; dx <= 2; dx++) {
                ll x_try = x + dx;
                if (x_try < 0 || x_try > all_S) continue;
                ll rem = W - A[i] * x_try;
                ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
                best = min(best, P[i] * x_try + Q[i] * y);
            }
        }

        total += best;
        if(total > X) return X+1;
    }
    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Calculate upper bound
    ll hi = 0;
    for(int i = 0; i < N; i++){
        ll max_A = X / P[i] * A[i];
        ll max_B = X / Q[i] * B[i];
        hi = max({hi, max_A, max_B});
    }
    hi += 1;  // To cover the case where W is exactly hi

    ll lo = 0;
    while(lo < hi){
        ll mid = lo + (hi - lo + 1) / 2;
        if(cost_for_W(N, mid, X, A, P, B, Q) <= X){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << "\n";
    return 0;
}
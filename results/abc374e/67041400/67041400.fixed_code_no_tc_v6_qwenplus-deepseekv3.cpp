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

        vector<ll> xs;
        // Possible optimal points
        if (A[i] > 0) {
            xs.push_back((W + A[i] - 1) / A[i]);  // All S
            if (B[i] > 0) {
                // Calculate x* when both A[i] and B[i] are positive
                long double x_star = (long double)W * Q[i] / ((long double)A[i]*Q[i] + (long double)B[i]*P[i]);
                ll xf = floor(x_star), xc = ceil(x_star);
                for (ll x : {xf-1, xf, xf+1, xc-1, xc, xc+1}) {
                    if (x >= 0) xs.push_back(x);
                }
            }
        }
        if (B[i] > 0) {
            xs.push_back(0);  // All T (x=0)
        }

        // Remove duplicates and sort
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        // Evaluate each candidate x
        for(ll x : xs) {
            if (x < 0) continue;
            
            ll rem = W - A[i] * x;
            ll y = 0;
            if (rem > 0) {
                if (B[i] == 0) {
                    // Can't produce remaining with B=0
                    continue;
                }
                y = (rem + B[i] - 1) / B[i];
            }
            
            ll cost = P[i] * x + Q[i] * y;
            if (cost < best) best = cost;
        }

        total += best;
        if(total > X) return X + 1;
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

    // Binary search bounds
    ll lo = 0;
    ll hi = 1;
    // Find a safe upper bound
    while (cost_for_W(N, hi, X, A, P, B, Q) <= X) {
        hi *= 2;
    }

    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (cost_for_W(N, mid, X, A, P, B, Q) <= X) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << "\n";
    return 0;
}
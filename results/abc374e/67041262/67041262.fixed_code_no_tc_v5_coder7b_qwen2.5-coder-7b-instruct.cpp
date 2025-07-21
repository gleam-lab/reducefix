#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the cost for a given production capacity W
ll min_cost(ll W, ll a, ll p, ll b, ll q){
    // Determine which machine type is more efficient based on cost per product processed
    ll best = LLONG_MAX;
    if ((q * a) <= (p * b)) {
        // Machine T is more efficient or equal in cost per product
        ll y0 = W / b;
        for (ll dy = 0; dy <= a && y0 >= dy; dy++){
            ll y = y0 - dy;
            ll rem = W - b * y;
            ll x = (rem <= 0 ? 0 : (rem + a - 1) / a);
            best = min(best, p * x + q * y);
        }
    } else {
        // Machine S is more efficient
        ll x0 = W / a;
        for (ll dx = 0; dx <= b && x0 >= dx; dx++){
            ll x = x0 - dx;
            ll rem = W - a * x;
            ll y = (rem <= 0 ? 0 : (rem + b - 1) / b);
            best = min(best, p * x + q * y);
        }
    }
    return best;
}

// Check function to determine if a given production capacity is feasible within the budget
bool can(ll W, int N, ll X,
         const vector<ll>& A, const vector<ll>& P,
         const vector<ll>& B, const vector<ll>& Q){
    ll sum = 0;
    for (int i = 0; i < N; i++){
        ll c = min_cost(W, A[i], P[i], B[i], Q[i]);
        sum += c;
        if (sum > X) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; i++){
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    ll lo = 0, hi = X; // Upper limit should be X, not arbitrarily large
    while (hi - lo > 1){
        ll mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}
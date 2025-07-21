#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the minimum cost to achieve at least W using machine i
ll min_cost(int W, ll A, ll P, ll B, ll Q) {
    long double ratio_A = static_cast<long double>(A) / P;
    long double ratio_B = static_cast<long double>(B) / Q;
    long double optimal_x = min(ratio_A, ratio_B) * W / (ratio_A * Q + ratio_B * P);
    ll x = static_cast<ll>(round(optimal_x));
    ll y = (W - A * x + B - 1) / B;
    return P * x + Q * y;
}

// Binary search to find the maximum achievable W within budget X
int binary_search(int N, ll X, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
    int lo = 0, hi = X;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        bool possible = true;
        for (int i = 0; i < N && possible; ++i) {
            if (min_cost(mid, A[i], P[i], B[i], Q[i]) > X) {
                possible = false;
            }
        }
        if (possible) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    int result = binary_search(N, X, A, P, B, Q);
    cout << result << "\n";

    return 0;
}
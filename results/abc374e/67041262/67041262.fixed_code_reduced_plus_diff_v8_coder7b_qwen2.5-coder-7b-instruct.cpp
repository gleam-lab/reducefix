#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long min_cost(long long W, long long a, long long p, long long b, long long q) {
    long long best = LLONG_MAX;
    if (p * b < q * a) {
        long long x0 = W / a;
        for (long long dx = 0; dx <= b && x0 >= dx; ++dx) {
            long long x = x0 - dx;
            long long rem = W - a * x;
            long long y = (rem <= 0 ? 0 : (rem + b - 1) / b);
            best = min(best, p * x + q * y);
        }
    } else {
        long long y0 = W / b;
        for (long long dy = 0; dy <= a && y0 >= dy; ++dy) {
            long long y = y0 - dy;
            long long rem = W - b * y;
            long long x = (rem <= 0 ? 0 : (rem + a - 1) / a);
            best = min(best, p * x + q * y);
        }
    }
    return best;
}

bool can(long long W, int N, long long X, const vector<long long>& A, const vector<long long>& P, const vector<long long>& B, const vector<long long>& Q) {
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        long long c = min_cost(W, A[i], P[i], B[i], Q[i]);
        sum += c;
        if (sum > X) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    long long lo = 0, hi = 1000000000000LL;
    while (hi - lo > 1) {
        long long mid = (lo + hi) / 2;
        if (can(mid, N, X, A, P, B, Q)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
    return 0;
}
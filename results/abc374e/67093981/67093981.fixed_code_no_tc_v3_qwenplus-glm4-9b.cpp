#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct{ int a, p, b, q; } p;
p A[100];
long long dp[100][10000];

int N, X;
long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * (long long)A[i].p * A[i].b;
}

bool f(int n) {
    long long ct = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i][0] > X) return false;
        ct += cost(i, n);
        if (ct > X) return false;
    }
    return true;
}

int main() {
    cin >> N >> X;

    for (int i = 0, a, b, p, q; i < N; i++) {
        cin >> a >> p >> b >> q;
        A[i] = {a, p, b, q};
        memset(dp[i], 0, sizeof(dp[i]));
        for (int j = 1; j <= a * b; j++) {
            dp[i][j] = min(dp[i][max(0, j - a)] + p, dp[i][max(0, j - b)] + q);
        }
        for (int j = 1; j <= a * b; j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i][j]);
        }
    }

    int lo = 0, hi = 1e9;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (f(mid)) lo = mid;
        else hi = mid - 1;
    }

    if (lo != hi && f(hi)) lo = hi;
    cout << lo << endl;

    return 0;
}
#include <iostream>
using namespace std;

typedef struct {
    int a, p, b, q;
} Product;

Product A[100];
long long dp[100][10000];

int N, X;

long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b), rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * A[i].p * A[i].b;
}

bool feasible(long long n) {
    long long total_cost = 0;
    for (int i = 0; i < N; i++) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    cin >> N >> X;

    for (int i = 0, a, b, p, q; i < N; i++) {
        cin >> a >> p >> b >> q;
        if (a * q < b * p) swap(a, b), swap(p, q);
        A[i] = {a, p, b, q};
        dp[i][0] = 0;
        for (int j = 1; j <= a * b; j++) {
            dp[i][j] = min(dp[i][max(0, j - a)] + p, dp[i][max(0, j - b)] + q);
        }
    }

    int low = 0, high = 1e9;
    while (high - low > 1) {
        int mid = (low + high) >> 1;
        if (feasible(mid)) low = mid;
        else high = mid - 1;
    }

    if (low != high && feasible(high)) low = high;
    cout << low << endl;

    return 0;
}
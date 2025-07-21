#include <iostream>
using namespace std;

typedef struct {int a, p, b, q;} item;
item A[100];
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

    for (int i = 0; i < N; i++) {
        cin >> A[i].a >> A[i].p >> A[i].b >> A[i].q;
        if (A[i].a * A[i].q < A[i].b * A[i].p) swap(A[i].a, A[i].b), swap(A[i].p, A[i].q);
        dp[i][0] = 0;
        for (int j = 1; j <= A[i].a * A[i].b; j++) {
            dp[i][j] = min(dp[i][max(0, j - A[i].a)] + A[i].p, dp[i][max(0, j - A[i].b)] + A[i].q);
        }
    }

    long long lo = 0, hi = 1e9;
    while (hi - lo > 1) {
        long long mid = (hi + lo) / 2;
        if (feasible(mid)) lo = mid;
        else hi = mid - 1;
    }

    if (lo != hi && feasible(lo + 1)) lo++;
    cout << lo << endl;

    return 0;
}
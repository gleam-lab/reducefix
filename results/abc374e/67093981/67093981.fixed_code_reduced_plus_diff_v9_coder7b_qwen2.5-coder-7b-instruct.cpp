#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct Product {
    int a, p, b, q;
};

Product A[100];
long long dp[100][10000];

int N, X;

long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * A[i].p * A[i].b;
}

bool feasible(long long n) {
    long long totalCost = 0;
    for (int i = 0; i < N; ++i) {
        totalCost += cost(i, n);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    cin >> N >> X;

    for (int i = 0; i < N; ++i) {
        cin >> A[i].a >> A[i].p >> A[i].b >> A[i].q;
        if (A[i].a * A[i].q < A[i].b * A[i].p) swap(A[i].a, A[i].b), swap(A[i].p, A[i].q);
        dp[i][0] = 0;
        for (int j = 1; j <= A[i].a * A[i].b; ++j) {
            dp[i][j] = min(dp[i][max(0, j - A[i].a)] + A[i].p, dp[i][max(0, j - A[i].b)] + A[i].q);
        }
    }

    int left = 0, right = INT_MAX;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (feasible(mid)) right = mid;
        else left = mid + 1;
    }

    cout << left << endl;

    return 0;
}
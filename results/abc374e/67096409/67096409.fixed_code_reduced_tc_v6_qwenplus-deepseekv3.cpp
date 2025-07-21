#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Package;
Package A[100];
long long dp[100][10000];

int N;
long long X;

long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * A[i].p * A[i].b;
}

bool feasible(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %lld", &N, &X);

    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};
        dp[i][0] = 0;
        for (int j = 1; j < a * b; ++j) {
            long long option1 = (j >= a) ? dp[i][j - a] + p : p;
            long long option2 = (j >= b) ? dp[i][j - b] + q : q;
            dp[i][j] = min(option1, option2);
        }
    }

    int low = 0, high = 1e9;
    int answer = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (feasible(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}
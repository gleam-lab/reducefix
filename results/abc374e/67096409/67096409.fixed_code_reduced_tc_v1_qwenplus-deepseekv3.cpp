#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Package;
Package packages[100];
long long dp[100][10000];

int N;
long long X;

long long cost(int i, long long n) {
    long long cycle = packages[i].a * packages[i].b;
    long long full_cycles = n / cycle;
    long long remaining = n % cycle;
    return dp[i][remaining] + full_cycles * packages[i].p * packages[i].b;
}

bool is_possible(long long n) {
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
        if ((long long)a * q > (long long)b * p) {
            swap(a, b);
            swap(p, q);
        }
        packages[i] = {a, p, b, q};

        dp[i][0] = 0;
        for (int j = 1; j < a * b; ++j) {
            long long option1 = (j >= a) ? dp[i][j - a] + p : p;
            long long option2 = (j >= b) ? dp[i][j - b] + q : q;
            dp[i][j] = min(option1, option2);
        }
    }

    long long low = 0, high = 1e18;
    long long answer = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (is_possible(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%lld\n", answer);
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Ingredient;
Ingredient A[100];
long long dp[100][10000];

int N, X;

// Compute the minimum cost to buy exactly 'n' units of ingredient i
long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    int rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * (long long)A[i].p * A[i].b;
}

// Check whether we can make 'n' portions within budget X
bool feasible(int n) {
    long long total = 0;
    for (int i = 0; i < N; ++i) {
        total += cost(i, n);
        if (total > X)
            return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        // Ensure (a,p) is better than (b,q) per unit cost
        if ((long long)a * q > (long long)b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};

        // Precompute dp[i][x]: min cost to get x units using this ingredient
        dp[i][0] = 0;
        for (int j = 1; j < a * b; ++j) {
            dp[i][j] = 1e18;
            if (j >= a) dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j >= b) dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search for max n such that feasible(n) == true
    int low = 0, high = 1e9;
    while (low < high) {
        int mid = (low + (long long)high + 1) >> 1;
        if (feasible(mid))
            low = mid;
        else
            high = mid - 1;
    }

    printf("%d\n", low);
}
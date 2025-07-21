#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Item;
Item A[100];
long long dp[100][10000];

int N, X;

// Calculate minimum cost to produce n units for item i
long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    int rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * (long long)A[i].p * A[i].b;
}

// Check if total X budget can afford 'n' units across all items
bool isPossible(int n) {
    long long total = 0;
    for (int i = 0; i < N; ++i) {
        total += cost(i, n);
        if (total > X) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        // Ensure that the better efficiency is first
        if (a * q < b * p) swap(a, b), swap(p, q);
        A[i] = {a, p, b, q};

        dp[i][0] = 0;
        for (int j = 1; j < a * b; ++j) {
            dp[i][j] = 1e18; // Initialize with large value
            if (j - a >= 0) dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j - b >= 0) dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    int low = 0, high = 1e9;
    int answer = 0;

    while (low <= high) {
        int mid = (low + (long long)high) >> 1;
        if (isPossible(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", answer);
}
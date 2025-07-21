#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Product;
Product A[100];
long long dp[100][10001];  // dp[i][j] is the minimal cost to produce j items of product i

int N, X;

long long cost(int i, int n) {
    int full_cycles = n / (A[i].a * A[i].b);
    int remainder = n % (A[i].a * A[i].b);
    return full_cycles * A[i].p * A[i].b + dp[i][remainder];
}

bool can_produce(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d %d", &A[i].a, &A[i].p, &A[i].b, &A[i].q);
        if (A[i].a * A[i].q < A[i].b * A[i].p) {
            swap(A[i].a, A[i].b);
            swap(A[i].p, A[i].q);
        }
        // Initialize DP for product i
        dp[i][0] = 0;
        for (int j = 1; j <= A[i].a * A[i].b; ++j) {
            long long option1 = (j >= A[i].a) ? dp[i][j - A[i].a] + A[i].p : A[i].q;
            long long option2 = (j >= A[i].b) ? dp[i][j - A[i].b] + A[i].q : A[i].p;
            dp[i][j] = min(option1, option2);
        }
    }

    int low = 0, high = X;
    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_produce(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", answer);

    return 0;
}
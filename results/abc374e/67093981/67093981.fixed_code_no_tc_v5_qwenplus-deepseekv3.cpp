#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10001]; // Increased size to handle up to a*b

int N, X;

long long cost(int i, int n) {
    long long cycle = A[i].a * A[i].b;
    long long full_cycles = n / cycle;
    long long rem = n % cycle;
    return full_cycles * A[i].p * A[i].b + dp[i][rem];
}

bool f(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; i++) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};
        
        // Initialize DP for this item type
        for (int j = 1; j <= A[i].a * A[i].b; j++) {
            long long option1 = (j >= A[i].a) ? dp[i][j - A[i].a] + A[i].p : A[i].p;
            long long option2 = (j >= A[i].b) ? dp[i][j - A[i].b] + A[i].q : A[i].q;
            dp[i][j] = min(option1, option2);
        }
    }

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", lo);

    return 0;
}
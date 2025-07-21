#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Product;
Product products[100];
long long dp[100][10000]; // dp[i][j] will store the cost to produce j+1 items of product i

int N, X;

long long cost(int i, int n) {
    if (n == 0) return 0;
    int cycle = products[i].a * products[i].b;
    long long full_cycles = n / cycle;
    int remainder = n % cycle;
    return full_cycles * products[i].p * products[i].b + dp[i][remainder - 1];
}

bool can_produce(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        total_cost += cost(i, n);
        if (total_cost > X) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);
    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }
        products[i] = {a, p, b, q};
        int cycle = a * b;
        dp[i][0] = min(p, q);
        for (int j = 1; j < cycle; ++j) {
            long long cost_a = (j >= a) ? dp[i][j - a] + p : p;
            long long cost_b = (j >= b) ? dp[i][j - b] + q : q;
            dp[i][j] = min(cost_a, cost_b);
        }
    }

    int lo = 0, hi = 1e9;
    int answer = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (can_produce(mid)) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    printf("%d\n", answer);

    return 0;
}
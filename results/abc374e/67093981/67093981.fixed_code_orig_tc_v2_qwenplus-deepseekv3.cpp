#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Item;
Item items[100];
long long dp[100][10001]; // dp[i][j] = min cost to produce j items of type i

int N, X;

long long compute_cost(int i, int n) {
    int a = items[i].a;
    int b = items[i].b;
    int p = items[i].p;
    int q = items[i].q;
    long long full_cycles = n / (a * b);
    int remainder = n % (a * b);
    return full_cycles * p * b + dp[i][remainder];
}

bool can_produce(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        total_cost += compute_cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        if (a * q > b * p) {
            swap(a, b);
            swap(p, q);
        }
        items[i] = {a, p, b, q};
        
        // Initialize DP for this item type
        dp[i][0] = 0;
        for (int j = 1; j <= a * b; ++j) {
            long long cost_a = (j >= a) ? dp[i][j - a] + p : q;
            long long cost_b = (j >= b) ? dp[i][j - b] + q : p;
            dp[i][j] = min(cost_a, cost_b);
        }
    }

    int low = 0;
    int high = 1e9;
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
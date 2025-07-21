#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Product;
Product products[100];
long long dp[100][10001];  // dp[i][j] = min cost to buy j items using product i

int N, X;

long long calculate_cost(int i, int n) {
    long long full_cycles = n / (products[i].a * products[i].b);
    long long remaining = n % (products[i].a * products[i].b);
    return full_cycles * products[i].p * products[i].b + dp[i][remaining];
}

bool is_possible(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; i++) {
        total_cost += calculate_cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        products[i] = {a, p, b, q};
        
        // Initialize DP for this product
        for (int j = 1; j <= 10000; j++) {
            long long option1 = (j >= a) ? dp[i][j - a] + p : (long long)1e18;
            long long option2 = (j >= b) ? dp[i][j - b] + q : (long long)1e18;
            dp[i][j] = min(option1, option2);
        }
    }

    int low = 0, high = X;
    int answer = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (is_possible(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}
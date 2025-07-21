#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int a, p, b, q;
};

Item items[100];
long long dp[100][10000];

int N, X;

long long cost(int i, int n) {
    long long d = n / (items[i].a * items[i].b);
    long long rem = n % (items[i].a * items[i].b);
    return dp[i][rem] + d * items[i].p * items[i].b;
}

bool feasible(long long mid) {
    long long totalCost = 0;
    for (int i = 0; i < N; ++i) {
        totalCost += cost(i, mid);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d %d", &items[i].a, &items[i].p, &items[i].b, &items[i].q);
        if (items[i].a * items[i].q < items[i].b * items[i].p)
            swap(items[i].a, items[i].b), swap(items[i].p, items[i].q);
        dp[i][0] = 0;
        for (int j = 1; j < items[i].a * items[i].b; ++j) {
            dp[i][j] = min(dp[i][max(0, j - items[i].a)] + items[i].p, dp[i][max(0, j - items[i].b)] + items[i].q);
        }
    }

    int low = 0, high = 1e9;
    while (high - low > 1) {
        int mid = (low + high) >> 1;
        if (feasible(mid)) low = mid;
        else high = mid - 1;
    }

    if (low != high && feasible(low + 1)) low++;
    printf("%d\n", low);

    return 0;
}
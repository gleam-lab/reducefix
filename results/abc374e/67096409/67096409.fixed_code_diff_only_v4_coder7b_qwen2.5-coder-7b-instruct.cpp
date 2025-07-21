#include <iostream>
using namespace std;

typedef struct { int a, p, b, q; } item;
item items[100];
long long dp[100][10000];

int N, X;

// Calculate the minimum cost to achieve at least 'n' units of item 'i'
long long cost(int i, int n) {
    long long d = n / (items[i].a * items[i].b), rem = n % (items[i].a * items[i].b);
    return dp[i][rem] + d * items[i].p * items[i].b;
}

// Check if it's possible to achieve exactly 'n' units with the current budget
bool isPossible(int n) {
    long long totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += cost(i, n);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        cin >> items[i].a >> items[i].p >> items[i].b >> items[i].q;
        if (items[i].a * items[i].q < items[i].b * items[i].p)
            swap(items[i].a, items[i].b), swap(items[i].p, items[i].q);
        dp[i][0] = 0;
        for (int j = 1; j <= items[i].a * items[i].b; j++) {
            dp[i][j] = min(dp[i][max(0, j - items[i].a)] + items[i].p, dp[i][max(0, j - items[i].b)] + items[i].q);
        }
    }

    int low = 0, high = 1e9;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) low = mid;
        else high = mid - 1;
    }

    if (low != high && isPossible(low + 1)) low++;
    cout << low << endl;

    return 0;
}
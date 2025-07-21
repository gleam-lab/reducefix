#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Product {
    int a, p, b, q;
};

long long dp[100][10000];

int N, X;

long long cost(const vector<Product>& products, int i, int n) {
    long long d = n / (products[i].a * products[i].b);
    long long rem = n % (products[i].a * products[i].b);
    return dp[i][rem] + d * products[i].p * products[i].b;
}

bool feasible(const vector<Product>& products, int n) {
    long long totalCost = 0;
    for (int i = 0; i < N; ++i) {
        totalCost += cost(products, i, n);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    cin >> N >> X;

    vector<Product> products(N);
    for (int i = 0; i < N; ++i) {
        cin >> products[i].a >> products[i].p >> products[i].b >> products[i].q;
        if (products[i].a * products[i].q < products[i].b * products[i].p) {
            swap(products[i].a, products[i].b);
            swap(products[i].p, products[i].q);
        }
        dp[i][0] = 0;
        for (int j = 1; j <= products[i].a * products[i].b; ++j) {
            dp[i][j] = min(dp[i][max(0, j - products[i].a)] + products[i].p, dp[i][max(0, j - products[i].b)] + products[i].q);
        }
    }

    int low = 0, high = INT_MAX;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (feasible(products, mid)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    cout << low - 1 << endl;

    return 0;
}
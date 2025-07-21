#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Item {
    int a, p, b, q;
};

int N, X;

long long cost(const vector<Item>& items, int i, int n) {
    int a = items[i].a, b = items[i].b, p = items[i].p, q = items[i].q;
    long long d = n / (a * b), rem = n % (a * b);
    return dp[i][rem] + d * p * b;
}

bool feasible(const vector<Item>& items, const vector<vector<long long>>& dp, int mid) {
    long long totalCost = 0;
    for (int i = 0; i < N; ++i) {
        totalCost += cost(items, i, mid);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    cin >> N >> X;
    vector<Item> items(N);
    vector<vector<long long>> dp(N, vector<long long>(10001, LLONG_MAX));

    for (int i = 0; i < N; ++i) {
        cin >> items[i].a >> items[i].p >> items[i].b >> items[i].q;
        if (items[i].a * items[i].q < items[i].b * items[i].p) {
            swap(items[i].a, items[i].b);
            swap(items[i].p, items[i].q);
        }
        dp[i][0] = 0;
        for (int j = 1; j <= items[i].a * items[i].b; ++j) {
            dp[i][j] = min(dp[i][max(0, j - items[i].a)] + items[i].p, dp[i][max(0, j - items[i].b)] + items[i].q);
        }
    }

    int lo = 0, hi = 1e9;
    while (hi - lo > 1) {
        int mid = (hi + lo) >> 1;
        if (feasible(items, dp, mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    if (lo != hi && feasible(items, dp, hi)) {
        lo = hi;
    }
    cout << lo << endl;

    return 0;
}
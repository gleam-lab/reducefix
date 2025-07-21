#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int a, p, b, q;
};

long long dp[105][10005];

int N, X;

long long cost(const vector<Item>& items, int i, int n) {
    long long d = n / (items[i].a * items[i].b);
    long long rem = n % (items[i].a * items[i].b);
    return dp[i][rem] + d * items[i].p * items[i].b;
}

bool feasible(const vector<Item>& items, int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        total_cost += cost(items, i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int binary_search(const vector<Item>& items) {
    int lo = 0, hi = 1e9;
    while (hi - lo > 1) {
        int mid = (hi + lo) >> 1;
        if (feasible(items, mid)) lo = mid;
        else hi = mid - 1;
    }
    if (lo != hi && feasible(items, lo + 1)) lo++;
    return lo;
}

int main() {
    cin >> N >> X;
    vector<Item> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].a >> items[i].p >> items[i].b >> items[i].q;
        if (items[i].a * items[i].q < items[i].b * items[i].p) swap(items[i].a, items[i].b), swap(items[i].p, items[i].q);
        dp[i][0] = 0;
        for (int j = 1; j <= items[i].a * items[i].b; ++j) {
            dp[i][j] = min(dp[i][max(0, j - items[i].a)] + items[i].p, dp[i][max(0, j - items[i].b)] + items[i].q);
        }
    }

    cout << binary_search(items) << endl;
    return 0;
}
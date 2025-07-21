#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int a, p, b, q;
};

vector<Item> items;
vector<vector<long long>> dp;

long long cost(int i, int n) {
    long long d = n / (items[i].a * items[i].b), rem = n % (items[i].a * items[i].b);
    return dp[i][rem] + d * items[i].p * items[i].b;
}

bool canAchieve(long long x) {
    vector<long long> current(items.size(), 0);
    for (int i = 0; i < items.size(); ++i) {
        for (int j = x; j >= 0; --j) {
            for (int k = 0; k <= items[i].a * items[i].b; ++k) {
                if (current[i] + cost(i, j - k) <= x) {
                    dp[i][k] = min(dp[i][k], current[i] + cost(i, j - k));
                } else {
                    dp[i][k] = dp[i][k];
                }
            }
            current[i] += dp[i][0];
        }
    }
    return current.back() <= x;
}

int main() {
    int n, x;
    cin >> n >> x;
    items.resize(n);
    dp.resize(n, vector<long long>(n * n + 1, LLONG_MAX));

    for (int i = 0; i < n; ++i) {
        cin >> items[i].a >> items[i].p >> items[i].b >> items[i].q;
        if (items[i].a * items[i].q > items[i].b * items[i].p) swap(items[i].a, items[i].b), swap(items[i].p, items[i].q);
        dp[i][0] = 0;
        for (int j = 1; j <= items[i].a * items[i].b; ++j) {
            dp[i][j] = min(dp[i][max(0, j - items[i].a)] + items[i].p, dp[i][max(0, j - items[i].b)] + items[i].q);
        }
    }

    long long low = 0, high = x;
    while (low < high) {
        long long mid = (low + high) / 2;
        if (canAchieve(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;
    return 0;
}
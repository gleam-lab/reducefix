#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Item {
    int a, p, b, q;
};

bool canMeetCost(const vector<Item>& items, int X, int target) {
    vector<vector<long long>> dp(items.size(), vector<long long>(target + 1, LLONG_MAX));
    
    for (int i = 0; i <= target; ++i) {
        if (i >= items[0].a * items[0].b) {
            dp[0][i] = min(dp[0][i], (i / (items[0].a * items[0].b)) * items[0].p * items[0].b + dp[0][i % (items[0].a * items[0].b)]);
        } else {
            dp[0][i] = dp[0][i % (items[0].a * items[0].b)];
        }
    }

    for (int i = 1; i < items.size(); ++i) {
        for (int j = 0; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= items[i].a * items[i].b) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - items[i].a * items[i].b] + (j / (items[i].a * items[i].b)) * items[i].p * items[i].b);
            }
            if (j >= items[i].b * items[i].a) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - items[i].b * items[i].a] + (j / (items[i].b * items[i].a)) * items[i].q * items[i].a);
            }
        }
    }

    return dp.back()[target] <= X;
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<Item> items(N);
    for (auto& item : items) {
        cin >> item.a >> item.p >> item.b >> item.q;
        if (item.a * item.q < item.b * item.p) swap(item.a, item.b), swap(item.p, item.q);
    }

    int low = 0, high = INT_MAX;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canMeetCost(items, X, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;
    return 0;
}
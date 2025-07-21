#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int a, p, b, q;
};

long long dp[100][10000];

bool canMeetCost(const vector<Item>& items, int X, int target) {
    long long currentCost = 0;
    for (const auto& item : items) {
        int units = target / (item.a * item.b);
        int remainder = target % (item.a * item.b);
        currentCost += dp[item.a][remainder] + units * item.p * item.b;
        if (currentCost > X) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<Item> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].a >> items[i].p >> items[i].b >> items[i].q;
        if (items[i].a * items[i].q < items[i].b * items[i].p) {
            swap(items[i].a, items[i].b);
            swap(items[i].p, items[i].q);
        }
        dp[items[i].a][0] = 0;
        for (int j = 1; j <= items[i].a * items[i].b; ++j) {
            dp[items[i].a][j] = min(dp[items[i].a][max(0, j - items[i].a)] + items[i].p,
                                    dp[items[i].a][max(0, j - items[i].b)] + items[i].q);
        }
    }

    int low = 0, high = 1e9;
    while (low < high) {
        int mid = (low + high) / 2;
        if (canMeetCost(items, X, mid)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    cout << low - 1 << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Item {
    int a, p, b, q;
};

long long cost(const vector<Item>& items, int i, int n) {
    int d = n / (items[i].a * items[i].b);
    int rem = n % (items[i].a * items[i].b);
    return d * items[i].p * items[i].b + items[i].dp[rem];
}

bool feasible(const vector<Item>& items, int X, int mid) {
    long long totalCost = 0;
    for (const auto& item : items) {
        totalCost += cost(items, item.a, mid);
        if (totalCost > X) return false;
    }
    return true;
}

int binarySearch(vector<Item>& items, int X, int low, int high) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (feasible(items, X, mid)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low - 1;
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<Item> items(N);
    for (auto& item : items) {
        cin >> item.a >> item.p >> item.b >> item.q;
        if (item.a * item.q < item.b * item.p) swap(item.a, item.b), swap(item.p, item.q);
        item.dp.resize(item.a * item.b + 1, INT_MAX);
        item.dp[0] = 0;
        for (int j = 1; j <= item.a * item.b; ++j) {
            item.dp[j] = min(j >= item.a ? item.dp[j - item.a] + item.p : INT_MAX,
                             j >= item.b ? item.dp[j - item.b] + item.q : INT_MAX);
        }
    }

    cout << binarySearch(items, X, 0, 1e9) << endl;
    return 0;
}
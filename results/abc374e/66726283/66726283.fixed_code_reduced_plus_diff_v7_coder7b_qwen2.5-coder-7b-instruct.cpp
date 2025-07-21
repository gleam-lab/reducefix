#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int a, p, b, q;
};

bool check(const vector<Item>& items, int x, int mid) {
    vector<int> c(items.size() + 1, INT_MAX);

    for (int i = 1; i <= items.size(); ++i) {
        const auto& item = items[i - 1];
        for (int j = 0; j <= item.b; ++j) {
            c[i] = min(c[i], j * item.p + item.q * ((mid - j * item.a + item.b - 1) / item.b));
        }
        for (int j = 0; j <= item.b; ++j) {
            c[i] = min(c[i], j * item.q + item.p * ((mid - j * item.b + item.a - 1) / item.a));
        }
    }

    int totalCost = 0;
    for (int cost : c) {
        if (cost == INT_MAX) return false;
        totalCost += cost;
    }

    return totalCost <= x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].a >> items[i].p >> items[i].b >> items[i].q;
    }

    int left = 1, right = x;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(items, x, mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << left - 1 << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int a, p, b, q;
};

bool operator<(const Item& lhs, const Item& rhs) {
    return lhs.a * rhs.b < rhs.a * lhs.b;
}

long long cost(const vector<Item>& items, int i, int n) {
    long long d = n / (items[i].a * items[i].b), rem = n % (items[i].a * items[i].b);
    return d * items[i].p * items[i].b + items[i].dp[rem];
}

bool feasible(const vector<Item>& items, int X, int n) {
    long long totalCost = 0;
    for (int i = 0; i < items.size(); ++i) {
        totalCost += cost(items, i, n);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<Item> items(N);
    for (auto& item : items) {
        cin >> item.a >> item.p >> item.b >> item.q;
        if (item.a * item.q < item.b * item.p) swap(item.a, item.b), swap(item.p, item.q);
        item.dp.resize(item.a * item.b + 1, LLONG_MAX);
        item.dp[0] = 0;
        for (int j = 1; j <= item.a * item.b; ++j) {
            if (j >= item.a) item.dp[j] = min(item.dp[j], item.dp[j - item.a] + item.p);
            if (j >= item.b) item.dp[j] = min(item.dp[j], item.dp[j - item.b] + item.q);
        }
    }

    sort(items.begin(), items.end());

    int low = 0, high = 1e9;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (feasible(items, X, mid)) low = mid;
        else high = mid;
    }

    if (feasible(items, X, low + 1)) low++;
    cout << low << endl;

    return 0;
}
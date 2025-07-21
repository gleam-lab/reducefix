#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Product {
    int a, p, b, q;
};

long long dp[100][10000];

bool canAchieve(long long target, const vector<Product>& products, int X) {
    for (const auto& prod : products) {
        int totalCost = 0;
        for (int rem = 0; rem <= target; ++rem) {
            int fullSets = rem / (prod.a * prod.b);
            int remainingItems = rem % (prod.a * prod.b);
            totalCost += fullSets * prod.p * prod.b + dp[prod.a * prod.b][remainingItems];
            if (totalCost > X) break;
        }
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<Product> products(N);
    for (auto& prod : products) {
        cin >> prod.a >> prod.p >> prod.b >> prod.q;
        if (prod.a * prod.q < prod.b * prod.p) swap(prod.a, prod.b), swap(prod.p, prod.q);
        dp[prod.a * prod.b][0] = 0;
        for (int j = 1; j <= prod.a * prod.b; ++j) {
            dp[prod.a * prod.b][j] = min(dp[prod.a * prod.b][max(0, j - prod.a)] + prod.p,
                                        dp[prod.a * prod.b][max(0, j - prod.b)] + prod.q);
        }
    }

    int low = 0, high = 1e9;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canAchieve(mid, products, X)) low = mid + 1;
        else high = mid;
    }

    cout << low - 1 << endl;
    return 0;
}
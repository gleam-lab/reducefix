#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Product {
    int a, p, b, q;
};

bool canPurchase(const vector<Product>& products, int X, int N) {
    long long totalCost = 0;
    for (const auto& product : products) {
        int numUnits = X / (product.a * product.b);
        int remainder = X % (product.a * product.b);
        totalCost += numUnits * product.p * product.b + dp[product.a][product.b][remainder];
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<Product> products(N);
    for (auto& product : products) {
        cin >> product.a >> product.p >> product.b >> product.q;
        if (product.a * product.q < product.b * product.p) swap(product.a, product.b), swap(product.p, product.q);
        dp[product.a][product.b].resize(product.a * product.b + 1);
        dp[product.a][product.b][0] = 0;
        for (int i = 1; i <= product.a * product.b; ++i) {
            dp[product.a][product.b][i] = min(dp[product.a][product.b][max(0, i - product.a)] + product.p, dp[product.a][product.b][max(0, i - product.b)] + product.q);
        }
    }

    int low = 0, high = 1e9;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canPurchase(products, mid, N)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;
    return 0;
}
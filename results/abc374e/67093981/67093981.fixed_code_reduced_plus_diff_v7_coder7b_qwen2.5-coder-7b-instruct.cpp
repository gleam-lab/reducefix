#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Product {
    int a, p, b, q;
};

long long cost(const vector<Product>& products, int i, int n) {
    long long d = n / (products[i].a * products[i].b);
    long long rem = n % (products[i].a * products[i].b);
    return d * products[i].p * products[i].b + products[i].dp[rem];
}

bool feasible(const vector<Product>& products, int X) {
    long long total_cost = 0;
    for (const auto& product : products) {
        total_cost += cost(products, product.a * product.b - 1, product.a * product.b);
        if (total_cost > X) return false;
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
        product.dp.resize(product.a * product.b + 1, 0);
        for (int j = 1; j <= product.a * product.b; ++j) {
            product.dp[j] = min(product.dp[max(0, j - product.a)] + product.p, product.dp[max(0, j - product.b)] + product.q);
        }
    }

    int left = 0, right = 1e9;
    while (left < right) {
        int mid = (left + right) / 2;
        if (feasible(products, X)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
    return 0;
}
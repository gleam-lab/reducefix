#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    int a, p, b, q;
} Product;

vector<Product> A;
long long dp[100][10000];

int N, X;

long long cost(int n) {
    long long sum = 0;
    for (auto &prod : A) {
        long long d = n / (prod.a * prod.b);
        long long rem = n % (prod.a * prod.b);
        sum += d * (prod.p * prod.b);
        sum += min(d, rem / prod.a) * prod.p;
    }
    return sum;
}

bool canAchieve(int n) {
    if (cost(n) > X) return false;
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0, a, p, b, q; i < N; ++i) {
        scanf("%d %d %d %d", &a, &p, &b, &q);
        if (a * q < b * p) swap(a, b), swap(p, q);
        A.emplace_back(a, p, b, q);
        dp[i][0] = 0;
        for (int j = 1; j < a * b; ++j) {
            dp[i][j] = min(dp[i][max(0, j - a)] + p, dp[i][max(0, j - b)] + q);
        }
    }

    int lo = 0, hi = 1e9;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (canAchieve(mid)) lo = mid;
        else hi = mid;
    }

    if (lo != hi && canAchieve(lo + 1)) lo++;
    printf("%d\n", lo);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // For each ingredient, decide optimal way to buy `mid` units at minimum cost
        ld priceA = p[i] / (ld)a[i]; // price per unit if buying bundle A
        ld priceB = q[i] / (ld)b[i]; // price per unit if buying bundle B

        if (priceA < priceB) {
            // Prefer buying more of bundle A
            int countA = mid / a[i];
            int remaining = mid % a[i];
            total_cost += countA * p[i] + remaining * priceA;
        } else {
            // Prefer buying more of bundle B
            int countB = mid / b[i];
            int remaining = mid % b[i];
            total_cost += countB * q[i] + remaining * priceB;
        }
    }

    return total_cost <= x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n); p.resize(n); b.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canMake(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << "\n";

    return 0;
}
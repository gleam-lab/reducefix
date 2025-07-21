#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, q, p;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // Calculate the minimum cost to get at least 'mid' units of ingredient i
        
        // Cost per unit using method A and B
        ld costA = p[i] / (ld)a[i];
        ld costB = q[i] / (ld)b[i];

        if (costA < costB) {
            // Prefer method A as it's cheaper per unit
            int countA = mid / a[i];
            int remaining = mid % a[i];
            total_cost += countA * p[i] + remaining * costA;
        } else {
            // Prefer method B
            int countB = mid / b[i];
            int remaining = mid % b[i];
            total_cost += countB * q[i] + remaining * costB;
        }
    }

    return total_cost <= x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) >> 1;

        if (canMake(mid)) 
            left = mid;
        else 
            right = mid - 1;
    }

    cout << left;

    return 0;
}
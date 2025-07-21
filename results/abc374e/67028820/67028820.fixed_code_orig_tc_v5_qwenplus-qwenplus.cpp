#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        // Try both options: buy as much of type A first or B first
        ld costA_first = 0;
        int wholeA = mid / a[i];
        int leftoverA = mid % a[i];
        costA_first += (ld)wholeA * p[i] + (ld)leftoverA * (q[i]/(ld)b[i]);

        ld costB_first = 0;
        int wholeB = mid / b[i];
        int leftoverB = mid % b[i];
        costB_first += (ld)wholeB * q[i] + (ld)leftoverB * (p[i]/(ld)a[i]);

        total_cost += min(costA_first, costB_first);
    }

    return (int)(ceil(total_cost)) <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) >> 1;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left << endl;

    return 0;
}
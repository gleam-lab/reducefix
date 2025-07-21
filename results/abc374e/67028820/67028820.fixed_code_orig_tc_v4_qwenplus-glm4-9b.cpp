#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define int long long
#define ll long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    long long total_cost = 0;
    for (int i = 0; i < n; i++) {
        long long temp = mid;
        double s = (double)p[i] / a[i];
        double t = (double)q[i] / b[i];

        if (s < t) {
            int x = temp / a[i];
            total_cost += x * p[i];
            temp -= x * a[i];
            total_cost += temp * llround(t);
        } else {
            int x = temp / b[i];
            total_cost += x * q[i];
            temp -= x * b[i];
            total_cost += temp * llround(s);
        }
    }

    return total_cost <= x;
}

int main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e18;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;
    return 0;
}
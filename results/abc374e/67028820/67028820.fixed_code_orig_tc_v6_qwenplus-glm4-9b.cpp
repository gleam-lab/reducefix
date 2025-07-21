#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define int long long
#define ll long long

int n, x;
vector<int> a, b, p, q;

bool canMake(int mid) {
    double total_cost = 0;
    for (int i = 0; i < n; i++) {
        int temp = mid;
        double s = p[i] / (double)a[i];
        double t = q[i] / (double)b[i];

        if (s < t) {
            int x = mid / a[i];
            total_cost += x * p[i];
            temp -= x * a[i];
            total_cost += temp * t;
        } else {
            int x = mid / b[i];
            total_cost += x * q[i];
            temp -= x * b[i];
            total_cost += temp * s;
        }
    }

    return (int)(ceil(total_cost)) <= x;
}

int main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); p.resize(n); q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int left = 0, right = 1e10;
    while (left < right) {
        int mid = (left + right + 1) / 2;

        if (canMake(mid)) left = mid;
        else right = mid - 1;
    }

    cout << left;

    return 0;
}
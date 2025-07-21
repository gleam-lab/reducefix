#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

int n, x;
vector<int> a, b, c, d;

bool canMake(int mid) {
    ll total_cost = 0;
    for (int i = 0; i < n; i++) {
        int x = mid / a[i];
        total_cost += x * p[i]; // Cost for the first resource
        mid -= x * a[i];
        double remain = mid / (double)b[i]; // Remainder by which we need the second resource
        total_cost += remain * q[i]; // Cost for the second resource
    }
    return total_cost <= x;
}

int main() {
    cin >> n >> x;
    a.resize(n); b.resize(n); c.resize(n); d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i] >> b[i] >> d[i];
        p.push_back(c[i]); // Resource 1 cost
        q.push_back(d[i]); // Resource 2 cost
    }

    int left = 0, right = 1e18;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canMake(mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << left - 1;
    return 0;
}
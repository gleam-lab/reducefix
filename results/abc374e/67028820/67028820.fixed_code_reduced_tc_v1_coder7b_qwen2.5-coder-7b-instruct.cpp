#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Process {
    int a, b, p, q;
    double s, t;
};

int n, x;
Process processes[105];

bool canAchieveCapacity(ll mid) {
    vector<ll> costs(n, 0);

    for (int i = 0; i < n; ++i) {
        ll remaining = mid - processes[i].a;
        if (remaining > 0) {
            ll additionalCost = ceil((double)remaining / processes[i].b) * processes[i].q;
            costs[i] = processes[i].p + additionalCost;
        }
    }

    ll totalCost = accumulate(costs.begin(), costs.end(), 0LL);
    return totalCost <= x;
}

int binarySearch() {
    int left = 0, right = 1e7;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (canAchieveCapacity(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> processes[i].a >> processes[i].p >> processes[i].b >> processes[i].q;
        processes[i].s = (double)processes[i].p / processes[i].a;
        processes[i].t = (double)processes[i].q / processes[i].b;
    }

    cout << binarySearch() << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

struct Machine {
    int a, p, b, q;
};

bool feasible(vector<Machine>& machines, int budget, int capacity) {
    for (auto& m : machines) {
        double x = ceil((double)(capacity - m.b * m.a) / m.a);
        double y = ceil((double)(capacity - m.a * m.b) / m.b);
        if (m.p * x + m.q * y > budget) return false;
    }
    return true;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<Machine> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
    }

    int l = 0, r = 1e7, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (feasible(machines, x, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
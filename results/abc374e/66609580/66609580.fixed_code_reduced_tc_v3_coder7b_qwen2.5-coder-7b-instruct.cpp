#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Machine {
    int a, b, p, q;
};

bool check(vector<Machine>& machines, vector<int>& w, long long budget, long long target_capacity) {
    long long cost = 0;
    for (int i = 0; i < machines.size(); ++i) {
        long long units_s = (target_capacity + machines[i].a - 1) / machines[i].a;
        long long units_t = (target_capacity + machines[i].b - 1) / machines[i].b;
        cost += min(units_s * machines[i].p, units_t * machines[i].q);
    }
    return cost <= budget;
}

int binary_search(vector<Machine>& machines, vector<int>& w, long long budget) {
    int left = 0, right = 1e7;
    while (left < right) {
        long long mid = (left + right + 1) / 2;
        if (check(machines, w, budget, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long budget;
    cin >> n >> budget;

    vector<Machine> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
    }

    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        w[i] = min(machines[i].a, machines[i].b);
    }

    cout << binary_search(machines, w, budget) << endl;

    return 0;
}
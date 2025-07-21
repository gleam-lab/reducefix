#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Machine {
    int a, b, p, q;
};

long long calculateCost(const Machine& m, long long capacity) {
    long long unitsS = capacity / m.a;
    long long unitsT = capacity / m.b;
    return unitsS * m.p + unitsT * m.q;
}

bool checkCapacity(int n, const vector<Machine>& machines, long long budget, long long targetCapacity) {
    for (const auto& m : machines) {
        long long cost = calculateCost(m, targetCapacity);
        if (cost > budget) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    long long budget;
    cin >> n >> budget;
    
    vector<Machine> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
    }

    long long left = 0, right = 10000000000LL;
    while (left < right) {
        long long mid = (left + right + 1) / 2;
        if (checkCapacity(n, machines, budget, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;
    return 0;
}
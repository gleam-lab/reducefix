#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

struct Process {
    ll A, B, P, Q;
};

ll minCapacity(const vector<Process>& processes, ll capacity) {
    ll totalCost = 0;
    for (const auto& proc : processes) {
        ll unitsS = max(0LL, capacity / proc.A);
        ll unitsT = max(0LL, capacity / proc.B);
        ll costS = unitsS * proc.P;
        ll costT = unitsT * proc.Q;
        totalCost += min(costS, costT);
    }
    return totalCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;

    vector<Process> processes(n);
    for (auto& proc : processes) {
        cin >> proc.A >> proc.P >> proc.B >> proc.Q;
    }

    ll left = 0, right = 1e10;
    while (left < right) {
        ll mid = (left + right + 1) / 2;
        if (minCapacity(processes, mid) <= x) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;

    return 0;
}
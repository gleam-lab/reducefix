#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Process {
    int A, B, P, Q;
};

bool check(const vector<Process>& processes, long long budget, long long target_capacity) {
    for (const auto& proc : processes) {
        long long lcm = lcm(proc.A, proc.B);
        long long max_units_S = (target_capacity + lcm - 1) / lcm * min(proc.P * (lcm / proc.A), proc.Q * (lcm / proc.B));
        long long max_units_T = (target_capacity + lcm - 1) / lcm * min(proc.Q * (lcm / proc.B), proc.P * (lcm / proc.A));
        if (max_units_S * proc.A + max_units_T * proc.B > budget) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long budget;
    cin >> n >> budget;

    vector<Process> processes(n);
    for (auto& proc : processes) {
        cin >> proc.A >> proc.P >> proc.B >> proc.Q;
    }

    long long left = 0, right = 1e9 + 10;
    while (left < right) {
        long long mid = (left + right + 1) / 2;
        if (check(processes, budget, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;
    return 0;
}
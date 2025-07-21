#include<bits/stdc++.h>
using namespace std;

struct Machine {
    int a, b, p, q;
};

bool check(vector<Machine>& machines, int budget, int capacity) {
    int total_cost = 0;
    for (auto& m : machines) {
        int units_S = max(0, (capacity - m.b * m.a + m.b - 1) / m.b);
        int units_T = max(0, (capacity - m.a * m.b + m.a - 1) / m.a);
        total_cost += min(units_S * m.p, units_T * m.q);
    }
    return total_cost <= budget;
}

int maxProductionCapacity(int N, int X, vector<vector<int>>& processes) {
    vector<Machine> machines(N);
    for (int i = 0; i < N; ++i) {
        machines[i].a = processes[i][0];
        machines[i].b = processes[i][1];
        machines[i].p = processes[i][2];
        machines[i].q = processes[i][3];
    }

    int left = 0, right = 1e7;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (check(machines, X, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<vector<int>> processes(N, vector<int>(4));
    for (int i = 0; i < N; ++i) {
        cin >> processes[i][0] >> processes[i][1] >> processes[i][2] >> processes[i][3];
    }
    cout << maxProductionCapacity(N, X, processes) << endl;
    return 0;
}
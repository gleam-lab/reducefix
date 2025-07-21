#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    long long A, P, B, Q;
};

bool canAchieveCapacity(const vector<Process>& processes, long long budget, long long targetCapacity) {
    for (const auto& p : processes) {
        long long cost = INF;
        for (long long s = 0; s <= p.B; ++s) {
            long long t = (max(0LL, targetCapacity - p.A * s) + p.B - 1) / p.B;
            cost = min(cost, s * p.P + t * p.Q);
        }
        if (cost > budget) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    long long X;
    cin >> N >> X;
    vector<Process> processes(N);

    for (int i = 0; i < N; ++i) {
        cin >> processes[i].A >> processes[i].P >> processes[i].B >> processes[i].Q;
    }

    long long low = 0, high = 1e9; // Assuming the upper bound is very large
    long long bestCapacity = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (canAchieveCapacity(processes, X, mid)) {
            bestCapacity = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << bestCapacity << endl;
    return 0;
}
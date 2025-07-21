#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canAchieveCapacity(const vector<pair<long long, long long>>& machines, long long budget, long long targetCapacity) {
    for (const auto& [A, P] : machines) {
        long long units = max(0LL, targetCapacity / A) + 1;
        long long cost = units * P;
        long long remainingBudget = budget - cost;
        if (remainingBudget < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    long long X;
    cin >> N >> X;
    vector<pair<long long, long long>> machinesS(N), machinesT(N);

    for (int i = 0; i < N; ++i) {
        long long A, B, P, Q;
        cin >> A >> P >> B >> Q;
        machinesS[i] = {A, P};
        machinesT[i] = {B, Q};
    }

    long long low = 0, high = 1e14;
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        if (canAchieveCapacity(machinesS, X, mid) || canAchieveCapacity(machinesT, X, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canAchieveProcessingCapacity(const vector<pair<int, int>>& machines, long long budget, long long targetCapacity) {
    for (const auto& [costPerUnit, units]: machines) {
        long long totalCost = 0;
        for (long long unitsUsed = 0; unitsUsed <= units; ++unitsUsed) {
            long long remainingUnits = targetCapacity - unitsUsed * costPerUnit;
            if (remainingUnits >= 0) {
                long long additionalUnitsNeeded = (remainingUnits + units - 1) / units;
                totalCost += unitsUsed * costPerUnit + additionalUnitsNeeded * units;
                break;
            }
        }
        if (totalCost > budget) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    long long X;
    cin >> N >> X;
    vector<pair<int, int>> machines(N);

    for (int i = 0; i < N; ++i) {
        cin >> machines[i].first >> machines[i].second;
    }

    sort(machines.begin(), machines.end());

    long long left = 0, right = 1e18;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (canAchieveProcessingCapacity(machines, X, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
    return 0;
}
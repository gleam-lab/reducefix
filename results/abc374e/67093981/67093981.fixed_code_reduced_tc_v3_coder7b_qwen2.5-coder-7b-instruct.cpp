#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Machine {
    int a, p, b, q;
};

long long maxProductionCapacity(int N, int X, vector<Machine>& machines) {
    // Sort machines based on the ratio of cost to production rate
    sort(machines.begin(), machines.end(), [](const Machine& m1, const Machine& m2) {
        double r1 = static_cast<double>(m1.p * m1.b) / (m1.a * m1.q);
        double r2 = static_cast<double>(m2.p * m2.b) / (m2.a * m2.q);
        return r1 > r2;
    });

    long long totalCost = 0, productionCapacity = 0;

    for (int i = 0; i < N; ++i) {
        // Calculate how many units of the current machine can be purchased within the remaining budget
        long long units = X / (machines[i].a * machines[i].b);
        if (units == 0) break; // If no more units can be bought, stop processing further

        // Update total cost and production capacity
        totalCost += units * machines[i].p * machines[i].b;
        productionCapacity += units * min(machines[i].a, machines[i].b);

        // Reduce the remaining budget
        X -= units * machines[i].p * machines[i].b;
    }

    return productionCapacity;
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<Machine> machines(N);
    for (int i = 0; i < N; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
    }

    cout << maxProductionCapacity(N, X, machines) << endl;

    return 0;
}
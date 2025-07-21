#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 1 << 30;

int main() {
    int N;
    long long X;
    cin >> N >> X;
    vector<pair<long long, pair<long long, long long>>> machines(N);

    for (int i = 0; i < N; i++) {
        cin >> machines[i].first >> machines[i].second.first >> machines[i].second.second;
    }

    sort(machines.begin(), machines.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    long long processing_capacity = 0, cost = 0;

    for (const auto& machine : machines) {
        long long max_capacity = machine.second.first;
        long long price = machine.second.second;

        // Calculate the maximum amount we can spend on this machine
        long long max_spent = min(X - cost, max_capacity * price);
        processing_capacity += max_spent / price;
        cost += max_spent;

        // If we have spent all our budget, break early
        if (cost == X) {
            break;
        }
    }

    cout << processing_capacity << endl;

    return 0;
}
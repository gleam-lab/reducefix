#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
using ll = long long;

int main() {
    int N;
    ll X;
    cin >> N >> X;

    vector<pair<ll, pair<ll, pair<ll, ll>>>> machines(N);

    for (int i = 0; i < N; ++i) {
        ll A, P, B, Q;
        cin >> A >> P >> B >> Q;
        machines[i] = {A, {P, {B, Q}}};
    }

    // Sort machines by A (ascending)
    sort(machines.begin(), machines.end());

    // Binary search to find the minimum processing capacity
    ll lb = 0, ub = numeric_limits<ll>::max();

    while (ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        ll cost = 0;
        ll i = 0;

        for (; i < N && machines[i].first <= mid; ++i) {
            ll maxB = min(mid / machines[i].second.first, machines[i].third.first);
            ll maxQ = mid % machines[i].second.first;
            ll currCost = maxB * machines[i].second.second.first + maxQ * machines[i].second.second.second;
            cost += currCost;

            ll maxA = min(mid / machines[i].first, machines[i].second.second.first);
            ll maxP = mid % machines[i].first;
            ll currCost2 = maxA * machines[i].second.second.second + maxP * machines[i].second.second.first;
            cost += currCost2;
        }

        if (cost <= X) {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    cout << ub << endl; // Output the minimum processing capacity that can be achieved within budget X.
    return 0;
}
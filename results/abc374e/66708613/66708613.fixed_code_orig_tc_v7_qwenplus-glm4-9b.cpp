#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<pair<ll, ll>> costA(N), costB(N);

    for (int i = 0; i < N; ++i) {
        ll A, P, B, Q;
        cin >> A >> P >> B >> Q;
        costA[i] = {P, Q};
        costB[i] = {A, P};
    }

    sort(costA.begin(), costA.end());
    sort(costB.begin(), costB.end());

    ll minCost = X;
    for (int i = 0; i < N; ++i) {
        ll cost = costA[i].first * costB[i].first + costB[i].second * costA[i].second;
        minCost = min(minCost, cost);
    }

    if (minCost > X) {
        cout << 0 << endl;
    } else {
        ll maxCapacity = (X - minCost) / N;
        cout << maxCapacity << endl;
    }

    return 0;
}
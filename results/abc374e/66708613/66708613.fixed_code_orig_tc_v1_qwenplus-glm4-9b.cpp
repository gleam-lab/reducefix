#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    int N;
    ll X;
    cin >> N >> X;

    vector<pair<ll, ll>> A(N), P(N), B(N), Q(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i].first >> P[i] >> B[i] >> Q[i].first;
        A[i].second = -A[i].first; // Store negative values for easier processing
    }

    sort(A.begin(), A.end()); // Sort by processing time in descending order for binary search
    sort(P.begin(), P.end()); // Sort prices in descending order for binary search
    sort(B.begin(), B.end()); // Sort quantities in descending order for binary search

    ll lower_bound = 0;
    ll upper_bound = 1e18;

    while (upper_bound - lower_bound > 1) {
        ll mid = (upper_bound + lower_bound) / 2;
        ll cost = 0;
        ll current_capacity = 0;

        int j = 0; // Pointer to iterate over A
        for (int i = 0; i < N; ++i) {
            if (A[j].second < mid) {
                ++j;
            }
            if (A[j].second < mid) break; // Early exit if we exceed mid capacity

            int max_machines = min(mid - A[j].second, B[j]);
            for (int m = 0; m < max_machines; ++m) {
                cost += Q[j].first;
                current_capacity += A[j].first;
            }
        }

        if (current_capacity >= mid) {
            lower_bound = mid;
        } else {
            upper_bound = mid;
        }
    }

    cout << lower_bound << endl;
    return 0;
}
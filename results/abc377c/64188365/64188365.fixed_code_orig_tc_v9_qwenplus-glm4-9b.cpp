#include <iostream>
#include <set>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> unavailable;

    // Step 1: Process each piece and add its capture range to the set of unavailable squares
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        vector<pair<ll, ll>> captureRange;

        // Calculate the capture range based on the conditions in the problem statement
        captureRange.push_back({a, b});
        captureRange.push_back({a + 1, b + 2});
        captureRange.push_back({a, b + 2});
        captureRange.push_back({a - 1, b + 2});
        captureRange.push_back({a - 2, b + 1});
        captureRange.push_back({a - 2, b - 1});
        captureRange.push_back({a - 1, b - 2});
        captureRange.push_back({a, b - 2});
        captureRange.push_back({a + 2, b - 1});

        // Add the captured squares to the set of unavailable squares
        for (const auto& p : captureRange) {
            unavailable.insert({p.first, p.second});
        }
    }

    // Step 2: Count the available squares
    ll availableSquares = n * n - unavailable.size();

    // Output the result
    cout << availableSquares << endl;

    return 0;
}
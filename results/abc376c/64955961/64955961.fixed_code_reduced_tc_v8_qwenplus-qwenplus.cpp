#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> A(n), B(n - 1);

    for (ll i = 0; i < n; ++i) cin >> A[i];
    for (ll i = 0; i < n - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Use binary search to find the minimum required size x
    ll left = 1, right = 1e18, answer = -1;

    while (left <= right) {
        ll mid = (left + right) / 2;

        // Create a temporary list of box sizes including the new one
        vector<ll> boxes = B;
        boxes.push_back(mid);
        sort(boxes.begin(), boxes.end());

        // Try to assign toys to boxes greedily from largest to smallest
        ll toy_idx = n - 1;
        ll box_idx = n - 1;

        while (toy_idx >= 0 && box_idx >= 0) {
            if (A[toy_idx] <= boxes[box_idx]) {
                // This box can fit this toy and no need to use it for smaller toys
                toy_idx--;
            }
            box_idx--;
        }

        if (toy_idx == -1) {
            // All toys were assigned
            answer = mid;
            right = mid - 1;
        } else {
            // Not all toys could be assigned
            left = mid + 1;
        }
    }

    cout << answer << endl;
}

int main() {
    solve();
}
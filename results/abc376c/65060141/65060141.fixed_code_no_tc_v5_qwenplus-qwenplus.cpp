#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> A(n), B(n - 1);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We will use binary search to find the minimum required size of the extra box

    // First, try to match largest toys with largest available boxes
    int a_ptr = n - 1;
    int b_ptr = n - 2;

    while (a_ptr >= 0 && b_ptr >= 0) {
        if (B[b_ptr] >= A[a_ptr]) {
            // Box can fit this toy, move to next smaller toy and box
            a_ptr--;
            b_ptr--;
        } else {
            // Can't fit current toy in current box, need to use extra box
            break;
        }
    }

    // At this point, all toys from A[a_ptr+1..n-1] have been matched with boxes
    // Remaining unmatched toys are A[0..a_ptr]

    if (a_ptr == -1) {
        // All toys can be placed in existing boxes
        cout << 0 << endl;
        return 0;
    }

    // Only one toy at most can be placed in the extra box
    // So we must be able to place all other toys in remaining boxes
    // Check if all remaining toys is at most one
    int remaining_boxes = b_ptr + 1;
    int remaining_toys = a_ptr + 1;

    if (remaining_toys > remaining_boxes + 1) {
        // Even using the extra box, not enough space
        cout << -1 << endl;
        return 0;
    }

    // We can place the largest remaining toy in the extra box
    cout << A[a_ptr] << endl;

    return 0;
}
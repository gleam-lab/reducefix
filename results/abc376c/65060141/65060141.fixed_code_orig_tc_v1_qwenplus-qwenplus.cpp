#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n - 1);

    // We need to assign toys (a) to boxes (b), leaving one toy to be placed in the new box
    // Try to match largest toys with largest available boxes

    int i = n - 1; // current toy index (largest to smallest)
    int j = n - 2; // current box index (largest to smallest)

    // First try to fit largest toys into largest available boxes
    while (i >= 0 && j >= 0) {
        if (b[j] >= a[i]) {
            // this toy fits in this box
            i--;
            j--;
        } else {
            // can't fit, we'll need a bigger box for this toy
            i--;
        }
    }

    // After greedy matching, if we have boxes left, then all toys fit and we can return 1
    // If we have toys left, we need to find what's the smallest toy that didn't get matched
    // because we might still be able to use a smaller box than the biggest unmatched toy

    // Let's reverse and do more precise check
    i = 0;
    j = 0;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }

    if (i == n) {
        // All toys matched, we can use x=1
        cout << "1\n";
        return 0;
    }

    // i points to the first unassigned toy, find minimum box size needed
    // Need to pick the smallest x such that we can replace one used box with x

    // Find which toy couldn't be assigned
    cout << a[i] << "\n";

    return 0;
}
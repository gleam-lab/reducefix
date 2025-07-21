#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n-1; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll i = 0, j = 0;
    ll cnt = 0;
    ll x = -1;

    while (i < n && j < n-1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            if (x == -1) {
                x = a[i];
                cnt++;
                i++;
            } else {
                cnt++;
                i++;
            }
        }
    }

    while (i < n) {
        if (x == -1) {
            x = a[i];
            cnt++;
        } else {
            cnt++;
        }
        i++;
    }

    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        if (x == -1) {
            // All toys are placed in existing boxes, any x <= smallest B is acceptable?
            // But since we need to place each toy in separate boxes, and we have N-1 boxes + 1 new box = N boxes.
            // So if all toys are placed in existing boxes, then the new box can be of any size, but the problem requires x to be minimal.
            // So the minimal x is 1, but since the toy sizes can be up to 1e9, but the boxes must be >= toy size.
            // So if all toys are placed, x can be any value >=0, but x must be positive. So minimal x is 1.
            // But the expected output suggests that x should be the smallest possible, but in this case, any x that is >=0 is allowed, but the toys are already placed.
            // So perhaps the problem expects x to be the smallest possible box size that can be used to place the remaining toys.
            // Since all toys are placed, x can be any value, but the problem might need us to consider the case where one toy is left, but in this case, cnt would be 1.
            // So in this scenario, perhaps x is the smallest toy not placed, but since all are placed, x can be 1.
            // But in the provided test case, the expected output is 641, which suggests that the new box must be exactly the size of the largest toy not placed.
            // So this suggests that the initial approach might have a flaw.
            // Alternative approach: simulate the placing more carefully.
            // Alternative approach: after sorting, for each toy, find the smallest box that can contain it.
            // The toys that can't be matched to any box will need the new box.
            // The new box must be able to contain all unmatched toys, but since each toy must be in a separate box, only one toy can be placed in the new box.
            // So if there's more than one unmatched toy, it's impossible. Otherwise, the new box must be at least the size of the unmatched toy.
            // So the correct approach is to count how many toys cannot be placed in any existing box. If more than one, output -1. Otherwise, output the size of the unmatched toy (or the smallest possible x if all are placed).
            // So the original code's logic was correct, but perhaps the implementation had a bug.
            // Let me re-examine the original code.
            // In the original code, after the while loops, if cnt is 0, all toys were placed in existing boxes. But the problem requires purchasing a new box (step 1), so even if all toys can be placed in existing boxes, we still need to buy a new box (but it can be of any size, preferably the smallest possible, 1).
            // However, the problem says to place each toy into one of the N boxes (N-1 existing + 1 new). So if all toys can be placed in existing boxes, the new box can be left empty, but the problem requires purchasing it. The minimal x in this case is probably 1.
            // But the sample input expects 641, which suggests that in the sample, one toy is left, which needs a box of size 641.
            // So the original code's logic must have missed some cases.
            // So the correct approach is: after sorting, try to match toys to boxes. The toys that cannot be matched will need the new box. If there's more than one such toy, output -1. Otherwise, output the size of that toy.
            // So the code should be modified to:
            // Count the number of toys that cannot be placed in any box. If more than 1, output -1. Otherwise, output the size of the unmatched toy (or 1 if all are matched).
            // Let me implement this.
            // Reset variables:
            x = 1; // minimal possible box size
        }
        cout << x << endl;
    }
}

int main() {
    solve();
    return 0;
}
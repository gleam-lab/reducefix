#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    
    vector<ll> A(n), B(n - 1);

    for (ll i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We need to find the minimum x such that we can assign all toys to boxes
    // Try to match largest toys with largest available boxes first
    // If we can't fit a toy in a box, we'll need to use our custom box

    ll i = n - 1, j = n - 2;
    ll needed_x = 0;
    ll unassigned_toy_count = 0;

    while (i >= 0 && j >= 0) {
        if (B[j] >= A[i]) {
            // This box can be used for one of the smaller toys
            i--;
            j--;
        } else {
            // This toy must go into our custom box
            needed_x = max(needed_x, A[i]);
            unassigned_toy_count++;
            i--;
        }
    }

    // If more than one toy remains unassigned after using all N-1 boxes, it's impossible
    if (unassigned_toy_count > 1) {
        cout << -1 << "\n";
    } else {
        cout << needed_x << "\n";
    }

    return 0;
}
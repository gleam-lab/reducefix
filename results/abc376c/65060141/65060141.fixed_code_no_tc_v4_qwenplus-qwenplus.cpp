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

    // We will use binary search to find minimal x

    // First, check if it's possible to assign toys to boxes with one box removed from A
    // That is, try each toy as the one that needs the extra box

    vector<ll> min_required(n); // min_required[i] is the smallest box needed for toy i

    // Two pointers approach: match largest toys with largest available boxes
    ll a_idx = n - 1, b_idx = n - 2;
    while (a_idx >= 0 && b_idx >= 0) {
        if (B[b_idx] >= A[a_idx]) {
            b_idx--;
            a_idx--;
        } else {
            a_idx--;
        }
    }

    // If more than one toy couldn't be matched, it's impossible
    if (a_idx > 0) {
        cout << -1 << '\n';
        return 0;
    }

    // The unmatched toy needs our purchased box
    ll required_x = A[a_idx];

    // But we need to make sure we don't miss better options
    // Try every toy as the one that goes into the purchased box
    a_idx = n - 1, b_idx = n - 2;
    ll need = -1;

    while (a_idx >= 0) {
        if (b_idx >= 0 && B[b_idx] >= A[a_idx]) {
            b_idx--;
            a_idx--;
        } else {
            if (need == -1) {
                need = A[a_idx];
                a_idx--; // Use purchased box for this toy
            } else {
                // Second toy can't fit, not enough boxes
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << need << '\n';
    return 0;
}
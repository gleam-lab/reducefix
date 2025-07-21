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

    // We need to find the minimal x such that we can assign all toys
    // using N-1 boxes from B and one box of size x.

    // Idea: Use greedy matching:
    // Try to match largest toys with largest available boxes.
    // If only one toy cannot be matched, then it's the required x.
    // Otherwise, it's not possible.

    int a_idx = n - 1;
    int b_idx = n - 2;

    while (a_idx >= 0 && b_idx >= 0) {
        if (B[b_idx] >= A[a_idx]) {
            a_idx--;
            b_idx--;
        } else {
            // This toy cannot fit in the current biggest box => needs our own box
            break;
        }
    }

    if (a_idx < 0) {
        // All toys matched, we could use any x (but minimum is smallest toy)
        // Actually, since all toys matched, we didn't need an extra box
        // But since we must buy one, choose smallest toy
        cout << A[0] << "\n";
    } else if (a_idx == 0) {
        // Only one toy left to assign, which is A[0]
        cout << A[0] << "\n";
    } else {
        // More than one toy cannot be handled with only one custom box
        cout << -1 << "\n";
    }

    return 0;
}
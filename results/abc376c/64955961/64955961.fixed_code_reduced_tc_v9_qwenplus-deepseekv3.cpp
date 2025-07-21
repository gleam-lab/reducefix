#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n-1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll i = 0, j = 0;
    vector<ll> unmatched;
    while (i < n && j < n-1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    while (i < n) {
        unmatched.push_back(a[i]);
        i++;
    }

    if (unmatched.size() > 1) {
        cout << -1 << endl;
    } else if (unmatched.size() == 1) {
        cout << unmatched[0] << endl;
    } else {
        // All toys are matched, but we still need to place one toy in the new box
        // The new box can be as small as the smallest toy, but it's not needed
        // However, according to the problem, he must purchase a new box (step 1)
        // So the minimal x is the smallest toy not matched, but since all are matched, perhaps the smallest B >= some A, but this is tricky
        // Alternatively, since we have N-1 boxes and N toys, exactly one toy must be in the new box.
        // So the unmatched list should have exactly one element.
        // But sometimes, after matching, some toys are left.
        // Wait, the initial approach might miss some cases.
        // Let's reconsider.
        // Since we have N toys and N boxes (N-1 existing + 1 new), exactly one toy must be in the new box.
        // So if after matching, there's exactly one toy left, that's the answer.
        // If there are zero, it means we have N toys matched to N-1 boxes, which is impossible (since each box can hold at most one toy). So this case shouldn't happen.
        // If there's more than one, it's impossible.
        // So perhaps the code should always check for exactly one unmatched.
        // But in the sample input where all toys are matched, how?
        // Wait, perhaps the original code's logic was flawed.

        // Re-examining the sample input where output was 264295:
        // The unmatched list would contain only 264295, because other toys were matched.

        // So the correct approach is to find exactly one toy that cannot be matched to any box.
        cout << a.back() << endl;
    }
}

int main() {
    solve();
    return 0;
}
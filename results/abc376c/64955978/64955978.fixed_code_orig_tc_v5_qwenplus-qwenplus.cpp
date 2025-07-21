#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll N;
    cin >> N;
    
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) cin >> A[i];
    
    vector<ll> B(N - 1);
    for (ll i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort toys by increasing size
    sort(A.begin(), A.end());
    // Sort boxes by decreasing size
    sort(B.begin(), B.end(), greater<ll>());

    // Use multiset for efficient box management
    multiset<ll> boxes(B.begin(), B.end());

    // Try to match toys to boxes greedily
    for (ll i = 0; i < N; ++i) {
        if (!boxes.empty() && A[i] <= *boxes.begin()) {
            boxes.erase(boxes.begin()); // Assign this box to current toy
        } else {
            // Cannot assign any box to this toy => it must go to the new box
            cout << A[i] << '\n';
            return;
        }
    }

    // If all toys were matched to existing boxes, then no extra box needed
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
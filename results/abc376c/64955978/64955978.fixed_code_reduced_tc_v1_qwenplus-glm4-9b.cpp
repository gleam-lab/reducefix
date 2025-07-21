#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for (ll i = 0; i < N; i++) cin >> A[i];
    for (ll i = 0; i < N-1; i++) cin >> B[i];
    
    sort(A.begin(), A.end());  // Sort toy sizes in ascending order
    sort(B.begin(), B.end());  // Sort box sizes in ascending order
    
    ll min_box_size = LLONG_MAX;  // To keep track of the smallest box size
    bool placed[N];  // To check if a toy has been placed in a box
    
    for (ll i = 0; i < N; i++) {
        bool placed_in_box = false;
        for (ll j = 0; j < N-1 && !placed_in_box; j++) {
            if (B[j] >= A[i] && !placed[i]) {
                placed_in_box = true;
                placed[i] = true;
                min_box_size = min(min_box_size, B[j]);
            }
        }
        if (!placed_in_box) {
            cout << -1 << endl;
            return;
        }
    }
    
    // Check if the largest toy can fit in any remaining box
    bool can_fit_all_toys = false;
    for (ll i = 0; i < N-1; i++) {
        if (B[i] >= A[N-1]) {
            can_fit_all_toys = true;
            break;
        }
    }
    
    if (!can_fit_all_toys) {
        cout << -1 << endl;
    } else {
        cout << min_box_size << endl;
    }
}

int main() {
    solve();
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for(ll i = 0; i < N; ++i) cin >> a[i];
    for(ll i = 0; i < N-1; ++i) cin >> b[i];

    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll j = 0; // Index for boxes
    for(ll i = 0; i < N; ++i) {
        // Find a suitable box for toy i
        while(j < N-1 && b[j] < a[i]) ++j;
        if(j == N-1) { // No suitable box found
            cout << "-1\n";
            return;
        }
        ++j; // Move to the next box
    }

    cout << a[N-1] << "\n"; // The last toy determines the required box size
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
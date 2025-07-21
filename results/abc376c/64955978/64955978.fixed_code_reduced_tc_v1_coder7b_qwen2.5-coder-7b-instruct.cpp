#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define sp ' '
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N-1; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Find the maximum size of toy that cannot fit into any box
    ll max_unfit = -1;
    for(int i = 0; i < N-1; i++) {
        if(a[i] > b[i]) {
            max_unfit = a[i];
            break;
        }
    }

    // If no toy is too big to fit into any box, we need a new box of size at least the largest toy
    if(max_unfit == -1) {
        max_unfit = a[N-1];
    }

    // Check if this box can fit all remaining toys
    bool can_fit = true;
    for(int i = N-2; i >= 0 && can_fit; i--) {
        if(a[i] > max_unfit) {
            can_fit = false;
        }
    }

    if(can_fit) {
        cout << max_unfit << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
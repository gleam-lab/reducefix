#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using ll = long long;
int n;
vector<ll> a;

int main() {
    cin >> n;
    a.resize(n);
    
    rep(i, n) {
        cin >> a[i];
    }

    // Initialize sum of experience points
    ll max_experience = 0;
    
    // Iterate through each monster
    for(int i = 0; i < n; ++i) {
        // If it's an odd-indexed monster or the next monster is stronger than twice the current one
        if((i % 2 == 0 && i + 1 == n) || (i + 1 < n && a[i + 1] * 2 > a[i])) {
            // Add the strength of the current monster to the sum
            max_experience += a[i];
        }
    }

    cout << max_experience << endl;
    return 0;
}
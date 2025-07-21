#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<ll> possible_x;
    
    // Check possibility where the new box is used for the largest toy(s)
    // Case 1: Ignore the largest toy in 'a' and match the rest
    {
        bool valid = true;
        for (int i = 0, j = 0; i < n - 1; ) {
            if (j < n - 1 && a[i] <= b[j]) {
                i++;
                j++;
            } else {
                valid = false;
                break;
            }
        }
        if (valid) {
            possible_x.push_back(a.back());
        }
    }
    
    // Case 2: Ignore the largest box in 'b' and match the rest
    {
        bool valid = true;
        for (int i = 0, j = 0; i < n; ) {
            if (j < n - 2 && a[i] <= b[j]) {
                i++;
                j++;
            } else if (j == n - 2 && a[i] <= b[j]) {
                i++;
                j++;
            } else {
                valid = false;
                break;
            }
        }
        if (valid) {
            possible_x.push_back(a[n - 1]);
        }
    }
    
    // Case 3: General approach to find the minimal x
    {
        vector<ll> candidates;
        // The new box must be >= the largest unplaced toy
        // So find all possible unplaced toys when trying to match
        int i = 0, j = 0;
        vector<ll> unplaced;
        while (i < n && j < n - 1) {
            if (a[i] <= b[j]) {
                i++;
                j++;
            } else {
                unplaced.push_back(a[i]);
                i++;
            }
        }
        while (i < n) {
            unplaced.push_back(a[i]);
            i++;
        }
        
        if (unplaced.size() == 1) {
            possible_x.push_back(unplaced[0]);
        } else if (unplaced.size() > 1) {
            // All unplaced must fit into the new box x, so x >= max(unplaced)
            possible_x.push_back(*max_element(unplaced.begin(), unplaced.end()));
        } else {
            // All toys placed, x can be 1
            possible_x.push_back(1);
        }
    }
    
    if (possible_x.empty()) {
        cout << -1 << endl;
    } else {
        sort(possible_x.begin(), possible_x.end());
        cout << possible_x[0] << endl;
    }
}

int main() {
    solve();
    return 0;
}
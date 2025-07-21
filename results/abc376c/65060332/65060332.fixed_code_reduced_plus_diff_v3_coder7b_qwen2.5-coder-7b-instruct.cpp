#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<ll> a(n), b(n-1);
    
    // Read input for toy sizes
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Read input for box sizes
    for(int i = 0; i < n-1; ++i) {
        cin >> b[i];
    }

    // Sort toy sizes and box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Check if we can fit all toys into boxes
    bool possible = true;
    for(int i = 0; i < n-1; ++i) {
        if(a[i] > b[i]) {
            possible = false;
            break;
        }
    }

    // If last toy can fit into the last box
    if(possible && a[n-1] <= b[n-2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
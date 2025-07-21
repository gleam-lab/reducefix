#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<long long> va(n), vb(n-1);
    
    for(int i = 0; i < n; ++i)
        cin >> va[i];

    for(int i = 0; i < n-1; ++i)
        cin >> vb[i];

    sort(va.rbegin(), va.rend()); // Sort toys in descending order
    sort(vb.rbegin(), vb.rend()); // Sort boxes in descending order
    
    long long minBoxSize = max(va[n-1], vb[0]); // Minimum required box size
    
    for(int i = 0; i < n-1; ++i) {
        if(vb[i] < va[i+1]) { // Check if current box can fit next toy
            cout << "-1\n"; 
            return 0;
        } 
        minBoxSize = max(minBoxSize, max(va[i], vb[i])); // Update min required box size
    }

    cout << minBoxSize << "\n";

    return 0;
}
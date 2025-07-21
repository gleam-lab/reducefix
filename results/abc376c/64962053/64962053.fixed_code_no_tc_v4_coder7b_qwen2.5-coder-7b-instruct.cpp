#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> va(n), vb(n);
    for(int i=0; i<n; ++i)
        cin >> va[i];
    for(int i=1; i<n; ++i)
        cin >> vb[i];
    
    // Sort the arrays to facilitate finding the minimum x
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // Check if the largest toy can fit into any box
    if (va[n-1] <= vb[n-2]) {
        cout << va[n-1] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
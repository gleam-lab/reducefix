#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for(int i = 0; i < n; ++i)
        cin >> va[i];
    for(int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    // Sort both arrays to facilitate comparison
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // The largest toy size needs to fit in some box
    int maxToySize = *max_element(va.begin(), va.end());
    
    // Check if any box can accommodate the largest toy
    for(int i = 0; i < n - 1; ++i) {
        if(vb[i] >= maxToySize) {
            cout << vb[i] << endl; // Found the smallest box that can hold the largest toy
            return 0;
        }
    }

    // If no box can accommodate the largest toy, we need a new box
    cout << maxToySize << endl;
    return 0;
}
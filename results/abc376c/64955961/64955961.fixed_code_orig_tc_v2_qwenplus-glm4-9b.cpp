#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<ll> toySizes(n);
    vector<ll> boxSizes(n - 1);
    ll maxToySize = 0;
    
    for (ll &size : toySizes) {
        cin >> size;
        maxToySize = max(maxToySize, size);
    }

    for (ll &size : boxSizes) {
        cin >> size;
    }

    // To keep track of the smallest box size that can fit all toys
    ll smallestBoxSize = maxToySize + 1;
    
    // Check each box size to see if it can be the smallest box to fit all toys
    for (ll size : boxSizes) {
        if (size >= maxToySize) {
            smallestBoxSize = min(smallestBoxSize, size);
        }
    }
    
    // If the smallest box size that can fit all toys is still greater than maxToySize,
    // it means we need an even larger box
    if (smallestBoxSize == maxToySize + 1) {
        smallestBoxSize = maxToySize + 1;
    }
    
    cout << smallestBoxSize << endl;
    return 0;
}
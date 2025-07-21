#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n);
    vb[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> va[i];
    for (int i = 1; i < n; i++)
        cin >> vb[i];
    vector<int> allSizes(n+1);
    for (int i = 0; i < n; i++) {
        allSizes[i] = va[i];
        allSizes[n] = max(allSizes[n], vb[i]);
    }
    sort(allSizes.rbegin(), allSizes.rend());
    
    if (allSizes[0] != allSizes[1]) { // if the largest toy is bigger than the largest box size
        cout << allSizes[1] << endl; // smallest possible box size
    } else {
        cout << -1 << endl; // no valid x
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n);
    
    for(int i = 0; i < n; ++i)
        cin >> va[i];
    
    for(int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int j = 0; // Index for boxes
    for(int i = 0; i < n; ++i) {
        while(j < n - 1 && vb[j] < va[i]) {
            ++j;
        }
        
        if(j == n - 1 && vb[j] < va[i]) {
            cout << "-1" << endl;
            return 0;
        }

        ++j;
    }

    cout << va[0] << endl; // The smallest box needed is the size of the first toy
    return 0;
}
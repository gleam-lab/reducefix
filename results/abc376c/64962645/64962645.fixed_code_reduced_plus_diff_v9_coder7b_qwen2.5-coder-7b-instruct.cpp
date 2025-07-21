#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];

    // Sort va in descending order and vb in ascending order
    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end());

    int ind = n, isPossible = false;

    for (int i = 0; i < n - 1; i++) {
        if (va[i] > vb[i]) {
            if (i == 0 || va[i] <= vb[i - 1]) {
                ind = i;
                isPossible = true;
                break;
            }
        }
    }

    if (isPossible) cout << va[ind] << endl;
    else cout << "-1" << endl;

    return 0;
}
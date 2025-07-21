#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n - 1);
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int last_box_size = vb.back(); // Size of the largest box
    for (int i = 0; i < n; ++i) {
        if (va[i] > last_box_size) {
            cout << va[i] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
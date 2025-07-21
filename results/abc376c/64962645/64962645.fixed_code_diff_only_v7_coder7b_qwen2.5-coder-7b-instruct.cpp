#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> va(n), vb(n - 1);
    for (int i = 0; i < n; i++) 
        cin >> va[i];
    for (int i = 0; i < n - 1; i++) 
        cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    long long max_b = *max_element(vb.begin(), vb.end());
    long long min_a = va[0];

    if (min_a > max_b) {
        cout << -1 << endl;
        return 0;
    }

    long long l = 1, r = 1e9 + 10;
    while (l < r) {
        long long m = (l + r) / 2;
        bool valid = true;
        for (int i = 0; i < n - 1; i++) {
            if (m < vb[i]) {
                valid = false;
                break;
            }
        }
        if (valid && m >= va[n - 1]) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << l << endl;
    return 0;
}
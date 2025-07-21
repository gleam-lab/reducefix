#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> va(n), vb(n-1);
    for(int i = 0; i < n; ++i) cin >> va[i];
    for(int i = 0; i < n-1; ++i) cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    long long max_needed_size = 0;
    for(int i = 0; i < n-1; ++i) {
        if(vb[i] < va[i]) {
            max_needed_size = max(max_needed_size, va[i]);
        } else {
            max_needed_size = max(max_needed_size, vb[i]);
        }
    }

    if(max_needed_size >= va[n-1]) {
        cout << max_needed_size << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
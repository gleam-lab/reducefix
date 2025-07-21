#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n - 1);

    for (int i = 0; i < n; ++i)
        cin >> va[i];

    for (int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    long long min_size = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (vb[i] >= va[i]) {
            continue;
        } else {
            min_size = max(min_size, (long long)va[i]);
        }
    }

    min_size = max(min_size, (long long)va[n - 1]);

    if (min_size == 0) {
        cout << "-1" << endl;
    } else {
        cout << min_size << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& va, vector<int>& vb, int x) {
    vector<bool> used(vb.size() + 1, false);
    for (int i = 0; i < va.size(); ++i) {
        if (va[i] <= x) {
            bool found = false;
            for (int j = 0; j < vb.size(); ++j) {
                if (!used[j] && vb[j] >= va[i]) {
                    used[j] = true;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    for (int i = 0; i < n; ++i) cin >> va[i];
    for (int i = 0; i < n-1; ++i) cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int l = 1, r = 1e9;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(va, vb, m)) r = m;
        else l = m + 1;
    }

    if (check(va, vb, l)) cout << l << endl;
    else cout << -1 << endl;

    return 0;
}
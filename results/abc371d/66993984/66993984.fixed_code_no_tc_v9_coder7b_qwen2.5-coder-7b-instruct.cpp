#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
map<int, int> prefixSum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        prefixSum[x[i]] += p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        auto itL = prefixSum.lower_bound(L);
        auto itR = prefixSum.upper_bound(R);
        int result = 0;
        if (itL != prefixSum.end()) {
            result -= itL->second;
        }
        if (itR != prefixSum.begin()) {
            itR--;
            result += itR->second;
        }
        cout << result << endl;
    }
    return 0;
}
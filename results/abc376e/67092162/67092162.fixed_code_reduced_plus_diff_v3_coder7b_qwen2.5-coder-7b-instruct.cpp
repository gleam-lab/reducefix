#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
multiset<int> maxSet, minSet;

void updateSets(int oldVal, int newVal) {
    auto itMax = maxSet.find(oldVal);
    if (itMax != maxSet.end()) {
        maxSet.erase(itMax);
    }
    maxSet.insert(newVal);

    auto itMin = minSet.find(oldVal);
    if (itMin != minSet.end()) {
        minSet.erase(itMin);
    }
    minSet.insert(newVal);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Initialize sets with the first K elements
        for (int i = 0; i < k; ++i) {
            maxSet.insert(a[i]);
            minSet.insert(b[i]);
        }

        long long sumB = accumulate(minSet.begin(), minSet.end(), 0LL);
        long long result = (*maxSet.rbegin()) * sumB;

        for (int i = k; i < n; ++i) {
            updateSets(a[i - k], a[i]);
            updateSets(b[i - k], b[i]);

            sumB += b[i] - b[i - k];
            result = min(result, (*maxSet.rbegin()) * sumB);
        }

        cout << result << "\n";
    }
    return 0;
}
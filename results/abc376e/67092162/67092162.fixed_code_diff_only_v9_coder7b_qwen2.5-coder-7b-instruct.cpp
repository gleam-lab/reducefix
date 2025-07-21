#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first) return p1.first < p2.first;
    return p1.second > p2.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pairs[i] = {a[i], b[i]};
        }

        sort(pairs.begin(), pairs.end(), cmp);

        long long totalSum = 0;
        for (int i = 0; i < k; i++) {
            totalSum += pairs[i].second;
        }

        long long minAnswer = pairs[k - 1].first * totalSum;

        for (int i = k; i < n; i++) {
            totalSum -= pairs[i - k].second;
            totalSum += pairs[i].second;
            minAnswer = min(minAnswer, static_cast<long long>(pairs[i].first) * totalSum);
        }

        cout << minAnswer << "\n";
    }
    return 0;
}
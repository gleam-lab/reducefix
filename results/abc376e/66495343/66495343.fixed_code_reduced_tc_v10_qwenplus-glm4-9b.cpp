#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

const int N = 2e5 + 10;

int a[N], b[N];
vector<PII> pairs;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        pairs.clear();
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cin >> b[i];
            pairs.push_back({a[i], b[i]});
        }

        // Sort pairs by A_i in ascending order
        sort(pairs.begin(), pairs.end());

        int res = LLONG_MAX;
        multiset<int> multisum; // Multiset to maintain the sum of top K B_i values
        long long sum = 0; // Sum of top K B_i values

        // Iterate through sorted pairs
        for (auto p : pairs) {
            // Add current B_i to the sum and multisum
            sum += p.second;
            multisum.insert(p.second);

            // If we have more than K elements, remove the smallest one
            if (multisum.size() > k) {
                sum -= *multisum.begin();
                multisum.erase(multisum.begin());
            }

            // If we have exactly K elements, calculate the result
            if (multisum.size() == k) {
                res = min(res, p.first * sum);
            }
        }

        cout << res << endl;
    }

    return 0;
}
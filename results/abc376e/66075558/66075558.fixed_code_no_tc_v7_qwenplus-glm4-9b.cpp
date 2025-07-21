#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
const int maxN = 200000 + 5;

int n, k;
int a[maxN], b[maxN];

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Pair and sort by A values, if equal, then by B values ascending
        vector<pair<int, int>>ab;
        for (int i = 0; i < n; ++i) {
            ab.emplace_back(a[i], b[i]);
        }
        sort(ab.begin(), ab.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first != p2.first) return p1.first < p2.first;
            return p1.second < p2.second;
        });

        long long sumB = 0, maxA = ab[0].first;
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            sumB += ab[i].second;
            if (i >= k - 1) {
                if (i < n - 1) {
                    sumB -= ab[i + 1].second; // Remove the last element added
                }
                result = min(result, maxA * sumB);
            }
        }

        cout << result << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, k;
int A[N], B[N];
vector<pair<int, int>> AB;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        AB.clear();

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            AB.emplace_back(A[i], B[i]);
        }

        sort(AB.begin(), AB.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });

        long long ans = LLONG_MAX;
        long long sumB = 0;
        int count = 0;

        for (auto& p : AB) {
            sumB += p.second;
            if (++count == k) {
                ans = min(ans, (sumB - p.second) * p.first);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
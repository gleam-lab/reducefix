#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

const int N = 2e5 + 9;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(N + 1);
    vector<pair<int, int>> queries;

    // Read all A_i values
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Read all B_j and k_j values and store them as queries
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        queries.emplace_back(b, k);
    }

    // Sort queries by B_j (second element of the pair) to handle them in increasing order
    sort(queries.begin(), queries.end());

    // Sort A_i values for binary search
    sort(a.begin() + 1, a.end() + 1);

    // Process each query
    for (const auto& q : queries) {
        int b = q.first;
        int k = q.second;
        int left = 1, right = n, ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int dist = abs(b - a[mid]);
            if (mid < n) {
                int nextDist = abs(b - a[mid + 1]);
                if (dist < nextDist) {
                    ans = dist;
                    left = mid + 1;
                } else {
                    ans = nextDist;
                    right = mid;
                }
            } else {
                ans = dist;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
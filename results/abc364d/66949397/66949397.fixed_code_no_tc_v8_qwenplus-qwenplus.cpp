#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    m_int N, Q;
    cin >> N >> Q;
    vector<m_int> a(N);

    for (m_int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (Q--) {
        m_int b, k;
        cin >> b >> k;

        // Binary search on the answer (distance)
        m_int low = 0, high = 2e8 + 10; // Safe upper bound

        auto count_in_range = [&](m_int x) {
            // Find first A_i >= (b - x)
            auto left = lower_bound(a.begin(), a.end(), b - x);
            // Find last A_i <= (b + x)
            auto right = upper_bound(a.begin(), a.end(), b + x);
            return static_cast<m_int>(right - left);
        };

        // Binary search to find the k-th smallest distance
        while (low < high) {
            m_int mid = (low + high) / 2;
            if (count_in_range(mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << "\n";
    }

    return 0;
}
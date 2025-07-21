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
    std::sort(a.begin(), a.end());

    while (Q--) {
        m_int b, k;
        cin >> b >> k;

        // Binary search on the answer
        m_int left = 0, right = 2e8 + 10; // Generous upper bound on possible distance

        auto count_points_within_distance = [&](m_int x) {
            // Find first A_i >= (b - x)
            auto low = std::lower_bound(a.begin(), a.end(), b - x);
            // Find last A_i <= (b + x)
            auto high = std::upper_bound(a.begin(), a.end(), b + x);
            return static_cast<m_int>(high - low);
        };

        while (left < right) {
            m_int mid = (left + right) / 2;
            if (count_points_within_distance(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }

    return 0;
}
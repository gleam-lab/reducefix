#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
    m_int N, Q;
    cin >> N >> Q;
    vector<m_int> A(N);
    
    for (m_int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    std::sort(A.begin(), A.end());

    while (Q--) {
        m_int b, k;
        cin >> b >> k;

        auto count_points_in_range = [&](m_int x) {
            // Number of points in A that are at most 'x' away from b
            auto left = b - x;
            auto right = b + x;
            auto it_l = std::lower_bound(A.begin(), A.end(), left);
            auto it_r = std::upper_bound(A.begin(), A.end(), right);
            return it_r - it_l;
        };

        m_int low = 0;
        m_int high = 200000000; // Max possible distance
        m_int result = high;

        while (low <= high) {
            m_int mid = (low + high) / 2;
            if (count_points_in_range(mid) >= k) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << result << "\n";
    }

    return 0;
}
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

        auto f = [&](m_int x) -> bool {
            // Binary search to find the range of elements within distance x from b
            auto left = std::lower_bound(A.begin(), A.end(), b - x);
            auto right = std::upper_bound(A.begin(), A.end(), b + x);
            return (right - left) >= k;
        };

        m_int low = 0, high = 2e8 + 10; // Safe upper bound
        while (low < high) {
            m_int mid = (low + high) / 2;
            if (f(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << low << "\n";
    }

    return 0;
}
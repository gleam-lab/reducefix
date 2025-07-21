#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;
using std::sort;

int main() {
    m_int n, q;
    cin >> n >> q;

    vector<m_int> a(n);
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<m_int, m_int>> queries(q);
    for (m_int j = 0; j < q; ++j) {
        cin >> queries[j].first >> queries[j].second;
        queries[j].first -= a[queries[j].second - 1]; // Adjust B_j based on the k_j-th A_i
    }

    sort(queries.begin(), queries.end());

    vector<m_int> sorted_a_indices(n);
    for (m_int i = 0; i < n; ++i) {
        sorted_a_indices[i] = i;
    }
    sort(sorted_a_indices.begin(), sorted_a_indices.end(), [&](m_int i, m_int j) {
        return a[i] < a[j];
    });

    cout << "Case#1\n";
    for (auto& q : queries) {
        m_int b = q.first;
        m_int k = q.second;
        auto it = std::lower_bound(sorted_a_indices.begin(), sorted_a_indices.end(), k, [&](m_int a, m_int b) {
            return abs(a - b) >= abs(b - b - 1); // Find the smallest index >= k
        });
        cout << abs(a[*it] - b) << "\n";
    }
}
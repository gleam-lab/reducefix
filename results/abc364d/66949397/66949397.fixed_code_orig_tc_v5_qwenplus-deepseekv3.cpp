#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

using m_int = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    m_int n, q;
    cin >> n >> q;
    vector<m_int> a(n);
    
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (q--) {
        m_int b, k;
        cin >> b >> k;

        vector<m_int> distances(n);
        for (m_int i = 0; i < n; ++i) {
            distances[i] = abs(a[i] - b);
        }
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << "\n";
    }
}
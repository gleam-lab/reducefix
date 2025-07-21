#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q, b, k;
    cin >> n >> q;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (int j = 0; j < q; ++j) {
        cin >> b >> k;
        vector<int> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = abs(A[i] - b);
        }
        std::nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << endl;
    }

    return 0;
}
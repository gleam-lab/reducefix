#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5 + 9;
vector<int> a(N);
int b[N], k[N];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }

    vector<int> distances;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q; ++j) {
            distances.push_back(abs(a[i] - b[j]));
        }
    }
    
    sort(distances.begin(), distances.end());
    
    for (int j = 0; j < q; ++j) {
        // Find the k-th smallest distance for B_j
        int k_j = k[j] - 1; // Convert to 0-indexed
        cout << distances[k_j] << endl;
    }
    
    return 0;
}
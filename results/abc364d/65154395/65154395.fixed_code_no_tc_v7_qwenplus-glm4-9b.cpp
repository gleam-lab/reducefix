#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    vector<pair<long long, int>> b(q);

    // Read the coordinates of A
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Read the coordinates and k_j for each B_j
    for (int j = 0; j < q; j++) {
        cin >> b[j].first >> b[j].second;
    }

    // Sort B by the value of b_j (this doesn't change the order of k_j)
    sort(b.begin(), b.end());

    // Sort A by the value of a_i
    sort(a.begin(), a.end());

    // For each B_j, find the k_j-th closest A_i
    for (const auto& p : b) {
        long long b_j = p.first;
        int k_j = p.second;

        // Create a vector of distances between B_j and each A_i
        vector<long long> distances;
        for (int i = 0; i < n; i++) {
            distances.push_back(abs(a[i] - b_j));
        }

        // Get the k_j-th closest distance
        cout << distances[k_j - 1] << endl;
    }

    return 0;
}
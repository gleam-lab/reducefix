#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
vector<ll> A, B;

int main() {
    int N, Q;
    cin >> N >> Q;
    A.resize(N);
    B.resize(Q);

    // Read coordinates of points A_i
    for(int i = 0; i < N; ++i)
        cin >> A[i];

    // Read coordinates of points B_j and their respective k_j values
    for(int j = 0; j < Q; ++j) {
        cin >> B[j].first >> B[j].second;
    }

    // Sort points A_i
    sort(A.begin(), A.end());

    // Process each query
    for(int j = 0; j < Q; ++j) {
        int target_index = B[j].second - 1; // Convert 1-based index to 0-based
        auto it = lower_bound(A.begin(), A.end(), B[j].first); // Find first element not less than B[j].first

        // Calculate distances
        vector<int> distances;
        for(; it != A.end(); ++it) {
            distances.push_back(abs(*it - B[j].first));
        }

        // Sort distances
        sort(distances.begin(), distances.end());

        // Output the k-th smallest distance
        cout << distances[target_index] << '\n';
    }

    return 0;
}
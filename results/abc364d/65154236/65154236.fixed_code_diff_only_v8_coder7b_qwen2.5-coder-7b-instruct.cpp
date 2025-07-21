#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<pair<int, int>> queries;

// Function to find the k-th smallest distance
int findKthSmallest(vector<int>& distances, int k) {
    sort(distances.begin(), distances.end());
    return distances[k - 1];
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    // Read the coordinates of points A
    for(int i = 0; i < n; ++i) {
        int a_i;
        cin >> a_i;
        A.push_back(a_i);
    }
    
    // Read the queries
    for(int i = 0; i < q; ++i) {
        int b_j, k_j;
        cin >> b_j >> k_j;
        queries.emplace_back(b_j, k_j);
    }
    
    // For each query, calculate the distances and find the k-th smallest one
    for(auto& [b_j, k_j] : queries) {
        vector<int> distances;
        for(int a_i : A) {
            distances.push_back(abs(a_i - b_j));
        }
        cout << findKthSmallest(distances, k_j) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
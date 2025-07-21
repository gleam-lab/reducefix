#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> pointsA[MAXN]; // Stores pairs of (distance, index)

// Comparator function for custom sort
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> coordsA(N);
    for (int i = 0; i < N; ++i) {
        cin >> coordsA[i];
    }

    for (int q = 0; q < Q; ++q) {
        int coordB, k;
        cin >> coordB >> k;
        
        for (int i = 0; i < N; ++i) {
            int dist = abs(coordsA[i] - coordB);
            pointsA[i].push_back({dist, i});
        }
        
        // Sort the distances for each point A_i
        for (int i = 0; i < N; ++i) {
            sort(pointsA[i].begin(), pointsA[i].end(), compare);
        }
        
        // Output the k-th smallest distance
        cout << pointsA[k-1][0] << "\n";
        
        // Clear the vector for next query
        for (int i = 0; i < N; ++i) {
            pointsA[i].clear();
        }
    }

    return 0;
}
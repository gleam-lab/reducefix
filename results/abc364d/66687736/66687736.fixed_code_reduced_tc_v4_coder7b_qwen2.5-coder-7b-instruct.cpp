#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

vector<int> sortedDistances(const vector<int>& A, int B) {
    vector<int> distances(A.size());
    for (size_t i = 0; i < A.size(); ++i) {
        distances[i] = abs(A[i] - B);
    }
    sort(distances.begin(), distances.end());
    return distances;
}

int findKthClosestDistance(vector<int>& sortedDistances, int k) {
    return sortedDistances[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int& a : A) {
        cin >> a;
    }

    vector<pair<int, int>> queries(Q);
    for (auto& [B, k] : queries) {
        cin >> B >> k;
    }

    // Precompute sorted distances for each unique point A[i]
    set<int> uniquePoints(A.begin(), A.end());
    unordered_map<int, vector<int>> precomputedDistances;
    for (int point : uniquePoints) {
        precomputedDistances[point] = sortedDistances(A, point);
    }

    for (auto& [B, k] : queries) {
        auto it = lower_bound(uniquePoints.begin(), uniquePoints.end(), B);
        if (it == uniquePoints.end()) {
            // If B is greater than any point in A, use the last computed distances
            it = prev(uniquePoints.end());
        }
        int result = findKthClosestDistance(precomputedDistances[*it], k);
        cout << result << '\n';
    }

    return 0;
}
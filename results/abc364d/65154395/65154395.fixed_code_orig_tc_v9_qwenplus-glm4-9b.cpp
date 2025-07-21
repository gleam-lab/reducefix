#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i; // Store original index
    }
    
    sort(A.begin(), A.end());

    vector<vector<int>> distances(Q);
    for (int j = 0; j < Q; ++j) {
        int B;
        cin >> B;
        for (int i = 0; i < N; ++i) {
            int distance = abs(B - A[i].first);
            distances[j].push_back(distance);
        }
        sort(distances[j].begin(), distances[j].end());
    }

    for (int j = 0; j < Q; ++j) {
        cout << distances[j][j] << endl; // k-th distance for each B_j is always the k-th element in the sorted list
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    for (int i = 0; i < Q; ++i) {
        int Bj = queries[i].first;
        int kj = queries[i].second;
        
        vector<int> distances(N);
        for (int j = 0; j < N; ++j) {
            distances[j] = abs(Bj - A[j]);
        }
        
        // We need the kj-th smallest element, which is at kj-1 in 0-indexed array
        sort(distances.begin(), distances.end());
        cout << distances[kj - 1] << endl;
    }
    
    return 0;
}
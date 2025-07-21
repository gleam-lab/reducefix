#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAXN = 100005;
vector<int> A(MAXN);

void solve() {
    int N, Q; cin >> N >> Q;
    
    // Read the coordinates of points A
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    // Process each query
    for(int i = 0; i < Q; i++) {
        int B, K; cin >> B >> K;
        
        // Calculate distances from B to all points A
        vector<int> distances(N);
        for(int j = 1; j <= N; j++) {
            distances[j-1] = abs(A[j] - B);
        }
        
        // Sort the distances
        sort(distances.begin(), distances.end());
        
        // Output the k-th smallest distance (1-based index)
        cout << distances[K-1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
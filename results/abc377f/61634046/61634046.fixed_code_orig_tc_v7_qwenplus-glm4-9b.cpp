#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    vector<unordered_set<int>> rows(N+1), cols(N+1);
    vector<unordered_set<int>> diagSum(N+1), diagDiff(N+1);
    
    // Read pieces and calculate the capture area for each piece
    for (int i = 0; i < M; ++i) {
        int r, c;
        cin >> r >> c;
        pieces[i] = {r, c};
        
        // Rows and columns
        rows[r].insert(c);
        cols[c].insert(r);
        
        // Diagonals
        diagSum[r + c].insert(c);
        diagDiff[r - c + N].insert(c);
    }
    
    // Count the number of captured squares
    int captured = 0;
    for (int i = 1; i <= N; ++i) {
        captured += rows[i].size() + cols[i].size();
        for (int diag : diagSum[i]) captured++;
        for (int diag : diagDiff[i]) captured++;
    }
    
    // Total squares minus captured squares
    int total = N * N;
    cout << total - captured << '\n';
    
    return 0;
}
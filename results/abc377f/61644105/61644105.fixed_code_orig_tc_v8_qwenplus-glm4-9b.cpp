#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
long long rowSums[MAX_N + 1], colSums[MAX_N + 1];
vector<int> rowCaptures[MAX_N + 1], colCaptures[MAX_N + 1];
vector<pair<int, int>> diagsCaptures[2 * MAX_N + 1];

int main() {
    int N, M;
    cin >> N >> M;
    
    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        a--; b--; // Convert to zero-based indexing
        
        // Capture row and column
        rowCaptures[a].push_back(b);
        colCaptures[b].push_back(a);
        
        // Capture diagonals
        diagsCaptures[a + b].push_back({a, b});
        diagsCaptures[a - b + N].push_back({a, b});
    }
    
    // Precompute row and column sums
    for (int i = 0; i < N; ++i) {
        rowSums[i + 1] = rowSums[i] + rowCaptures[i].size();
        colSums[i + 1] = colSums[i] + colCaptures[i].size();
    }
    
    // Precompute diagonal sums
    for (int i = 0; i < 2 * N + 1; ++i) {
        sort(diagsCaptures[i].begin(), diagsCaptures[i].end());
    }
    
    // Count safe positions
    long long safePositions = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i > 0 && rowSums[i] - rowSums[i - 1] > rowCaptures[i - 1].size() ||
                j > 0 && colSums[j] - colSums[j - 1] > colCaptures[j - 1].size() ||
                (i + j > 0 && diagsCaptures[i + j].back().first - diagsCaptures[i + j].front().first > diagsCaptures[i + j].size()) ||
                (i - j > 0 && diagsCaptures[i - j + N].back().first - diagsCaptures[i - j + N].front().first > diagsCaptures[i - j + N].size())) {
                continue;
            }
            safePositions++;
        }
    }
    
    cout << safePositions << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> captured;
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        captured.insert({a, b});
    }
    
    // Calculate the number of cells that can be captured by each piece
    vector<long long> capture_count(N + 1, 0);
    for (const auto& p : captured) {
        long long x = p.first;
        long long y = p.second;
        
        // Check if the piece can capture any cells
        if (x <= N - 2 && y <= N - 1) {
            capture_count[x + 2] = max(capture_count[x + 2], capture_count[x] + 1);
        }
        if (x <= N - 1 && y <= N - 2) {
            capture_count[x + 1] = max(capture_count[x + 1], capture_count[x] + 1);
        }
        if (x >= 1 && y <= N - 2) {
            capture_count[x - 1] = max(capture_count[x - 1], capture_count[x] + 1);
        }
        if (x >= 2 && y <= N - 1) {
            capture_count[x - 2] = max(capture_count[x - 2], capture_count[x] + 1);
        }
        if (x >= 2 && y >= 1) {
            capture_count[x - 2] = max(capture_count[x - 2], capture_count[x] + 1);
        }
        if (x <= N - 1 && y >= 2) {
            capture_count[x + 1] = max(capture_count[x + 1], capture_count[x] + 1);
        }
        if (x <= N - 2 && y >= 1) {
            capture_count[x + 2] = max(capture_count[x + 2], capture_count[x] + 1);
        }
        if (x >= 1 && y >= 2) {
            capture_count[x - 1] = max(capture_count[x - 1], capture_count[x] + 1);
        }
        if (x >= 2 && y >= 1) {
            capture_count[x + 2] = max(capture_count[x + 2], capture_count[x] + 1);
        }
    }
    
    // Subtract the number of captured cells from the total cells
    long long total_cells = N * N;
    long long captured_cells = total_cells;
    for (long long i = 0; i <= N; ++i) {
        captured_cells -= min(N * N, i) - max(0LL, i - capture_count[i]);
    }
    
    cout << captured_cells << endl;
    return 0;
}
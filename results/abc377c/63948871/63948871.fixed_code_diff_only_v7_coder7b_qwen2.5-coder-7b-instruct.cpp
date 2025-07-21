#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAXN = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int M;
    cin >> N >> M;

    unordered_set<int> occupied;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        
        // Convert coordinates to a unique integer representation
        int idx = (a - 1) * N + b;
        occupied.insert(idx);
        
        // Add positions that can be captured by the piece at (a, b)
        int directions[8][2] = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };
        
        for (auto& dir : directions) {
            int new_a = a + dir[0];
            int new_b = b + dir[1];
            
            if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N) {
                occupied.insert((new_a - 1) * N + new_b);
            }
        }
    }

    // Calculate the number of empty squares
    long long total_empty = static_cast<long long>(N) * N - occupied.size();
    cout << total_empty << endl;

    return 0;
}
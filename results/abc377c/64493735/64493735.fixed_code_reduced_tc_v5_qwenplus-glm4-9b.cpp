#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const vector<pair<int, int>> DIRECTIONS = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int main() {
    int N, M;
    cin >> N >> M;
    
    unordered_map<int, unordered_map<int, bool>> can_capture;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        for (const auto &dir : DIRECTIONS) {
            int nx = a + dir.first;
            int ny = b + dir.second;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                can_capture[nx][ny] = true;
            }
        }
    }
    
    // Check number of free squares
    int free_squares = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            bool is_free = true;
            for (const auto &dir : DIRECTIONS) {
                int nx = i + dir.first;
                int ny = j + dir.second;
                if (1 <= nx && nx <= N && 1 <= ny && ny <= N && can_capture[nx][ny]) {
                    is_free = false;
                    break;
                }
            }
            if (is_free) {
                free_squares++;
            }
        }
    }
    
    cout << free_squares << endl;
    return 0;
}
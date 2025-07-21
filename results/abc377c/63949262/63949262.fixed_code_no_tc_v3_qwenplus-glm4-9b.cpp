#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define INF 1000000000

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    set<pair<int, int>> occupied;
    for (const auto& piece : pieces) {
        occupied.insert(piece);
    }

    long long safe_squares = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (occupied.find({i, j}) == occupied.end()) {
                bool is_safe = true;
                // Check if the current square can be captured by any piece
                for (const auto& piece : pieces) {
                    int x = piece.first, y = piece.second;
                    if (x + 2 <= N && y + 1 <= N && occupied.find({x + 2, y + 1}) != occupied.end()) {
                        is_safe = false;
                        break;
                    }
                    if (x + 1 <= N && y + 2 <= N && occupied.find({x + 1, y + 2}) != occupied.end()) {
                        is_safe = false;
                        break;
                    }
                    if (x - 1 >= 1 && y + 2 <= N && occupied.find({x - 1, y + 2}) != occupied.end()) {
                        is_safe = false;
                        break;
                    }
                    if (x - 2 >= 1 && y + 1 <= N && occupied.find({x - 2, y + 1}) != occupied.end()) {
                        is_safe = false;
                        break;
                    }
                    if (x - 2 >= 1 && y - 1 >= 1 && occupied.find({x - 2, y - 1}) != occupied.end()) {
                        is_safe = false;
                        break;
                    }
                    if (x - 1 >= 1 && y - 2 >= 1 && occupied.find({x - 1, y - 2}) != occupied.end()) {
                        is_safe = false;
                        break;
                    }
                    if (x + 1 <= N && y - 2 >= 1 && occupied.find({x + 1, y - 2}) != occupied.end()) {
                        is_safe = false;
                        break;
                    }
                    if (x + 2 <= N && y - 1 >= 1 && occupied.find({x + 2, y - 1}) != occupied.end()) {
                        is_safe = false;
                        break;
                    }
                }
                if (is_safe) {
                    ++safe_squares;
                }
            }
        }
    }
    
    cout << safe_squares << endl;
    
    return 0;
}
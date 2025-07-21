#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<pair<int, int>> occupied_squares;
    for (auto& p : pieces) {
        occupied_squares.insert(p);
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            bool can_place = true;
            
            // Check all possible capture positions
            for (int di = -2; di <= 2; ++di) {
                for (int dj = -2; dj <= 2; ++dj) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni < 1 || ni > N || nj < 1 || nj > N) continue; // Skip out of bounds
                    if (occupied_squares.count({ni, nj})) {
                        can_place = false;
                        break;
                    }
                }
                if (!can_place) break;
            }
            
            if (can_place) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
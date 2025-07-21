#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    set<pair<int, int>> pieces;
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // Check and insert all possible positions that can be attacked by the knight
        for(int dx = -2; dx <= 2; ++dx) {
            for(int dy = -2; dy <= 2; ++dy) {
                if(abs(dx) + abs(dy) == 3) {
                    int nx = a + dx, ny = b + dy;
                    if(nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                        pieces.insert({nx, ny});
                    }
                }
            }
        }
    }

    // Calculate the number of empty squares
    long long total_squares = static_cast<long long>(N) * N;
    long long occupied_squares = pieces.size();
    long long empty_squares = total_squares - occupied_squares;

    cout << empty_squares << endl;

    return 0;
}
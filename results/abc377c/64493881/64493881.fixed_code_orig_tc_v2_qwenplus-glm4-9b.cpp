#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int dy[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dx[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> attacked(N + 2, vector<int>(N + 2, 0));
    set<pair<int, int>> pieces;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.emplace(a, b);
        for (int k = 0; k < 8; ++k) {
            int x = a + dy[k];
            int y = b + dx[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked[x][y] = 1;
            }
        }
    }

    // è®¡ç®æªè¢«æ»å»çæ»åºå
    long long total = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (attacked[i][j] == 0) {
                total++;
            }
        }
    }

    cout << total - static_cast<long long>(pieces.size()) << endl;

    return 0;
}
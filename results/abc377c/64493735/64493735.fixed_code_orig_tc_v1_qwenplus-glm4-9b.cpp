#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<int, int>> capturedCells;
    vector<pair<int, int>> pieces(M);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                int nx = a + dx;
                int ny = b + dy;
                if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                    capturedCells.emplace_back(nx, ny);
                }
            }
        }
    }

    set<pair<int, int>> uniqueCapturedCells(capturedCells.begin(), capturedCells.end());
    long long totalCells = N * N;
    long long safeCells = totalCells - uniqueCapturedCells.size();

    cout << safeCells << endl;

    return 0;
}
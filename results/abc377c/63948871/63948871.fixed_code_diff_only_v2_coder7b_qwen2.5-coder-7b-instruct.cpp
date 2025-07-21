#include <iostream>
#include <bitset>

using namespace std;

const int MAXN = 1000000000;
const int MAXM = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    bitset<MAXN * MAXN> attacked;

    for (int k = 0; k < M; ++k) {
        int a, b;
        cin >> a >> b;
        
        // Mark all positions that can be attacked by the knight
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (abs(dx) + abs(dy) == 3) {
                    int nx = a + dx;
                    int ny = b + dy;
                    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                        attacked[(nx - 1) * N + (ny - 1)] = true;
                    }
                }
            }
        }
    }

    // Calculate the number of valid positions
    int valid_positions = N * N - attacked.count();

    cout << valid_positions << endl;

    return 0;
}
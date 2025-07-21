#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> captured_cells;

    // Process each existing piece and update the captured cells
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        // Add the capture range of the piece to the captured_cells set
        // This is where the actual logic for determining the capture range needs to be implemented
    }

    // Calculate the number of available cells
    long long available_cells = N * N;
    for (const auto& cell : captured_cells) {
        available_cells--;
    }

    cout << available_cells << endl;

    return 0;
}
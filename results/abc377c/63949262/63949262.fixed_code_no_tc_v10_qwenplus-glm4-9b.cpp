#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000000;
const int MAX_M = 200000;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    long long valid_positions = N * N; // Total cells in the grid
    long long captured_positions = 0;

    for (int i = 0; i < M; ++i) {
        int r = pieces[i].first;
        int c = pieces[i].second;

        // Check if the current piece can capture any cells in the grid
        if (r + 2 <= N) captured_positions++;
        if (r + 2 <= N && c + 1 <= N) captured_positions++;
        if (r + 1 <= N && c + 2 <= N) captured_positions++;
        if (r - 1 >= 1 && c + 2 <= N) captured_positions++;
        if (r - 2 >= 1 && c + 1 <= N) captured_positions++;
        if (r - 2 >= 1 && c - 1 >= 1) captured_positions++;
        if (r - 1 >= 1 && c - 2 >= 1) captured_positions++;
        if (r + 1 <= N && c - 2 >= 1) captured_positions++;
    }

    valid_positions -= captured_positions;
    cout << valid_positions << endl;

    return 0;
}
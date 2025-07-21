#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

#define ALL(a) (a).begin(), (a).end()

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<int, int>> st;
    vector<pair<int, int>>vc = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    vector<pair<int, int>> pieces;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        pieces.emplace_back(a, b);
        for (auto &p : vc) {
            int nx = a + p.first;
            int ny = b + p.second;
            st.insert({nx, ny});
        }
    }

    long long total_cells = N * N;
    long long captured_cells = 0LL;

    // Calculate the number of cells that can be captured
    for (int i = 0; i < M; ++i) {
        int cx = pieces[i].first;
        int cy = pieces[i].second;

        // Check all the target cells that can be captured
        for (auto &p : vc) {
            int nx = cx + p.first;
            int ny = cy + p.second;

            // Check if the target cell exists within the grid
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                captured_cells++;
            }
        }
    }

    long long answer = total_cells - captured_cells;
    cout << answer << endl;

    return 0;
}
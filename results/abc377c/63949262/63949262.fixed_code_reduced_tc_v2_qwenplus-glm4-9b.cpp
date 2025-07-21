#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000000;

struct Boundary {
    int x;
    int y;
    int type;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Boundary> boundaries;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        // Add the boundaries for the current piece
        boundaries.push_back({a - 2, b - 1, 1}); // (i-2, j-1)
        boundaries.push_back({a - 2, b, 1});     // (i-2, j)
        boundaries.push_back({a - 2, b + 1, 1}); // (i-2, j+1)
        boundaries.push_back({a - 1, b + 2, 1}); // (i-1, j+2)
        boundaries.push_back({a + 1, b + 2, 1}); // (i+1, j+2)
        boundaries.push_back({a + 2, b + 1, 1}); // (i+2, j+1)
        boundaries.push_back({a + 2, b, 1});     // (i+2, j)
        boundaries.push_back({a + 2, b - 1, 1}); // (i+2, j-1)
        boundaries.push_back({a - 1, b - 2, 1}); // (i-1, j-2)
        boundaries.push_back({a + 1, b - 2, 1}); // (i+1, j-2)
    }

    // Sort the boundaries by x and y and type
    sort(boundaries.begin(), boundaries.end());

    // Merge overlapping or contiguous regions
    vector<Boundary> merged_boundaries;
    for (auto &b : boundaries) {
        if (!merged_boundaries.empty() && merged_boundaries.back().x == b.x && merged_boundaries.back().type == b.type) {
            merged_boundaries.back().y = b.y;
        } else {
            merged_boundaries.push_back(b);
        }
    }

    // Count the number of safe cells
    long long safe_cells = 0;
    for (int i = 0; i < merged_boundaries.size(); ++i) {
        if (merged_boundaries[i].type == 1) {
            if (i == 0 || merged_boundaries[i - 1].type == -1) {
                int x_start = merged_boundaries[i].x;
                int x_end = x_start + 1;
                int y_start = max(1, (i == 0 ? 1 : merged_boundaries[i].y));
                int y_end = min(N, (i == merged_boundaries.size() - 1 ? N : merged_boundaries[i + 1].y));
                safe_cells += (x_end - x_start) * (y_end - y_start);
            }
        }
    }

    cout << N * N - safe_cells << endl;

    return 0;
}
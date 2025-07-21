#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Rect {
    int min_row, max_row, min_col, max_col;
};

bool operator==(const Rect& a, const Rect& b) {
    return a.min_row == b.min_row && a.max_row == b.max_row &&
           a.min_col == b.min_col && a.max_col == b.max_col;
}

bool operator<(const Rect& a, const Rect& b) {
    if (a.min_row != b.min_row) return a.min_row < b.min_row;
    if (a.max_row != b.max_row) return a.max_row < b.max_row;
    if (a.min_col != b.min_col) return a.min_col < b.min_col;
    return a.max_col < b.max_col;
}

int main() {
    int N, M;
    cin >> N >> M;

    set<Rect> rectangles;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index
        Rect r = {a, a, b, b};

        // Expand the rectangle to include all possible captures
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                int nx = a + dx, ny = b + dy;
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    r.min_row = min(r.min_row, nx);
                    r.max_row = max(r.max_row, nx);
                    r.min_col = min(r.min_col, ny);
                    r.max_col = max(r.max_col, ny);
                }
            }
        }

        rectangles.insert(r);
    }

    long long safe_cells = N * N;
    for (const auto& r : rectangles) {
        // Subtract the cells in the bounding rectangle from the total
        safe_cells -= (r.max_row - r.min_row + 1) * (r.max_col - r.min_col + 1);
    }

    cout << safe_cells << endl;
    return 0;
}
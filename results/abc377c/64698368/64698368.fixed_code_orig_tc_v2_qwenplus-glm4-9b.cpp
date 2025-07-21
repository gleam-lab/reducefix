#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

// A structure to represent a capture area of a piece
struct CaptureArea {
    int cx, cy; // center coordinates
    int h, w;   // height and width of the capture area
};

// Check if a given square (x, y) is inside the capture area of a piece
bool is_captured(int x, int y, const CaptureArea& area) {
    if (x < area.cx - area.w / 2 || x > area.cx + area.w / 2 ||
        y < area.cy - area.h / 2 || y > area.cy + area.h / 2) {
        return false;
    }
    // Additional check for the specific capture pattern
    // You need to implement the exact capture pattern as per the problem statement
    // For example, if the piece captures in a diamond pattern with side length 2:
    int dx = x - area.cx;
    int dy = y - area.cy;
    if (abs(dx) + abs(dy) > 2) {
        return true;
    }
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<CaptureArea> areas;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        // Calculate the capture area for the piece at (a, b)
        // You need to implement the exact calculation as per the problem statement
        // For example, if the piece captures in a diamond pattern with side length 2:
        areas.push_back({a, b, 2, 2});
    }
    
    set<pair<int, int>> grid(N*N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid.insert({i, j});
        }
    }
    
    int free_squares = 0;
    for (const auto& area : areas) {
        for (int x = area.cx - area.w / 2; x <= area.cx + area.w / 2; ++x) {
            for (int y = area.cy - area.h / 2; y <= area.cy + area.h / 2; ++y) {
                if (is_captured(x, y, area) && grid.find({x, y}) != grid.end()) {
                    grid.erase({x, y});
                    free_squares++;
                }
            }
        }
    }
    
    cout << free_squares << endl;
    return 0;
}
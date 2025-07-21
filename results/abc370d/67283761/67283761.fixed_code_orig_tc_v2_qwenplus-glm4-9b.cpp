#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Grid {
private:
    int H, W;
    vector<vector<set<pair<int, int>>>> walls; // stores (row, col) for walls

public:
    Grid(int h, int w) : H(h), W(w), walls(h + 1, vector<set<pair<int, int>>>(w + 1)) {}

    // Function to process the bomb placement query
    void placeBomb(int r, int c) {
        // Find and remove wall at (r, c) if it exists
        walls[r][c].erase({r, c});

        // Check and remove walls around (r, c) as per the problem statement
        // This may involve querying the nearest wall in the four directions
    }

    // Function to get the remaining number of walls
    int getRemainingWalls() {
        int remainingWalls = 0;
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                remainingWalls += walls[i][j].size();
            }
        }
        return remainingWalls;
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    Grid grid(H, W);

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        grid.placeBomb(r, c);
    }

    cout << grid.getRemainingWalls() << endl;

    return 0;
}
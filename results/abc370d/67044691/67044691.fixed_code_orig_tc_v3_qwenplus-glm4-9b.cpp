#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define HMAX 400005
#define WMAX 400005

vector<set<int>> row_walls(HMAX), col_walls(WMAX);
int walls_remaining = 0;

void destroy_wall(int r, int c) {
    row_walls[r].erase(c);
    col_walls[c].erase(r);
    walls_remaining--;
}

void destroy_walls_around(int r, int c) {
    // Check and destroy walls above
    for (int i = r - 1; i >= 0; --i) {
        if (row_walls[i].find(c) != row_walls[i].end()) {
            row_walls[i].erase(c);
            col_walls[c].erase(i);
            walls_remaining--;
        } else {
            break;
        }
    }

    // Check and destroy walls below
    for (int i = r + 1; i < HMAX; ++i) {
        if (row_walls[i].find(c) != row_walls[i].end()) {
            row_walls[i].erase(c);
            col_walls[c].erase(i);
            walls_remaining--;
        } else {
            break;
        }
    }

    // Check and destroy walls to the right
    for (int j = c + 1; j < WMAX; ++j) {
        if (col_walls[j].find(r) != col_walls[j].end()) {
            row_walls[r].erase(j);
            col_walls[j].erase(r);
            walls_remaining--;
        } else {
            break;
        }
    }

    // Check and destroy walls to the left
    for (int j = c - 1; j >= 0; --j) {
        if (col_walls[j].find(r) != col_walls[j].end()) {
            row_walls[r].erase(j);
            col_walls[j].erase(r);
            walls_remaining--;
        } else {
            break;
        }
    }
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    // Initialize number of walls remaining
    walls_remaining = H * W;
    
    int r, c;
    for (int q = 0; q < Q; ++q) {
        cin >> r >> c;
        if (row_walls[r].find(c) != row_walls[r].end()) {
            // Wall exists at (r, c), destroy it
            destroy_wall(r, c);
        } else {
            // No wall at (r, c), destroy walls around it
            destroy_walls_around(r, c);
        }
    }
    
    cout << walls_remaining << endl;
    return 0;
}
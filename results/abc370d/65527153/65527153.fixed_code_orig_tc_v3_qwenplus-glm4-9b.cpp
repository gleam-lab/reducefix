#include <iostream>
#include <vector>
using namespace std;

const int MAX_H = 200020;

int H, W, Q;
vector<int> walls;

void add_wall(int r, int c) {
    walls.push_back(r);
    walls.push_back(c);
}

void remove_wall(int r, int c) {
    for (int i = 0; i < walls.size(); i += 2) {
        if (walls[i] == r && walls[i + 1] == c) {
            walls.erase(walls.begin() + i, walls.begin() + i + 2);
            return;
        }
    }
}

void process_bomb(int r, int c) {
    remove_wall(r, c);
    // Remove walls from the row and column
    for (int i = 0; i < walls.size(); i += 2) {
        if (walls[i] == r) {
            remove_wall(r, walls[i + 1]);
        }
        if (walls[i] == c) {
            remove_wall(c, walls[i + 1]);
        }
    }
}

int main() {
    cin >> H >> W >> Q;

    for (int i = 0; i < H * W; ++i) {
        add_wall(i / W + 1, i % W + 1);
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;
        process_bomb(r, c);
    }

    int remaining_walls = 0;
    for (int i = 0; i < walls.size(); i += 2) {
        remaining_walls++;
    }
    cout << remaining_walls << endl;

    return 0;
}
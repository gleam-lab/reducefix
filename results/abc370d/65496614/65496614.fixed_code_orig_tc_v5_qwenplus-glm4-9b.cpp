#include <iostream>
#include <vector>

using namespace std;

int H, W, Q;
vector<int> parent;

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    cin >> H >> W >> Q;
    parent.resize(W + 1);
    for (int i = 1; i <= W; ++i) parent[i] = i;

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (find(r) == find(c)) {
            // æ¢ã«é£çµããã¦ãã
            continue;
        } else {
            // é£çµãã
            unionSets(r, c);
            // å¨å²ã®å£ãé¤å»
            for (int i = 1; i <= H && find(i) == find(c); ++i) {
                unionSets(i, r);
            }
            for (int j = 1; j <= W && find(j) == find(r); ++j) {
                unionSets(j, c);
            }
        }
    }

    // å©ä½çå¢çæ°é
    int remainingWalls = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (find(i) != find(j)) {
                ++remainingWalls;
            }
        }
    }

    cout << remainingWalls << endl;

    return 0;
}
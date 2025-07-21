#include <iostream>
#include <vector>
using namespace std;

// æ£æ¥ç¹ (x, y) æ¯å¦å¨æ£ç
bool isInside(int x, int y, int n) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(n * n, {-1, -1}); // å­å¨ (åæ , æè·èå´)
    vector<pair<int, int>> occupied; // å­å¨ occupied ä½ç½®

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b; // è½¬æ¢ä¸º0-basedç´¢å¼
        occupied.push_back({a, b});

        // æ´æ°æè·åºå
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (dx != 0 || dy != 0) {
                    int nx = a + dx;
                    int ny = b + dy;
                    if (isInside(nx, ny, n)) {
                        pieces[nx * n + ny] = {nx, ny};
                    }
                }
            }
        }
    }

    // è®¡ç®å¯æ¾ç½®ä½ç½®æ°é
    int count = 0;
    for (int i = 0; i < n * n; ++i) {
        int x = i / n + 1;
        int y = i % n + 1;
        if (find(occupied.begin(), occupied.end(), {x - 1, y - 1}) == occupied.end()) {
            bool canPlace = true;
            for (int dx = -2; dx <= 2; ++dx) {
                for (int dy = -2; dy <= 2; ++dy) {
                    if (dx != 0 || dy != 0) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (isInside(nx, ny, n) && pieces[nx * n + ny].first != -1) {
                            canPlace = false;
                            break;
                        }
                    }
                }
                if (!canPlace) break;
            }
            if (canPlace) count++;
        }
    }

    cout << count << endl;
    return 0;
}
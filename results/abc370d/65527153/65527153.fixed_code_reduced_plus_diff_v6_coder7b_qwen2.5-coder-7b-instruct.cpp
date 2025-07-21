#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Point {
    int x, y;
};

struct Grid {
    int n, m;
    set<Point> walls;

    Grid(int _n, int _m) : n(_n), m(_m) {}

    bool has_wall(const Point& p) const {
        return walls.count(p);
    }

    void add_wall(const Point& p) {
        walls.insert(p);
    }

    void remove_wall(const Point& p) {
        walls.erase(walls.find(p));
    }

    void clear_walls() {
        walls.clear();
    }

    void explode_bomb(const Point& p) {
        // Destroy walls vertically
        for (int i = p.x - 1; i >= 1 && !has_wall({i, p.y}); --i) {
            remove_wall({i, p.y});
        }
        for (int i = p.x + 1; i <= n && !has_wall({i, p.y}); ++i) {
            remove_wall({i, p.y});
        }

        // Destroy walls horizontally
        for (int j = p.y - 1; j >= 1 && !has_wall({p.x, j}); --j) {
            remove_wall({p.x, j});
        }
        for (int j = p.y + 1; j <= m && !has_wall({p.x, j}); ++j) {
            remove_wall({p.x, j});
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    Grid grid(n, m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            grid.add_wall({i, j});
        }
    }

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;

        if (grid.has_wall({r, c})) {
            grid.remove_wall({r, c});
        } else {
            grid.explode_bomb({r, c});
        }
    }

    cout << grid.walls.size() << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) begin(x), end(x)

struct Point {
    int r, c;

    // Define equality for sorting and set operations
    bool operator==(const Point& other) const {
        return r == other.r && c == other.c;
    }

    // Define less than for sorting
    bool operator<(const Point& other) const {
        if (r != other.r) return r < other.r;
        return c < other.c;
    }
};

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Use sets to keep track of walls
    vector<set<Point>> rows(h + 2), cols(w + 2);
    rep(i, h + 2) {
        rows[i].insert({i, 1}); // Wall on the bottom of each row
        rows[i].insert({i, w + 1}); // Wall on the top of each row
    }
    rep(j, w + 2) {
        cols[j].insert({1, j}); // Wall on the left of each column
        cols[j].insert({h + 1, j}); // Wall on the right of each column
    }

    vector<Point> queries;
    rep(i, q) {
        int r, c;
        cin >> r >> c;
        queries.push_back({r, c});
    }

    // Sort queries to process them in lexicographical order
    sort(all(queries));

    // Process queries
    for (const auto& query : queries) {
        auto& r_set = rows[query.r];
        auto& c_set = cols[query.c];

        // Find the walls to remove
        auto r_it = r_set.lower_bound({query.r, 1});
        while (--r_it != r_set.lower_bound({query.r, 2})) {
            c_set.erase(r_it->c);
        }

        r_it = r_set.lower_bound({query.r, w});
        while (++r_it != r_set.upper_bound({query.r, w})) {
            c_set.erase(r_it->c);
        }

        auto c_it = c_set.lower_bound({1, query.c});
        while (--c_it != c_set.lower_bound({2, query.c})) {
            rows[c_it->r].erase(c_it->c);
        }

        c_it = c_set.lower_bound({h, query.c});
        while (++c_it != c_set.upper_bound({h, query.c})) {
            rows[c_it->r].erase(c_it->c);
        }

        // Remove the wall at the query point
        rows[query.r].erase({query.r, query.c});
        cols[query.c].erase({query.r, query.c});
    }

    // Calculate the number of remaining walls
    int remaining_walls = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (!rows[i].count({i, j}) && !cols[j].count({i, j})) {
                remaining_walls++;
            }
        }
    }

    cout << remaining_walls << endl;

    return 0;
}
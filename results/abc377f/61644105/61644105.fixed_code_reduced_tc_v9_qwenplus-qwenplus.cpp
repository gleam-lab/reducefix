#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using Coord = pair<i64, i64>;

i64 N, M;

map<i64, i64> row_map, col_map;
map<i64, i64> diag1_map, diag2_map;

// Count of squares that are threatened or occupied
set<pair<i64, i64>> occupied;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        
        row_map[a]++;
        col_map[b]++;
        diag1_map[a - b]++;
        diag2_map[a + b]++;
    }

    // Total number of threatened cells
    i64 total_threatened = 0;

    // Add all rows
    for (const auto& [x, _] : row_map) {
        total_threatened += N;
    }
    // Add all columns
    for (const auto& [x, _] : col_map) {
        total_threatened += N;
    }
    // Add diagonal 1 (a - b)
    for (const auto& [d, _] : diag1_map) {
        i64 len;
        if (N <= abs(d)) {
            len = 1;
        } else {
            len = N - abs(d);
        }
        total_threatened += len;
    }
    // Add diagonal 2 (a + b)
    for (const auto& [s, _] : diag2_map) {
        i64 len;
        if (s < 2 || s > 2 * N) {
            len = 0;
        } else if (s <= N + 1) {
            len = s - 1;
        } else {
            len = 2 * N + 1 - s;
        }
        total_threatened += len;
    }

    // Subtract overlaps: row & column
    for (const auto& [r, _] : row_map) {
        for (const auto& [c, _] : col_map) {
            if (occupied.count({r, c}) == 0) {
                total_threatened -= 1;
            }
        }
    }

    // Subtract overlaps: row & diag1
    for (const auto& [r, _] : row_map) {
        for (const auto& [d, _] : diag1_map) {
            i64 c = r - d;
            if (1 <= c && c <= N) {
                if (occupied.count({r, c}) == 0) {
                    total_threatened -= 1;
                }
            }
        }
    }

    // Subtract overlaps: row & diag2
    for (const auto& [r, _] : row_map) {
        for (const auto& [s, _] : diag2_map) {
            i64 c = s - r;
            if (1 <= c && c <= N) {
                if (occupied.count({r, c}) == 0) {
                    total_threatened -= 1;
                }
            }
        }
    }

    // Subtract overlaps: col & diag1
    for (const auto& [c, _] : col_map) {
        for (const auto& [d, _] : diag1_map) {
            i64 r = d + c;
            if (1 <= r && r <= N) {
                if (occupied.count({r, c}) == 0) {
                    total_threatened -= 1;
                }
            }
        }
    }

    // Subtract overlaps: col & diag2
    for (const auto& [c, _] : col_map) {
        for (const auto& [s, _] : diag2_map) {
            i64 r = s - c;
            if (1 <= r && r <= N) {
                if (occupied.count({r, c}) == 0) {
                    total_threatened -= 1;
                }
            }
        }
    }

    // Subtract overlaps: diag1 & diag2
    for (const auto& [d, _] : diag1_map) {
        for (const auto& [s, _] : diag2_map) {
            i64 r = (s + d) / 2;
            i64 c = (s - d) / 2;
            if ((s + d) % 2 != 0 || (s - d) % 2 != 0) continue;
            if (1 <= r && r <= N && 1 <= c && c <= N) {
                if (occupied.count({r, c}) == 0) {
                    total_threatened -= 1;
                }
            }
        }
    }

    // Add back overlaps of 3 types
    for (const auto& [r, _] : row_map) {
        for (const auto& [c, _] : col_map) {
            for (const auto& [d, _] : diag1_map) {
                if (r - c == d) {
                    if (occupied.count({r, c}) == 0) {
                        total_threatened += 1;
                    }
                }
            }
        }
    }

    for (const auto& [r, _] : row_map) {
        for (const auto& [c, _] : col_map) {
            for (const auto& [s, _] : diag2_map) {
                if (r + c == s) {
                    if (occupied.count({r, c}) == 0) {
                        total_threatened += 1;
                    }
                }
            }
        }
    }

    for (const auto& [r, _] : row_map) {
        for (const auto& [d, _] : diag1_map) {
            for (const auto& [s, _] : diag2_map) {
                i64 c1 = r - d;
                i64 c2 = s - r;
                if (c1 == c2 && 1 <= c1 && c1 <= N) {
                    if (occupied.count({r, c1}) == 0) {
                        total_threatened += 1;
                    }
                }
            }
        }
    }

    for (const auto& [c, _] : col_map) {
        for (const auto& [d, _] : diag1_map) {
            for (const auto& [s, _] : diag2_map) {
                i64 r1 = d + c;
                i64 r2 = s - c;
                if (r1 == r2 && 1 <= r1 && r1 <= N) {
                    if (occupied.count({r1, c}) == 0) {
                        total_threatened += 1;
                    }
                }
            }
        }
    }

    // Subtract overlap of all 4 types
    for (const auto& [r, _] : row_map) {
        for (const auto& [c, _] : col_map) {
            for (const auto& [d, _] : diag1_map) {
                for (const auto& [s, _] : diag2_map) {
                    if (r - c == d && r + c == s) {
                        if (occupied.count({r, c}) == 0) {
                            total_threatened -= 1;
                        }
                    }
                }
            }
        }
    }

    // Remove overcounted cells that have multiple attackers
    for (const auto& [pos, cnt] : row_map) {
        total_threatened -= (cnt - 1) * (4 * N - 4);
    }
    for (const auto& [pos, cnt] : col_map) {
        total_threatened -= (cnt - 1) * (4 * N - 4);
    }
    for (const auto& [pos, cnt] : diag1_map) {
        total_threatened -= (cnt - 1) * (4 * N - 4);
    }
    for (const auto& [pos, cnt] : diag2_map) {
        total_threatened -= (cnt - 1) * (4 * N - 4);
    }

    // Final answer
    i64 total_cells = N * N;
    i64 occupied_cells = M;
    i64 threatened_cells = total_threatened;

    // Each cell may be counted multiple times in threat count
    // We need to only count each threatened/occupied cell once
    set<Coord> threatened_set;

    for (const auto& [a, b] : occupied) {
        threatened_set.insert({a, b});
    }

    function<void(i64, i64)> add_diagonal1 = [&](i64 a, i64 b) {
        i64 d = a - b;
        for (i64 x = 1; x <= N; ++x) {
            i64 y = x - d;
            if (1 <= y && y <= N && (x != a || y != b)) {
                threatened_set.insert({x, y});
            }
        }
    };

    function<void(i64, i64)> add_diagonal2 = [&](i64 a, i64 b) {
        i64 s = a + b;
        for (i64 x = 1; x <= N; ++x) {
            i64 y = s - x;
            if (1 <= y && y <= N && (x != a || y != b)) {
                threatened_set.insert({x, y});
            }
        }
    };

    for (const auto& [a, b] : occupied) {
        // Row
        for (i64 y = 1; y <= N; ++y) {
            if (y != b) threatened_set.insert({a, y});
        }

        // Column
        for (i64 x = 1; x <= N; ++x) {
            if (x != a) threatened_set.insert({x, b});
        }

        // Diagonal 1
        add_diagonal1(a, b);

        // Diagonal 2
        add_diagonal2(a, b);
    }

    i64 safe_cells = total_cells - occupied_cells - threatened_set.size();

    cout << safe_cells << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define MAX_N 1000000000

struct Range {
    int x_start, x_end, y_start, y_end;
};

vector<Range> ranges;
int N, M;

bool is_safe(int x, int y) {
    for (auto& r : ranges) {
        if (r.x_start <= x && x <= r.x_end && r.y_start <= y && y <= r.y_end)
            return false;
    }
    return true;
}

void output_safe_region() {
    int cnt = 0;
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            if (is_safe(x, y)) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

void process_piece(int x, int y) {
    if (x + 2 <= N && y + 1 <= N) {
        ranges.push_back({x, x + 2, y, y + 1});
    }
    if (x + 1 <= N && y + 2 <= N) {
        ranges.push_back({x, x + 1, y, y + 2});
    }
    if (x - 1 >= 1 && y + 2 <= N) {
        ranges.push_back({x - 2, x - 1, y, y + 2});
    }
    if (x - 2 >= 1 && y + 1 <= N) {
        ranges.push_back({x - 2, x - 1, y, y + 1});
    }
    if (x - 2 >= 1 && y - 1 >= 1) {
        ranges.push_back({x - 2, x - 1, y - 1, y - 1});
    }
    if (x - 1 >= 1 && y - 2 >= 1) {
        ranges.push_back({x - 1, x - 1, y - 2, y - 1});
    }
    if (x + 1 <= N && y - 2 >= 1) {
        ranges.push_back({x + 1, x + 1, y - 2, y - 1});
    }
    if (x + 2 <= N && y - 1 >= 1) {
        ranges.push_back({x + 2, x + 1, y - 1, y - 1});
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        process_piece(a, b);
    }
    output_safe_region();
    return 0;
}
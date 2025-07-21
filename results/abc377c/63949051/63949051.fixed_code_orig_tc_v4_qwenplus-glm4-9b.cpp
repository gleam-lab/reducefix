#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000000;
int N, M;
vector<pair<int, int>> pieces;

struct Box {
    int x1, y1, x2, y2;
};

vector<vector<int>> grid;

void read_input() {
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        pieces.push_back({a, b});
    }
}

void calculate_boxes() {
    vector<Box> boxes;
    for (auto& p : pieces) {
        int x = p.first, y = p.second;
        // Determine the bounding box for the capture area
        // This is a simplification and might need adjustment based on problem statement
        Box box = {max(x - 3, 1), max(y - 3, 1), min(x + 3, N), min(y + 3, N)};
        boxes.push_back(box);
    }

    // Sort boxes by x1, then by y1
    sort(boxes.begin(), boxes.end(), [&](Box a, Box b) {
        if (a.x1 != b.x1) return a.x1 < b.x1;
        return a.y1 < b.y1;
    });

    // Calculate the total area covered by overlapping boxes
    int covered_area = 0;
    int last_x2 = 0, last_y2 = 0;

    for (const Box& box : boxes) {
        if (box.x1 > last_x2) {
            covered_area += (box.x1 - last_x2) * (box.y2 - last_y2);
        }
        last_x2 = max(last_x2, box.x2);
        last_y2 = max(last_y2, box.y2);
    }

    // Output the number of safe squares
    int total_squares = N * N;
    cout << total_squares - covered_area << endl;
}

int main() {
    read_input();
    calculate_boxes();
    return 0;
}
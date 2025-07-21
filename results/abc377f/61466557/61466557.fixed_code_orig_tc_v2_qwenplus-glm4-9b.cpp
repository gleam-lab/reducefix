#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int maxN = 1e9 + 2;
int n, m;
vector<pair<int, int>> pieces;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        pieces.push_back({x, y});
    }

    unordered_set<int> rows, cols, diagSum, diagDiff;

    for (auto &p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diagSum.insert(p.first + p.second);
        diagDiff.insert(p.first - p.second);
    }

    int totalCapture = rows.size() + cols.size() + diagSum.size() + diagDiff.size();
    int intersection = rows & cols;
    intersection.insert(diagSum.begin(), diagSum.end());
    intersection.insert(diagDiff.begin(), diagDiff.end());

    totalCapture -= intersection.size(); // Subtract the cells counted multiple times

    cout << n * n - totalCapture << endl; // Total cells minus affected cells

    return 0;
}
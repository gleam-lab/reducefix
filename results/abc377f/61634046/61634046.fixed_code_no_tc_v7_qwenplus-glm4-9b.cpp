#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

long long count_empty_squares(int N, const vector<pair<int, int>>& pieces) {
    unordered_set<int> row capturing_rows;
    unordered_set<int> col capturing_cols;
    unordered_set<pair<int, int>> capturing_dia1, capturing_dia2, capturing_rot1, capturing_rot2;

    for (auto& p : pieces) {
        int r = p.first;
        int c = p.second;

        capturing_rows.insert(r);
        capturing_cols.insert(c);
        capturing_dia1.insert(r - c);
        capturing_dia2.insert(r + c);
        capturing_rot1.insert(r - c + 1);
        capturing_rot2.insert(c - r + 1);
    }

    long long total_empty = 0;
    total_empty += N * N;

    // Subtract squares that are in capturing rows or columns
    total_empty -= capturing_rows.size() * N;
    total_empty -= capturing_cols.size() * N;

    // Subtract squares that are in diagonal capturing sets
    total_empty -= capturing_dia1.size();
    total_empty -= capturing_dia2.size();

    // Subtract squares that are in rotation capturing sets
    total_empty -= capturing_rot1.size();
    total_empty -= capturing_rot2.size();

    // Add back the overlap of capturing sets
    // Overlap with both row and column
    for (int r : capturing_rows) {
        total_empty += capturing_cols.count(r);
    }
    for (int c : capturing_cols) {
        total_empty += capturing_rows.count(c);
    }

    // Overlap with diagonal capturing sets
    for (int d : capturing_dia1) {
        int r = d + capturing_dia2.lower_bound(d) - 1;
        if (capturing_rows.count(r)) {
            total_empty++;
        }
    }
    for (int d : capturing_dia2) {
        int r = d - capturing_dia1.lower_bound(d) + 1;
        if (capturing_rows.count(r)) {
            total_empty++;
        }
    }

    return total_empty;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    cout << count_empty_squares(N, pieces) << endl;

    return 0;
}
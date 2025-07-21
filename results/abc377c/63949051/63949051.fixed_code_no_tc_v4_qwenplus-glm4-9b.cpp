#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    set<pair<int, int>> captured_squares;

    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        captured_squares.insert(pieces[i]);

        // Check the cells that can be captured by this piece
        if (pieces[i].first + 2 <= N && pieces[i].second + 1 <= N) {
            captured_squares.insert({pieces[i].first + 2, pieces[i].second + 1});
        }
        if (pieces[i].first + 1 <= N && pieces[i].second + 2 <= N) {
            captured_squares.insert({pieces[i].first + 1, pieces[i].second + 2});
        }
        if (pieces[i].first - 1 >= 1 && pieces[i].second + 2 <= N) {
            captured_squares.insert({pieces[i].first - 1, pieces[i].second + 2});
        }
        if (pieces[i].first - 2 >= 1 && pieces[i].second + 1 <= N) {
            captured_squares.insert({pieces[i].first - 2, pieces[i].second + 1});
        }
        if (pieces[i].first - 2 >= 1 && pieces[i].second - 1 >= 1) {
            captured_squares.insert({pieces[i].first - 2, pieces[i].second - 1});
        }
        if (pieces[i].first - 1 >= 1 && pieces[i].second - 2 >= 1) {
            captured_squares.insert({pieces[i].first - 1, pieces[i].second - 2});
        }
        if (pieces[i].first + 1 <= N && pieces[i].second - 2 >= 1) {
            captured_squares.insert({pieces[i].first + 1, pieces[i].second - 2});
        }
        if (pieces[i].first + 2 <= N && pieces[i].second - 1 >= 1) {
            captured_squares.insert({pieces[i].first + 2, pieces[i].second - 1});
        }
    }

    // Calculate the number of empty squares
    long long total_squares = N * N;
    long long empty_squares = total_squares - captured_squares.size();

    cout << empty_squares << endl;

    return 0;
}
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int M;
    cin >> M;

    set<pair<int, int>> pieces;
    for(int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        pieces.insert({x, y});
    }

    long long total_squares = static_cast<long long>(N) * N;
    long long occupied_squares = 0;

    for(auto& [x, y] : pieces) {
        if(x + 2 <= N && y + 1 <= N) ++occupied_squares;
        if(x + 1 <= N && y + 2 <= N) ++occupied_squares;
        if(x - 1 >= 1 && y + 2 <= N) ++occupied_squares;
        if(x - 2 >= 1 && y + 1 <= N) ++occupied_squares;
        if(x - 2 >= 1 && y - 1 >= 1) ++occupied_squares;
        if(x - 1 >= 1 && y - 2 >= 1) ++occupied_squares;
        if(x + 1 <= N && y - 2 >= 1) ++occupied_squares;
        if(x + 2 <= N && y - 1 >= 1) ++occupied_squares;
    }

    cout << total_squares - occupied_squares << endl;

    return 0;
}
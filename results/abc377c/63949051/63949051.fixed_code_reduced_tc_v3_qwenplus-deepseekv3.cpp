#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;
    
    set<pair<long long, long long>> attacked;
    vector<pair<long long, long long>> pieces(M);

    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        attacked.insert(pieces[i]);
    }

    for (const auto &p : pieces) {
        long long i = p.first;
        long long j = p.second;

        if (i + 2 <= N && j + 1 <= N) {
            attacked.insert({i + 2, j + 1});
        }
        if (i + 1 <= N && j + 2 <= N) {
            attacked.insert({i + 1, j + 2});
        }
        if (i - 1 >= 1 && j + 2 <= N) {
            attacked.insert({i - 1, j + 2});
        }
        if (i - 2 >= 1 && j + 1 <= N) {
            attacked.insert({i - 2, j + 1});
        }
        if (i - 2 >= 1 && j - 1 >= 1) {
            attacked.insert({i - 2, j - 1});
        }
        if (i - 1 >= 1 && j - 2 >= 1) {
            attacked.insert({i - 1, j - 2});
        }
        if (i + 1 <= N && j - 2 >= 1) {
            attacked.insert({i + 1, j - 2});
        }
        if (i + 2 <= N && j - 1 >= 1) {
            attacked.insert({i + 2, j - 1});
        }
    }

    long long total_squares = N * N;
    long long unsafe_squares = attacked.size();
    long long safe_squares = total_squares - unsafe_squares;

    cout << safe_squares << '\n';

    return 0;
}
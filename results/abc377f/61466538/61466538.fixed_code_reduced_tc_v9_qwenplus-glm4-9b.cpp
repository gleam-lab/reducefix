#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> pos(M);
    for (long long i = 0; i < M; ++i) {
        cin >> pos[i].first >> pos[i].second;
    }

    long long free_squares = N * N; // start with all squares free

    // Check horizontal and vertical capture
    for (int i = 0; i < M; ++i) {
        free_squares -= N - 1; // all squares in row and column are captured
    }

    // Check diagonal captures
    set<pair<long long, long long>> seen;
    // Diagonal i+j
    for (int i = 0; i < M; ++i) {
        auto key = make_pair(pos[i].first + pos[i].second, pos[i].second - pos[i].first);
        free_squares--;
        seen.insert(key);
    }
    // Diagonal i-j
    for (int i = 0; i < M; ++i) {
        auto key = make_pair(pos[i].first - pos[i].second, pos[i].first + pos[i].second);
        free_squares--;
        seen.insert(key);
    }

    // Count duplicate captures
    for (int i = 0; i < M; ++i) {
        auto key1 = make_pair(pos[i].first + pos[i].second, pos[i].second - pos[i].first);
        auto key2 = make_pair(pos[i].first - pos[i].second, pos[i].first + pos[i].second);
        if (seen.count(key1) > 1 || seen.count(key2) > 1) {
            free_squares++;
        }
    }

    cout << free_squares << endl;
    return 0;
}
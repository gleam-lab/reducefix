#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> pieces;
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    long long count = 0;
    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= N; ++j) {
            bool canPlace = true;
            if (pieces.find({i + 2, j + 1}) != pieces.end()) canPlace = false;
            if (pieces.find({i + 1, j + 2}) != pieces.end()) canPlace = false;
            if (pieces.find({i - 1, j + 2}) != pieces.end()) canPlace = false;
            if (pieces.find({i - 2, j + 1}) != pieces.end()) canPlace = false;
            if (pieces.find({i - 2, j - 1}) != pieces.end()) canPlace = false;
            if (pieces.find({i - 1, j - 2}) != pieces.end()) canPlace = false;
            if (pieces.find({i + 1, j - 2}) != pieces.end()) canPlace = false;
            if (pieces.find({i + 2, j - 1}) != pieces.end()) canPlace = false;
            if (canPlace) ++count;
        }
    }

    cout << count << endl;

    return 0;
}
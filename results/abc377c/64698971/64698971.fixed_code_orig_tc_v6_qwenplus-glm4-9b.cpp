#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> banned_positions;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        --pieces[i].first; // è½¬æ¢ä¸º0-basedç´¢å¼
        --pieces[i].second;
    }

    // è®°å½æ¯ä¸ªæ£å­çå½±ååºå
    for (auto &p : pieces) {
        vector<pair<int, int>> capture_areas = {
            {p.first, p.second}, {p.first, p.second + 1}, {p.first, p.second + 2},
            {p.first + 1, p.second + 2}, {p.first - 1, p.second + 2},
            {p.first - 2, p.second + 1}, {p.first - 2, p.second},
            {p.first - 2, p.second - 1}, {p.first - 1, p.second - 2},
            {p.first + 1, p.second - 2}, {p.first + 2, p.second - 1}
        };

        for (auto &area : capture_areas) {
            if (area.first < 0 || area.first >= N || area.second < 0 || area.second >= N) continue; // å¿½ç¥æ æåºå
            banned_positions.insert(make_pair(area.first, area.second));
        }
    }

    // è®¡ç®æ»ç©ºä½åå¯æ¾ç½®ä½ç½®
    long long total_positions = N * N;
    long long free_positions = total_positions - banned_positions.size();

    cout << free_positions << endl;

    return 0;
}
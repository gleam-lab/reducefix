#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int dx[8] = {1, 1, 1, -1, -1, -1, 1, -1};
const int dy[8] = {1, -1, -1, -1, 1, 1, 1, -1};

bool is_occupied(int a, int b, const vector<pair<int, int>>& pieces) {
    for (const auto& p : pieces) {
        if (p.first == a && p.second == b) {
            return true;
        }
    }
    return false;
}

bool is_safe(int a, int b, const set<pair<int, int>>& occupied) {
    for (int i = 0; i < 8; ++i) {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x >= 1 && x <= 1000000000 && y >= 1 && y <= 1000000000) {
            if (occupied.count({x, y})) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    sort(pieces.begin(), pieces.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first * 1000000000 + a.second < b.first * 1000000000 + b.second;
    });
    
    vector<set<pair<int, int>>> occupied;
    for (const auto& p : pieces) {
        occupied.push_back(set<pair<int, int>>());
        for (int i = 0; i < 8; ++i) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (x >= 1 && x <= 1000000000 && y >= 1 && y <= 1000000000) {
                occupied.back().insert({x, y});
            }
        }
    }
    
    int total = n * n;
    int not_occupied = 0;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            bool is_occ = is_occupied(i, j, pieces);
            bool can_be_occupied = false;
            for (int k = 0; k < m; ++k) {
                if (!occupied[k].count({i, j}) && is_safe(i, j, occupied[k])) {
                    can_be_occupied = true;
                    break;
                }
            }
            if (!is_occ && can_be_occupied) {
                not_occupied++;
            }
        }
    }
    
    cout << not_occupied << endl;
    
    return 0;
}
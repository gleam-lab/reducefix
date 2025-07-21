#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    set<pair<long long, long long>> occupied;
    vector<pair<long long, long long>> pieces(m);
    vector<pair<long long, long long>> captures;

    // Read occupied pieces and calculate possible captures
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        occupied.insert({a, b});

        // Calculate possible captures for each piece
        for (int j = 0; j < 8; j++) {
            long long dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
            long long dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
            long long x = a + dx[j];
            long long y = b + dy[j];
            if (x > 0 && x <= n && y > 0 && y <= n) {
                captures.push_back({x, y});
            }
        }
    }

    // Subtract captured pieces from total
    for (auto& capture : captures) {
        if (occupied.count(capture)) {
            occupied.erase(capture);
        }
    }

    // Output the count of available empty squares
    cout << (n * n) - occupied.size() << endl;

    return 0;
}
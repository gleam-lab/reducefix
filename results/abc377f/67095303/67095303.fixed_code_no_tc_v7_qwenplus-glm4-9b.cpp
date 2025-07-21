#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<pair<int, int>> pieces;

bool can_place(int x, int y) {
    for (auto& p : pieces) {
        int a, b;
        tie(a, b) = p;
        // Check if (x, y) can be captured by (a, b)
        if (a == x || b == y || a + b == x + y || a - b == x - y) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pieces.push_back({a, b});
    }

    int valid_positions = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (can_place(i, j)) {
                valid_positions++;
            }
        }
    }

    cout << valid_positions << endl;
    return 0;
}
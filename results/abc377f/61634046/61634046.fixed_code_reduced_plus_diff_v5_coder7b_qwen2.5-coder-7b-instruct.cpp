#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for(int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    sort(pieces.begin(), pieces.end());

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            bool valid = true;
            for(const auto& p : pieces) {
                if(p.first == i || p.second == j || p.first + p.second == i + j || p.first - p.second == i - j) {
                    valid = false;
                    break;
                }
            }
            if(valid) ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}
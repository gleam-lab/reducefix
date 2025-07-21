#include <bits/stdc++.h>
using namespace std;

bool isValidMove(long long x, long long y, long long N) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    long long n, m;
    cin >> n >> m;
    unordered_set<string> positions;

    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        string pos = to_string(a) + "," + to_string(b);
        positions.insert(pos);
    }

    long long ans = 0;
    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            string pos = to_string(i) + "," + to_string(j);
            if(positions.find(pos) == positions.end()) {
                bool valid = true;
                for(long long di = -2; di <= 2; ++di) {
                    for(long long dj = -2; dj <= 2; ++dj) {
                        if(abs(di) + abs(dj) != 3) continue;
                        long long ni = i + di, nj = j + dj;
                        string newPos = to_string(ni) + "," + to_string(nj);
                        if(isValidMove(ni, nj, n) && positions.find(newPos) != positions.end()) {
                            valid = false;
                            break;
                        }
                    }
                    if(!valid) break;
                }
                if(valid) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
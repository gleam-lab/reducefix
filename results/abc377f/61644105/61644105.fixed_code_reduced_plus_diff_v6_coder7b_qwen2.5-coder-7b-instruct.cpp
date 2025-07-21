#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    set<long long> rowThreats, colThreats, diag1Threats, diag2Threats;
    vector<pair<long long, long long>> pieces(m);

    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        rowThreats.insert(pieces[i].first);
        colThreats.insert(pieces[i].second);
        diag1Threats.insert(pieces[i].first + pieces[i].second);
        diag2Threats.insert(pieces[i].first - pieces[i].second);
    }

    long long validPositions = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (!rowThreats.count(i) && !colThreats.count(j) 
                && !diag1Threats.count(i + j) && !diag2Threats.count(i - j)) {
                ++validPositions;
            }
        }
    }

    cout << validPositions << endl;
    return 0;
}
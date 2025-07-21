#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    vector<long long> row(M), col(M);
    vector<long long> diag1(M), diag2(M); // i-j, i+j

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        row[i] = a;
        col[i] = b;
        diag1[i] = a - b;
        diag2[i] = a + b;
    }

    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    sort(diag1.begin(), diag1.end());
    sort(diag2.begin(), diag2.end());

    auto ur = unique(row.begin(), row.end());
    auto uc = unique(col.begin(), col.end());
    auto ud1 = unique(diag1.begin(), diag1.end());
    auto ud2 = unique(diag2.begin(), diag2.end());

    row.erase(ur, row.end());
    col.erase(uc, col.end());
    diag1.erase(ud1, diag1.end());
    diag2.erase(ud2, diag2.end());

    long long R = row.size();
    long long C = col.size();
    long long D1 = diag1.size();
    long long D2 = diag2.size();

    // Total number of threatened positions
    long long totalThreatened =
        N * R + N * C + N * D1 + N * D2
        - R * C
        - R * D1
        - R * D2
        - C * D1
        - C * D2
        - D1 * D2
        + R * D1 * D2 / N
        + C * D1 * D2 / N
        + R * C * D2 / N
        + R * C * D1 / N
        - R * C * D1 * D2 / (N * N);

    long long totalPositions = N * N;
    long long occupied = M;
    long long result = totalPositions - totalThreatened - occupied;

    cout << result << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    set<long long> rows, cols, sumDiag, diffDiag;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        sumDiag.insert(a + b);
        diffDiag.insert(a - b);
    }

    // Helper lambda to count unique elements in a sorted array
    auto countUnique = [](const vector<long long>& v) {
        return distance(v.begin(), unique(v.begin(), v.end()));
    };

    // Convert sets to vectors and sort them
    vector<long long> rowVec(rows.begin(), rows.end());
    vector<long long> colVec(cols.begin(), cols.end());
    vector<long long> sumVec(sumDiag.begin(), sumDiag.end());
    vector<long long> diffVec(diffDiag.begin(), diffDiag.end());

    sort(rowVec.begin(), rowVec.end());
    sort(colVec.begin(), colVec.end());
    sort(sumVec.begin(), sumVec.end());
    sort(diffVec.begin(), diffVec.end());

    // Inclusion-Exclusion Principle

    long long attacked = 0;

    // Rows
    attacked += N * rowVec.size();
    // Columns
    attacked += N * colVec.size();
    // Sum diagonals: each contains up to N points
    for (long long s : sumVec) {
        long long cnt = min(s, 2 * N - s);
        attacked += cnt;
    }
    // Diff diagonals: each contains up to N points
    for (long long d : diffVec) {
        long long lo = max(1LL - (N - d), 1LL);
        long long hi = min(N, N - d + 1);
        long long cnt = max(0LL, hi - lo + 1);
        attacked += cnt;
    }

    // Subtract overlaps
    // Row & Column
    attacked -= (long long)rowVec.size() * (long long)colVec.size();

    // Row & SumDiag
    for (long long r : rowVec) {
        for (long long s : sumVec) {
            long long c = s - r;
            if (1 <= c && c <= N)
                attacked--;
        }
    }

    // Row & DiffDiag
    for (long long r : rowVec) {
        for (long long d : diffVec) {
            long long c = r - d;
            if (1 <= c && c <= N)
                attacked--;
        }
    }

    // Col & SumDiag
    for (long long c : colVec) {
        for (long long s : sumVec) {
            long long r = s - c;
            if (1 <= r && r <= N)
                attacked--;
        }
    }

    // Col & DiffDiag
    for (long long c : colVec) {
        for (long long d : diffVec) {
            long long r = d + c;
            if (1 <= r && r <= N)
                attacked--;
        }
    }

    // SumDiag & DiffDiag
    for (long long s : sumVec) {
        for (long long d : diffVec) {
            long long r = (s + d) / 2;
            long long c = (s - d) / 2;
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N)
                attacked--;
        }
    }

    // Add back triple overlaps
    for (long long r : rowVec) {
        for (long long c : colVec) {
            if (sumDiag.count(r + c))
                attacked++;
            if (diffDiag.count(r - c))
                attacked++;
        }
    }

    for (long long r : rowVec) {
        for (long long s : sumVec) {
            long long c = s - r;
            if (1 <= c && c <= N && diffDiag.count(r - c))
                attacked++;
        }
    }

    for (long long c : colVec) {
        for (long long s : sumVec) {
            long long r = s - c;
            if (1 <= r && r <= N && diffDiag.count(r - c))
                attacked++;
        }
    }

    for (long long s : sumVec) {
        for (long long d : diffVec) {
            long long r = (s + d) / 2;
            long long c = (s - d) / 2;
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0 &&
                1 <= r && r <= N && 1 <= c && c <= N &&
                rows.count(r) && cols.count(c))
                attacked++;
        }
    }

    // Subtract quadruple overlaps
    for (long long r : rowVec) {
        for (long long c : colVec) {
            if (sumDiag.count(r + c) && diffDiag.count(r - c))
                attacked--;
        }
    }

    long long totalEmpty = N * N - M;
    long long result = totalEmpty - attacked;

    cout << result << endl;

    return 0;
}
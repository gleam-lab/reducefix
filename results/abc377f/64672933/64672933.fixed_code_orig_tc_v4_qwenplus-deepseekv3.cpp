#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    unordered_set<i64> rows, cols, diags, anti_diags;
    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diags.insert(a + b);
        anti_diags.insert(a - b);
    }

    i64 unsafe = 0;
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe += diags.size() * N;
    unsafe += anti_diags.size() * N;

    // Subtract intersections between rows and cols (they are counted twice)
    unsafe -= rows.size() * cols.size();

    // Subtract intersections between rows and diags
    for (i64 d : diags) {
        for (i64 r : rows) {
            i64 c = d - r;
            if (cols.count(c)) {
                unsafe--;
            }
        }
    }

    // Subtract intersections between rows and anti-diags
    for (i64 ad : anti_diags) {
        for (i64 r : rows) {
            i64 c = r - ad;
            if (cols.count(c)) {
                unsafe--;
            }
        }
    }

    // Subtract intersections between cols and diags
    for (i64 d : diags) {
        for (i64 c : cols) {
            i64 r = d - c;
            if (rows.count(r)) {
                unsafe--;
            }
        }
    }

    // Subtract intersections between cols and anti-diags
    for (i64 ad : anti_diags) {
        for (i64 c : cols) {
            i64 r = ad + c;
            if (rows.count(r)) {
                unsafe--;
            }
        }
    }

    // Subtract intersections between diags and anti-diags
    for (i64 d : diags) {
        for (i64 ad : anti_diags) {
            if ((d + ad) % 2 == 0) {
                i64 r = (d + ad) / 2;
                i64 c = (d - ad) / 2;
                if (rows.count(r) && cols.count(c)) {
                    unsafe--;
                }
            }
        }
    }

    // Now, unsafe is the total number of distinct squares under attack
    // However, some squares might be counted multiple times in the initial sum, but we've subtracted overlaps.

    // The total safe squares is N*N - unsafe - M (since M squares are already occupied)
    i64 total_safe = N * N - unsafe - M;
    cout << max(total_safe, 0LL) << "\n";

    return 0;
}
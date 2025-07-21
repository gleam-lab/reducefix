#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::vector<std::pair<long long, long long>> pieces(m);

    for (long long i = 0; i < m; ++i) {
        std::cin >> pieces[i].first >> pieces[i].second;
    }

    std::set<long long> rows, cols, diag1, diag2;
    for (const auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first + p.second);
        diag2.insert(p.first - p.second);
    }

    // Calculate the number of squares that are fully covered by existing pieces
    long long total_covered = rows.size() * n + cols.size() * n - static_cast<long long>(rows.size() * cols.size());
    total_covered += diag1.size() * n + diag2.size() * n - static_cast<long long>(diag1.size() * diag2.size());

    // Subtract the diagonal captures from each other
    total_covered -= diag1.size() * diag1.size();
    total_covered -= diag2.size() * diag2.size();

    // Calculate the number of squares where the new piece would be captured by an existing piece
    long long covered_by diagnostics[2];
    covered_by[0] = diag1.size() * diag2.size();
    covered_by[1] = diag2.size() * diag1.size();

    // Calculate the number of valid squares
    long long valid_squares = n * n - total_covered;
    valid_squares -= covered_by[0];
    valid_squares -= covered_by[1];

    std::cout << valid_squares << std::endl;

    return 0;
}
function solve(N, M):
    row_coverage = new unordered_map<int, int>
    col_coverage = new unordered_map<int, int>
    diag_coverage_d1 = new unordered_map<int, int>
    diag_coverage_d2 = new unordered_map<int, int>

    for each piece (a_k, b_k):
        add a_k to row_coverage
        add b_k to col_coverage
        add a_k + b_k to diag_coverage_d1
        add a_k - b_k to diag_coverage_d2

    total = N * N
    for each key in row_coverage:
        total -= N
        if key in col_coverage:
            total -= 1
    for each key in diag_coverage_d1:
        total -= N
        if key in diag_coverage_d2:
            total -= 1

    print total
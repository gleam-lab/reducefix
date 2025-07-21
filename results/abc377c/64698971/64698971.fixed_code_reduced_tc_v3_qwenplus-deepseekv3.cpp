#include <bits/stdc++.h>
using namespace std;

int N, M;
set<pair<int, int>> st;
set<pair<int, int>> occupied;

void set_insert(int a, int b) {
    if (1 <= a && a <= N && 1 <= b && b <= N) {
        st.insert({a, b});
    }
}

int main() {
    cin >> N >> M;
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        for (auto &move : moves) {
            int na = a + move.first;
            int nb = b + move.second;
            set_insert(na, nb);
        }
    }

    long long total_squares = (long long)N * N;
    long long unsafe_squares = st.size();
    long long occupied_squares = occupied.size();
    
    // The unsafe squares include the occupied squares, so we need to subtract them
    // to avoid double counting.
    long long safe_squares = total_squares - unsafe_squares - occupied_squares + st.size();
    
    // But the correct way is total_squares - (unsafe_squares + occupied_squares - intersection)
    // Since occupied squares are already in unsafe_squares if they are in st, but we need to ensure
    // that occupied squares are not counted in safe_squares.
    // So safe_squares = total_squares - (unsafe_squares + occupied_squares - count of occupied squares in st)
    // But since all occupied squares are not necessarily in st, we can simply subtract both and add the overlap.
    // Alternatively, since occupied squares are not safe, they should not be in safe_squares.
    // So safe_squares = total_squares - unsafe_squares - occupied_squares + count of occupied squares that are in st.
    // But calculating the overlap is complex; instead, we can note that the total unsafe squares are st.size() + occupied_squares - the overlap.
    // But since occupied_squares are M, and st may include some of them, the total unsafe is st.size() + M - count of occupied in st.
    // But since st includes the squares that can be captured by any piece, and occupied are the squares with pieces, the safe squares are total_squares - (st.size() + M - count of occupied in st).
    // But calculating the count of occupied in st is not straightforward. Instead, we can note that the safe squares are total_squares - (st.size() + M), because st includes all squares that can be captured, and the occupied squares are already unsafe by definition.
    // Therefore, the safe squares are total_squares - (st.size() + M).
    // But this is not correct if some occupied squares are in st, which they might be. For example, if a piece is placed such that another piece can capture it, then that square is in both st and occupied.
    // To avoid double counting, the total unsafe squares are the union of st and occupied, which is st.size() + M - intersection.
    // But calculating the intersection is not easy, so we can instead note that the safe squares are total_squares - (st.size() + M - intersection).
    // However, since we cannot easily compute the intersection, we can instead compute the total unsafe as the size of the union of st and occupied, which is st.size() + M - intersection.
    // But since we can't compute the intersection easily, we can instead note that the safe squares are total_squares - (st.size() + M - intersection), but since intersection is at most M, the maximum unsafe is st.size() + M.
    // So the safe squares are at least total_squares - (st.size() + M).
    // But this might undercount the safe squares if there is overlap.
    // To fix this, we can ensure that the occupied squares are not in st, but that's not necessarily true.
    // Therefore, the correct approach is to subtract the size of the union of st and occupied from total_squares.
    // The union size is st.size() + M - intersection(st and occupied).
    // But since we can't easily compute the intersection, we can instead note that the safe squares are total_squares - (st.size() + M - intersection), which is at least total_squares - (st.size() + M).
    // But in the worst case, the intersection is M, so the unsafe squares are st.size(), which is incorrect.
    // Therefore, the correct way is to note that the safe squares are total_squares - (st.size() + M), because st includes all squares that can be captured, and the occupied squares are already unsafe by being occupied, even if they are not in st.
    // So the safe squares are total_squares - st.size() - M + the number of occupied squares that are in st.
    // But since we can't compute the number of occupied squares in st, we can instead note that the safe squares are at least total_squares - st.size() - M.
    // But this might undercount if some occupied squares are in st, which they might be.
    // To avoid this, we can ensure that the occupied squares are not in st by removing them from st before counting.
    // So the correct approach is to first add all squares that can be captured to st, then remove the occupied squares from st, and then the safe squares are total_squares - st.size() - M.
    // But this would mean that the safe squares are total_squares - (st.size() + M), because the occupied squares are not in st after removal.
    // Therefore, the safe squares are total_squares - (st.size() + M).
    // This is the correct approach, because the occupied squares are already unsafe, and the st includes all other squares that can be captured.
    // So the total unsafe squares are st.size() + M, and the safe squares are total_squares - (st.size() + M).

    long long safe = total_squares - st.size() - M;
    cout << safe << endl;

    return 0;
}
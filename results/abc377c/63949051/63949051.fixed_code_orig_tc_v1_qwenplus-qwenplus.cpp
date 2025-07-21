// C - Avoid Knight Attack

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <tuple>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

#define INF 1000000000
#define LINF 1000000000000000000LL

#define fi first
#define se second

#define i32 int
#define i64 long long
#define i128 long long

#define u32 unsigned int
#define u64 unsigned long long
#define u128 unsigned long long

#define f32 float
#define f64 double
#define f128 long double

#define str string
#define vec vector
#define cc const char *

#define all(x) x.begin(), x.end() // その配列の最初から最後
#define len(x) x.size()           // その配列の要素数
#define elif else if              // 見ての通り

#define FOR_U(r, b, e, s) for (i128 r = (i128)b; r < (i128)e; r += (i128)s) // 数字増加のfor
#define FOR_L(r, b, e, s) for (i128 r = (i128)b; r > (i128)e; r -= (i128)s) // 数字減少のfor
#define FOR_R(r, b) for (auto r : b)                                        // 範囲ベースfor
#define loop while (true)                                                   // 無限ループ

namespace mine
{

    // 標準出力を扱いやすくする関数(T)
    template <typename T>
    inline void out(T out_data, string end = "\n")
    {
        cout << out_data << end;
    }

    // 標準出力を扱いやすくする関数(vector<T>)
    template <typename T>
    inline void out(vector<T> &out_data, string sep = " ", string end = "\n")
    {
        for (auto &value : out_data)
        {
            cout << value << sep;
        }
        cout << end;
    }

    // 標準出力を扱いやすくする関数(vector<pair<T>>)
    template <typename T, typename U>
    inline void out(vector<pair<T, U>> &let, string sep = " ", string end = "\n")
    {
        for (auto &l : let)
        {
            cout << l.fi << sep << l.se << end;
        }
    }

    // 標準出力を扱いやすくする関数(vector<vector<T>>)
    template <typename T>
    inline void out(vector<vector<T>> &out_data, string sep = " ", string end = "\n")
    {
        for (auto &value_v : out_data)
        {
            for (auto &value_s : value_v)
            {
                cout << value_s << sep;
            }
            cout << end;
        }
    }

    // 標準入力を扱いやすくする関数(T)
    template <typename T>
    inline void in(T &let)
    {
        cin >> let;
    }

    // 標準入力を扱いやすくする関数(vector<T>)
    template <typename T>
    inline void in(vector<T> &let)
    {
        for (auto &l : let)
        {
            cin >> l;
        }
    }

    // 標準入力を扱いやすくする関数(vector<pair<T>>)
    template <typename T, typename U>
    inline void in(vector<pair<T, U>> &let)
    {
        for (auto &l : let)
        {
            cin >> l.fi;
            cin >> l.se;
        }
    }

}

using namespace mine;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N;
    i64 piece_num;
    in(N);
    in(piece_num);

    set<pair<i64, i64>> placed_pieces;
    set<pair<i64, i64>> attacked_positions;

    for(i64 i = 0; i < piece_num; ++i){
        i64 a, b;
        cin >> a >> b;
        placed_pieces.insert({a, b});
    }

    vector<pair<i64, i64>> knight_moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for(const auto& p : placed_pieces){
        for(const auto& move : knight_moves){
            i64 ni = p.fi + move.fi;
            i64 nj = p.se + move.se;
            if(ni >= 1 && ni <= N && nj >= 1 && nj <= N){
                attacked_positions.insert({ni, nj});
            }
        }
    }

    // 自分の駒を置けるマスの数 = 全マス数 - 駒が既に存在する or 攻撃されるマスの数
    i128 total_cells = (i128)N * (i128)N;
    i128 used_or_attacked = placed_pieces.size() + attacked_positions.size();
    
    // 攻撃されるマスの中にすでに駒がある場合を除く
    i64 overlap = 0;
    for(const auto& pos : attacked_positions){
        if(placed_pieces.count(pos)){
            overlap++;
        }
    }

    i128 result = total_cells - placed_pieces.size() - (attacked_positions.size() - overlap);
    cout << result << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define INF 1000000000
#define LINF 1000000000000000000

#define fi first
#define se second

#define i32 int
#define i64 long long

#define u32 unsigned int
#define u64 unsigned long long

#define f32 float
#define f64 double
#define f128 long double

#define str string
#define vec vector
#define cc const char *

#define all(x) x.begin(), x.end() // その配列の最初から最後
#define len(x) x.size()           // その配列の要素数
#define elif else if              // 見ての通り

#define FOR_U(r, b, e, s) for (u64 r = (u64)b; r < (u64)e; r += (u64)s) // 数字増加のfor
#define FOR_L(r, b, e, s) for (u64 r = (u64)b; r > (u64)e; r -= (u64)s) // 数字減少のfor
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

    u64 N;
    in(N);

    u64 piece_num;
    in(piece_num);

    vector<pair<u64, u64>> pieces(piece_num);
    in(pieces);

    set<pair<u64, u64>> anti_dup;

    FOR_R(p, pieces)
    {
        anti_dup.insert(make_pair(p.fi, p.se));

        if (p.fi + 2 <= N && p.se + 1 <= N)
        {
            anti_dup.insert(make_pair(p.fi + 2, p.se + 1));
        }

        if (p.fi + 1 <= N && p.se + 2 <= N)
        {
            anti_dup.insert(make_pair(p.fi + 1, p.se + 2));
        }

        if (p.fi - 1 >= 1 && p.se + 2 <= N)
        {
            anti_dup.insert(make_pair(p.fi - 1, p.se + 2));
        }

        if (p.fi - 2 >= 1 && p.se + 1 <= N)
        {
            anti_dup.insert(make_pair(p.fi - 2, p.se + 1));
        }

        if (p.fi - 2 >= 1 && p.se - 1 >= 1)
        {
            anti_dup.insert(make_pair(p.fi - 2, p.se - 1));
        }

        if (p.fi - 1 >= 1 && p.se - 2 >= 1)
        {
            anti_dup.insert(make_pair(p.fi - 1, p.se - 2));
        }

        if (p.fi + 1 <= N && p.se - 2 >= 1)
        {
            anti_dup.insert(make_pair(p.fi + 1, p.se - 2));
        }

        if (p.fi + 2 <= N && p.se - 1 >= 1)
        {
            anti_dup.insert(make_pair(p.fi + 2, p.se - 1));
        }
    }

    u64 total_squares = N * N;
    u64 invalid_squares = anti_dup.size();
    u64 valid_squares = total_squares - invalid_squares;

    out(valid_squares);

    return 0;
}
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
#define LINF 1000000000000000000

#define fi first
#define se second

#define i32 int
#define i64 long int
#define i128 long long

#define u32 unsigned int
#define u64 unsigned long int
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

    i32 N;
    in(N);

    i32 piece_num;
    in(piece_num);

    unordered_set<long long> anti_dup;

    FOR_U(_, 0, piece_num, 1)
    {
        i32 a, b;
        in(a);
        in(b);

        long long pos = static_cast<long long>(a - 1) * N + b;
        anti_dup.insert(pos);

        if (a + 2 <= N && b + 1 <= N)
        {
            pos = static_cast<long long>((a + 2) - 1) * N + (b + 1);
            anti_dup.insert(pos);
        }

        if (a + 1 <= N && b + 2 <= N)
        {
            pos = static_cast<long long>((a + 1) - 1) * N + (b + 2);
            anti_dup.insert(pos);
        }

        if (a - 1 >= 1 && b + 2 <= N)
        {
            pos = static_cast<long long>((a - 1) - 1) * N + (b + 2);
            anti_dup.insert(pos);
        }

        if (a - 2 >= 1 && b + 1 <= N)
        {
            pos = static_cast<long long>((a - 2) - 1) * N + (b + 1);
            anti_dup.insert(pos);
        }

        if (a - 2 >= 1 && b - 1 >= 1)
        {
            pos = static_cast<long long>((a - 2) - 1) * N + (b - 1);
            anti_dup.insert(pos);
        }

        if (a - 1 >= 1 && b - 2 >= 1)
        {
            pos = static_cast<long long>((a - 1) - 1) * N + (b - 2);
            anti_dup.insert(pos);
        }

        if (a + 1 <= N && b - 2 >= 1)
        {
            pos = static_cast<long long>((a + 1) - 1) * N + (b - 2);
            anti_dup.insert(pos);
        }

        if (a + 2 <= N && b - 1 >= 1)
        {
            pos = static_cast<long long>((a + 2) - 1) * N + (b - 1);
            anti_dup.insert(pos);
        }
    }

    out(static_cast<long long>(N * N) - static_cast<long long>(anti_dup.size()));

    return 0;
}
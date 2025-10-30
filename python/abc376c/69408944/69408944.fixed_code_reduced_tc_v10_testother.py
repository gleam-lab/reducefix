import heapq

N = int(input())
A = sorted(map(int, input().split()), reverse=True)  # おもちゃのサイズを降順
B = sorted(map(int, input().split()), reverse=True)  # 箱のサイズを降順

# 貪欲法：大きいおもちゃから、それ以下の最大の箱を割り当てる
box_index = 0
min_required_size = 0

# 各玩具に対して、既存の箱で収まるか確認
for toy_size in A:
    if box_index < len(B) and B[box_index] >= toy_size:
        # この箱を使える
        box_index += 1
    else:
        # 新しい箱が必要。必要な最小サイズはこのおもちゃのサイズ以上。
        min_required_size = toy_size
        break
else:
    # 全てのおもちゃが既存の箱に入った → 新しい箱は何でも良いが、最小なので1で十分？
    # しかし問題は「最小のx」を求めること。すべての玩具が既存の箱に入るなら、xは1でも良いが、
    # 実際には使わないが、「存在する」ので最小サイズは1？→いや、使わないが条件を満たすxは任意。
    # しかし、全ての玩具が元の箱に入るので、新しい箱のサイズは1で十分（空でも良い）。
    # だが、問題文：「各おもちゃはサイズ以上の箱にしか入れられない」→新しい箱が空でも、x>=1ならOK。
    # よって、最小のxは1。
    # しかし、上記ループですべて処理された＝新しい箱を使わずに済む → x は 1 でよい？
    # いや、実際には新しい箱は一つ買わなければならない（ステップ1）。
    # そしてすべての玩具が他の箱に入った場合、新しい箱は空になるが、それは許される。
    # よって、新しい箱のサイズは、どの玩具も入らない可能性があるが、少なくとも1以上であれば問題ない。
    # 最小の正整数xは1。
    # しかし、例えばA=[1,2], B=[2,3] のとき、Bの2と3で1と2が入る。新しい箱は空。x=1でよい。
    print(1)
    exit()

# min_required_size > 0 ということは、新しい箱が必要な玩具がある
# その玩具を新しい箱に入れる必要があるので、x >= min_required_size
# では、他の残った玩具はどうなるか？

# ここで重要な点：新しい箱は1つだけ。それをx = min_required_sizeとして使う。
# 残りの玩具を、残った既存の箱に割り当てられるか？

# 再度シミュレーション：新しい箱に「min_required_sizeの玩具」を入れる。
# 残りのN-1個の玩具を、N-1個の既存の箱に割り当てられるか？

# 既存の箱のうち、box_indexまで使った（割り当て済み）。残りは B[box_index:] （降順）
# 残りの玩具：Aのうち、min_required_size以外で、かつまだ割り当てられていないもの。

# 実際に貪欲に割り当て直す
used_new_box = False
assigned_count = 0
available_boxes = B[box_index:]  # まだ使っていない既存の箱（降順）
remaining_toys = []

for toy_size in A:
    if not used_new_box and toy_size == min_required_size:
        # 新しい箱を使う（最初に見つかったmin_required_sizeを使う）
        used_new_box = True
        continue
    remaining_toys.append(toy_size)

# 残りの玩具を降順、残りの箱を降順にして貪欲に割り当て
remaining_toys.sort(reverse=True)
available_boxes.sort(reverse=True)

box_ptr = 0
for toy in remaining_toys:
    if box_ptr < len(available_boxes) and available_boxes[box_ptr] >= toy:
        box_ptr += 1
    else:
        # 残りの箱では足りない
        print(-1)
        exit()

# 全て割り当てられた
print(min_required_size)
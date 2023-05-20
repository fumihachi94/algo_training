import sys
from sys import stdin

# # [1] 通常Input
data1 = stdin.readline().rstrip()
data2 = stdin.readline().rstrip()
print(data1)
print(data2)

# # [2] テスト用Input
# filename  = sys.argv[1]         # ファイル名をコマンドライン引数から取得
# sys.stdin = open(filename, 'r') # ファイルを読み込んで sys.stdin に置き換える
# data      = input()             # input() を使用してファイルの内容を取得
# sys.stdin = sys.__stdin__       # sys.stdin を元に戻す

# print('Inputfile: '+ filename)
# print('InputData: '+ data)


# 標準入力から文字列として取得
input_str = sys.stdin.read()

# 改行を含む複数行の入力をリストに分割
input_list = input_str.splitlines()

# input_list を処理する
print(input_list)







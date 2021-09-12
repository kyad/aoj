# https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1193&lang=jp

def solve(board):
    score = 0
    while True:
        H = len(board)
        remove = [[0] * 5 for i in range(H)]
        remove_sum = 0
        # Remove
        for y in range(H):
            start = -1
            end = -1
            value = 0
            line = board[y] + [0]
            for x in range(6):
                if line[x] != value:
                    if end - start >= 2 and value != 0:
                        for i in range(start, end + 1):
                            remove[y][i] = 1
                        score += value * (end - start + 1)
                    value = line[x]
                    start = x
                else:
                    end = x
            remove_sum += sum(remove[y])
        if remove_sum == 0:
            break
        # Drop
        for x in range(5):
            remove_y = H - 1
            for y in range(H - 1, -1, -1):
                while remove_y >= 0 and remove[remove_y][x] == 1:
                    remove_y -= 1
                if remove_y < 0:
                    board[y][x] = 0
                else:
                    board[y][x] = board[remove_y][x]
                    remove_y -= 1
    print(score)

def main():
    while True:
        H = int(input())
        if H == 0:
            break
        board = []
        for h in range(H):
            board.append(list(map(int, input().split())))
        solve(board)

main()

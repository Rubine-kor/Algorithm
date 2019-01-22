//2019-01-23

n = int(input())
m = int(input())

arr = [[0]*n for i in range(n)]

now = 1

xstart = n // 2
ystart = n // 2

x = xstart
y = ystart

arr[xstart][ystart] = now
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

cnt_base = 3
cnt_before = 1
move = 1
stop = n * n

while now <= stop:
    now += 1
    x -= 1
    arr[x][y] = now
    if now == m:
        mx = x
        my = y
    for i in range(move):
        now += 1
        x += dx[0]
        y += dy[0]
        arr[x][y] = now
        if now == m:
            mx = x
            my = y
    move += 1
    for j in range(1, 4):
        for i in range(move):
            if now == stop:
                break
            now += 1
            x += dx[j]
            y += dy[j]
            arr[x][y] = now
            if now == m:
                mx = x
                my = y
    if now == stop:
        break
    move += 1

for i in range(n):
    for j in range(n):
        print(arr[i][j], end=' ')
    print("")
print(mx + 1, my + 1)
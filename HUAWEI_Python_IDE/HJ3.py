# 明明的随机数

while 1:
    try:
        num = int(input())
        data = [int(input()) for _ in range(num)]
        data = sorted(set(data))
        for c in data:
            print(c)
    except:
        break


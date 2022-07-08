while 1:
    try:
        num = int(input())
        lst = [input() for _ in range(num)]
        lst = sorted(lst)
        for c in lst:
            print(c)
    except:
        break

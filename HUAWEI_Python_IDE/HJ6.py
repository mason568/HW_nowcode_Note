while 1:
    try:
        num = int(input())

        c = 2
        while c <= num//c:
            if num % c == 0:
                print(c, end=' ')
                num = num // c
            else:
                c += 1

        if num>2:
            print(num, end=' ')
    except:
        break

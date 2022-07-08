while 1:
    try:
        num = input()
        print(bin(int(num)).count('1'))
    except:
        break

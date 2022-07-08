
while 1:
    try:
        line = int(input())

        data = dict()
        while line > 0:
            index, value = map(int, input().split(' '))
            if index in data:
                data[index] += value
            else:
                data[index] = value
            line -= 1

        keys = sorted(data)
        for k in keys:
            print(f"{k} {data[k]}") # print(f'') 表示之后有变量和表达式
    except:
        break

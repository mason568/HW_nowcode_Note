# 遍历记录 非字母位置
# 遍历 进行排序
# 遍历 插入非字母

while 1:
    try:    
        data = input()
        temp = ""
        c_index = []
        for index, val in enumerate(data):
            if val.isalpha():
                temp += val
            else:
                c_index.append(index)
        temp = sorted(temp, key=str.upper)
        lens = len(data)
        index = 0
        while index != lens:
            if index in c_index:
                temp.insert(index, data[index])
            index += 1

        print("".join(temp))
    except:
        break

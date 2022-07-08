# 计算某字符出现次数
while 1:
    try:
        data = input()
        ch = input()
        print(data.lower().count(ch.lower()))
    except:
        break

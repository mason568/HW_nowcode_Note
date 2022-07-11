
while 1:
    data = input()
    l, r = 0, 0 
    for ad in data.split(';'):
        ad = ad.strip() #Python strip() 方法用于移除字符串头尾指定的字符（默认为空格或换行符）或字符序列。 注意：该方法只能删除开头或是结尾的字符，不能删除中间部分的字符。
        # ad[0] 移动方向
        # ad[1:] 移动距离
        try:
            if ad[0] == "A":
                l -= int(ad[1:])
            elif ad[0] == "D":
                l += int(ad[1:])
            elif ad[0] == "W":
                r += int(ad[1:])
            elif ad[0] == "S":
                r -= int(ad[1:])
            else:
                # 异常情况不做处理
                pass
        except:
            # 异常情况不做处理
            pass

    # 格式化输出
    print(f"{l},{r}")

def max_sub_str(line):
    lens = len(line)
    # 双指针暴力破解
    s = e = 0
    while s != lens-1:
        e = s
        while e != lens-1:
            if line[s:e] in line[e:] and e-s > 2:
                return False
            e += 1
        s += 1
    return True
        
while 1:
    try:
        line = input()

        # 条件1
        if len(line) > 8:
            counts = [0, 0, 0, 0]

            # 条件2
            for c in line:
                if "0" <= c <= "9":
                    counts[0] = 1
                elif "a" <= c <= "z":
                    counts[1] = 1
                elif "A" <= c <= "Z":
                    counts[2] = 1
                else:
                    counts[3] = 1

            if sum(counts) < 3:
                print("NG")
                continue

            # 条件3
            if max_sub_str(line):
                print("OK")
            else:
                print("NG")
        else:
            print("NG")
    except:
        break


# I = "15,123,456,786,453,46,7,5,3,665,453456,745,456,786,453,123"  # i[0] 为序列的个数 
# R = "5,6,3,6,3,0"  # r[0] 为序列的个数

# i_lens = 15
# I = "123,456,786,453,46,7,5,3,665,453456,745,456,786,453,123"
# r_lens = 5
# R = "6,3,6,3,0"
# R = "0,3,6"

# 1. R 需要排序 去重
# 2. 输入格式要求   后面数据的总个数  需要比较的且满足条件R<i>值  满足R<i>的字符个数  字符的下标  字符  重复

while 1:
    try:
        I = input().split() #输入为str "15,123,456,786,453,46,7,5,3,665,453456,745,456,786,453,123"
        R = input().split() #输入为str "5,6,3,6,3,0"

        i_lens = int(I[0])
        I = I[1:]
        r_lens = int(R[0])
        R = R[1:]

        # 1. R 需要排序 去重
        R = list(map(int, R))
        R = list(set(R))
        R = sorted(R)
        R = list(map(str, R))

        ret = []
        for rc in R:
            boxs = []
            for index in range(i_lens):
                if rc in I[index]: #由于都是字符串，直接用in
                    boxs.append((I[index], index)) 

            if boxs:
                ret += [rc, len(boxs)]
                for key, idx in boxs:
                    ret += [idx, key]

        print(len(ret), end=" ")
        for i in ret:
            print(i, end=" ")
        print("")
    except:
        break


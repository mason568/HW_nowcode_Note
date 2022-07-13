import sys


def check_ip(num):
    """
    检查IP 单个字段
    """
    num = int(num)
    if 0 <= num <= 255:
        pass
    else:
        raise Exception("无效字符")
    return num

def check_mask(num):
    """
    检查掩码
    """
    num = check_ip(num)
    return bin(num)[2:].zfill(8)#Python zfill() 方法返回指定长度的字符串，原字符串右对齐，前面填充0。

a = 0
b = 0
c = 0
d = 0
e = 0
e_ip = 0
p_ip = 0

# 没有告诉需要输入的行数，使用 sys.stdin 更便捷
for _c in sys.stdin:
    ip, mask = _c.strip().split('~')

    # 判断 ip
    try:
        ips = ip.split('.')
        ips = list(map(check_ip, ips))
    except:
        # 存在无效字符
        e_ip += 1
        continue
        
    if ips[0] == 0 or ips[0] == 127:
        continue
        
    # 判断 mask
    try:
        masks = mask.split('.')
        masks = list(map(check_mask, masks))
        masks_b = "".join(masks)
        if masks_b.find("0") != masks_b.rfind("1")+1:
            raise
    except:
        e_ip += 1
        continue

    if 1 <= ips[0] <= 126:
        a += 1
    elif 128 <= ips[0] <= 191:
        b += 1
    elif 192 <= ips[0] <= 223:
        c += 1
    elif 224 <= ips[0] <= 239:
        d += 1
    elif 240 <= ips[0] <= 255:
        e += 1
    else:
        pass
        
    if 10 == ips[0]:
        p_ip += 1
    elif 172 == ips[0] and 16 <= ips[1] <= 31:
        p_ip += 1
    elif 192 == ips[0] and 168 == ips[1]:
        p_ip += 1
        
print(a,b,c,d,e,e_ip,p_ip)

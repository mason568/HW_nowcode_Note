def encode(ch):
    """
	加密
	"""
    if ch == "Z":
        return "a"
    elif ch == "z":
        return "A"
    elif ch == "9":
        return "0"
    elif "A" <= ch < "Z":
        return chr(ord(ch.lower())+1)
    elif "a" <= ch < "z":
        return chr(ord(ch.upper())+1)
    elif "0" <= ch < "9":
        return str(int(ch)+1)

def decode(ch):
    """
	解密
	"""
    if ch == "a":
        return "Z"
    elif ch == "A":
        return "z"
    elif ch == "0":
        return "9"
    elif "A" < ch <= "Z":
        return chr(ord(ch.lower())-1)
    elif "a" < ch <= "z":
        return chr(ord(ch.upper())-1)
    elif "0" < ch <= "9":
        return str(int(ch)-1)


while 1:
    try:
        for c in input():
            print(encode(c), end="")
        print("")
        for c in input():
            print(decode(c), end="")
        print("")
    except:
        break

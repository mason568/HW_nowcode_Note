while 1:
    try:
        data = input()

        psw = ""
        for c in data:
            if "A" <= c < "Z":
                psw += chr(ord(c)+1).lower()
            elif c == "Z":
                psw += "a"
            elif "a" <= c <= "c":
                psw += "2"
            elif "d" <= c <= "f":
                psw += "3"
            elif "g" <= c <= "i":
                psw += "4"
            elif "j" <= c <= "l":
                psw += "5"
            elif "m" <= c <= "o":
                psw += "6"
            elif "p" <= c <= "s":
                psw += "7"
            elif "t" <= c <= "v":
                psw += "8"
            elif "w" <= c <= "z":
                psw += "9"
            else:
                psw += c
        print(psw)
    except:
        break

s="123456789"
print([0]*len(s))
dp= [[0]*len(s) for _ in range(len(s))]
print(len(dp))
for line in dp:
    print(line)
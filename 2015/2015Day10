inp = '1113122113'
ans = ''
for _ in range(50):
    count = 0
    digit = inp[0]
    for j in inp:
        if j == digit:
            count += 1
        else:
            ans += str(count) + str(digit)
            count = 1
            digit = j
    ans += str(count) + str(digit)
    inp = ans
    ans = ''
print(len(inp))

file = open('input.txt', 'r')
file = file.readlines()
temp = 0
result = 0

for i in file:
    for j in i:
        if j.isdigit():
            temp = temp+int(j)
            break
    for j in i[::-1]:
        if j.isdigit():
            temp = temp*10+int(j)
            break
    result += temp
    temp = 0
print(result)

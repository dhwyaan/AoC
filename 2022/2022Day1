inpu = open("input.txt", 'r')

inpu = open("input.txt", 'r')
f = inpu.readlines()
curr = 0
arr = []
for i in range(len(f)):
    if f[i] != '\n':
        curr = curr + int(f[i].strip())
    else:
        arr.append(curr)
        curr = 0
print(max(arr))

arr.sort()
print(arr[len(arr)-1] + arr[len(arr)-2] + arr[len(arr)-3])

num = bin(input())

f = 0

for i in range(2, len(n)-1):
    if n[i] == n[i+1]:
        f = 1
        break

if f==0: 
    print("true")
else:
    print("false")

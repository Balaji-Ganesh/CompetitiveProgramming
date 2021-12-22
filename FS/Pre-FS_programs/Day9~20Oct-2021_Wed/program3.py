word = input()

for i in range(0, len(word)-1):
    after = word[i:]+word[i+1:]
    if after == word:
        return True

print(False)
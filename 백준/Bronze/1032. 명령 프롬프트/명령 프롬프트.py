N = int(input())

string = input()

for i in range(N-1):
    string2 = input()
    for i in range(len(string)):
        if string[i] != string2[i]:
            string = string[:i] + '?' + string[i+1:]

print(string)
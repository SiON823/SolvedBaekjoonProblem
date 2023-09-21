def insertionSort(arr):
    # 1 ~ n-1까지 요소가 삽입할 요소
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # 삽입할 요소보다 큰 요소는 한 칸씩 뒤로 밀어냄
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        # 삽입할 요소를 삽입
        arr[j + 1] = key

n = int(input())
a = list(map(int, input().split()))
insertionSort(a)

result = 0
for i in range(n):
    result += sum(a[:i+1])
print(result)
import sys

res = 0
N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))


def merge_sort(start, end):
    global res, A

    if start < end:
        mid = (start + end) // 2
        merge_sort(start, mid)
        merge_sort(mid + 1, end)

        idx1, idx2 = start, mid + 1
        new_arr = []

        while idx1 <= mid and idx2 <= end:
            if A[idx1] <= A[idx2]:
                new_arr.append(A[idx1])
                idx1 += 1
            else:
                new_arr.append(A[idx2])
                idx2 += 1
                res += mid - idx1 + 1

        if idx1 <= mid:
            new_arr = new_arr + A[idx1: mid + 1]
        if idx2 <= end:
            new_arr = new_arr + A[idx2: end + 1]

        for i in range(len(new_arr)):
            A[start + i] = new_arr[i]


merge_sort(0, N - 1)
print(res)


def linearSearch(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Element found at index i
    return -1  # Element not found


arr = [64, 34, 25, 12, 22, 11, 90]
target = 12

result = linearSearch(arr, target)

if result != -1:
    print(f"Element {target} found at index {result}")
else:
    print(f"Element {target} not found in the array")
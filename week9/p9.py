def findItinerary(arr):
    
    dataSet = {}
    for i in arr:
        dataSet[i[0]] = i[1]

    reverseMap = {}
    for i in arr:
        reverseMap[i[1]] = i[0]

    start = ""

    for i in range(len(arr)):
        if arr[i][0] not in reverseMap:
            start = arr[i][0]
            break

    ans = []

    while start in dataSet:
        ans.append([start, dataSet[start]])
        start = dataSet[start]

    return ans


if __name__ == "__main__":
    arr = [["Chennai", "Bangalore"], ["Bombay", "Delhi"], 
           ["Goa", "Chennai"], ["Delhi", "Goa"]]

    res = findItinerary(arr)
    for i in res:
        print(i[0], "->", i[1])
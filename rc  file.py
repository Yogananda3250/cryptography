import heapq

def rc_file_algorithm(data, buf_size):
    runs, run, heap, hold = [], [], [], []
    it = iter(data)
    last = float('-inf')

    for _ in range(buf_size):
        try: heapq.heappush(heap, next(it))
        except StopIteration: break

    while heap or hold:
        while heap:
            smallest = heapq.heappop(heap)
            run.append(smallest)
            last = smallest
            try:
                nxt = next(it)
                if nxt >= last:
                    heapq.heappush(heap, nxt)
                else:
                    hold.append(nxt)
            except StopIteration:
                continue
        runs.append(run)
        run = []
        heap, hold = hold, []
        heapq.heapify(heap)
        last = float('-inf')
    return runs

# Example usage
data = [3, 1, 4, 2, 5, 6, 0, 7, 8]
buffer = 3
result = rc_file_algorithm(data, buffer)
for i, r in enumerate(result):
    print(f"Run {i+1}: {r}")

def get_area(rectangles):
    events = []
    for rect in rectangles:
        x1, y1, x2, y2 = rect
        events.append((x1, y1, y2, 1))  # 进入事件
        events.append((x2, y1, y2, -1)) # 离开事件

    events.sort()

    last_x = events[0][0]
    active_intervals = []
    total_area = 0

    def compute_y_range(active_intervals):
        if not active_intervals:
            return 0
        active_intervals.sort()
        current_start, current_end = active_intervals[0]
        y_length = 0
        for start, end in active_intervals[1:]:
            if start > current_end:
                y_length += current_end - current_start
                current_start, current_end = start, end
            else:
                current_end = max(current_end, end)
        y_length += current_end - current_start
        return y_length

    for x, y1, y2, typ in events:
        if x != last_x:
            total_area += (x - last_x) * compute_y_range(active_intervals)
            last_x = x

        if typ == 1:
            active_intervals.append((y1, y2))
        else:
            active_intervals.remove((y1, y2))

    return total_area

# 读取输入
N = int(input())
rectangles = [tuple(map(int, input().split())) for _ in range(N)]

# 计算覆盖的面积
result = get_area(rectangles)
print(result)

#!bin/python3

#Description
#
#There is a light in a room which lights up only when someone is in the room (think motion detector). You are given a set of intervals in entrance and exit times as single integers, and expected to find how long the light has been on. When the times overlap, you need to find the time between the smallest and the biggest numbers in that interval.
#Input Description
#
#You'll be given a set of two integers per line telling you the time points that someone entered and exited the room, respectively. Each line is a visitor, each block is a room. Example:
#
#1 3
#2 3
#4 5
#
#Output Description
#
#Your program should report the number of hours the lights would be on. From the above example:
#
#3
#
#Input
#
#2 4
#3 6
#1 3
#6 8
#
#6 8
#5 8
#8 9
#5 7
#4 7
#
#Output
#
#7
#
#5
#
#Bonus Input
#
#15 18
#13 16
#9 12
#3 4
#17 20
#9 11
#17 18
#4 5
#5 6
#4 5
#5 6
#13 16
#2 3
#15 17
#13 14

entry_exit_points1 = [[1, 2], [2, 3], [4, 5]]
entry_exit_points2 = [[2, 4], [3, 6], [1, 3], [6, 8]]
entry_exit_points3 = [[6, 8], [5, 8], [8, 9], [5, 7], [4, 7]]
entry_exit_points4 = [[15, 18], [13, 16], [9, 12], [3, 4], [17, 20], [9, 11], [17, 18], [4, 5], [5, 6], [4, 5], [5, 6], [13, 16], [2, 3], [15, 17], [13, 14]]

def get_hours_on(entry_exit_points):
    all_entries = [entry_exit_points[0]]
    for t0, t1 in entry_exit_points:
        for e0, e1 in all_entries:
            i = 0
            # current entry is between the previous one
            if e0 <= t0 and e1 >= t1:
                continue
            # current entry is wider that the previous one
            elif t0 < e0 and t1 > e1:
                all_entries[i][0] = t0
                all_entries[i][1] = t1
                # current entry is shifted to the right of the previous one
            elif e0 <= t0 and t0 <= e1 and e1 < t1:
                all_entries[i][1] = t1
                # current entry is shifted to the left of the previous one
            elif e0 > t0 and t1 >= e0 and e1 >= t1:
                all_entries[i][0] = t0
            else:
                all_entries.append([t0, t1])
            i += 1
    print(all_entries)
    hours_on = 0
    for t0, t1 in all_entries:
        hours_on += t1 - t0
    return hours_on

print(get_hours_on(entry_exit_points1))
print(get_hours_on(entry_exit_points2))
print(get_hours_on(entry_exit_points3))
print(get_hours_on(entry_exit_points4))

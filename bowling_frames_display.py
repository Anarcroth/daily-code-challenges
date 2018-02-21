#!bin/python3

roll_hit = input("Enter rows and hits on each roll: ").split();
roll_hit = list(map(int, roll_hit));

display = [];
skip = False;
for index, hit in enumerate(roll_hit):
    if skip:
        skip = False;
        continue;
    elif roll_hit[index] + roll_hit[index + 1] == 10 and roll_hit[index] != 10:
        display.append(str(roll_hit[index]));
        display.append('/');
        skip = True;
        continue;
    elif roll_hit[index] == 10:
        display.append('X');
        skip = True;
        continue;

#!bin/python3

acc_values = input("Enter number of credits and debts: ");
credits_and_debts = input("Enter credits and debts: ");

credits_and_debts = list(map(int, credits_and_debts.split()));

for index, n in enumerate(credits_and_debts):
    _sum_forw = sum(credits_and_debts[index + 1:len(credits_and_debts)]);
    _sum_back = sum(credits_and_debts[0: index]);
    if _sum_back == _sum_forw:
        print(index);

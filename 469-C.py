s = input()

seqs = []
zero = set()  # point to seq which ends with o
one = set()  # point to seq in seqs which ends with 1
impossible = False

for i in range(len(s)):
    day = i + 1
    if s[i] == '0':
        if len(one) > 0:
            ends_with_one = one.pop()
            seqs[ends_with_one].append(day)
            zero.add(ends_with_one)  # now it ends with 0
        else:
            seqs.append([day])
            ends_with_zero = len(seqs) - 1
            zero.add(ends_with_zero)
    else:
        if len(zero) > 0:
            ends_with_zero = zero.pop()
            seqs[ends_with_zero].append(day)
            one.add(ends_with_zero)  # now it ends with 1
        else:
            impossible = True
            break

    if impossible:
        break

if len(one) > 0:
    impossible = True

if impossible:
    print(-1)
else:
    print(len(seqs))
    for se in seqs:
        print(len(se), ' '.join([str(e) for e in se]))

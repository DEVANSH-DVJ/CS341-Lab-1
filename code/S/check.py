import os

f = open('tc.txt')
tc = f.readlines()
f.close()

for i in range(0, len(tc), 2):
    arr = tc[i].split(', ')
    out, size = (int(x) for x in tc[i+1].split())

    text = "{}\n".format(size)
    text += "\n".join(arr)

    f = open('tmp.txt', 'w')
    f.write(text)
    f.close()

    output = int(os.popen("spim -file A1.s < tmp.txt").readlines()[-1])
    if output == out:
        print(f"{i//2}/{len(tc)//2}", end='\r')
    else:
        print(f"failed for {arr}, got {output} expected {out}")
        exit()

print("woohoo! your code is correct (or the testcases are wrong xD)")
os.system("rm -rf tmp.txt")

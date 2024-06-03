import subprocess, os
generators = os.listdir("generators-src")
validators = os.listdir("validators-src")
solutions = os.listdir("solutions-src")
if not os.path.exists("generators"):
    os.mkdir("generators")
if not os.path.exists("validators"):
    os.mkdir("validators")
if not os.path.exists("solutions"):
    os.mkdir("solutions")
total = len(generators)+len(validators)+len(solutions)
cnt = 0
print(f"\rCompiled 0/{total}",end="")
for gen in generators:
    cnt+=1
    subprocess.run(["g++",f"generators-src/{gen}","-o",f"generators/{gen[:-4]}"])
    print(f"\rCompiled {cnt}/{total}",end="")
for val in validators:
    cnt+=1
    subprocess.run(["g++",f"validators-src/{val}","-o",f"validators/{val[:-4]}"])
    print(f"\rCompiled {cnt}/{total}",end="")
for sol in solutions:
    cnt+=1
    subprocess.run(["g++",f"solutions-src/{sol}","-o",f"solutions/{sol[:-4]}"])
    print(f"\rCompiled {cnt}/{total}",end="")
print()
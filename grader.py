import subprocess, os, psutil, time, json, sys, resource
GREEN = '\x1b[32m'
RED = '\x1b[31m'
RESET = '\x1b[39m'
BLUE = '\x1b[34m'
MAGENTA = '\x1b[35m'
YELLOW = '\x1b[33m'
if len(sys.argv) != 3:
    print(f"{RED}Format: {RESET}python3 test.py <problem name> <file name>")
    exit()
name = sys.argv[1]
file = sys.argv[2]
if not os.path.exists(f"cases/{name}.json"):
    print(f"{RED}Problem {RESET}{name} {RED}not found\nPossible names: {RESET}{os.listdir(f'linux/solutions')}")
    exit()
if not os.path.exists(file):
    print(f"{RED}File {RESET}{file} {RED}not found{RESET}")
    exit()
if not os.path.exists("constraints.json"):
    print(f"{RED}You must run the speed test:\n\t{RESET}python3 speedTest.py")
    exit()
if file.endswith("cpp"):
    print(f"\r{RESET}Compiling {BLUE}{file}",end="")
    err = subprocess.run(["g++",file,"-o","Main"]).stderr
    if err != None:
        print(f"\r{RED}Failed to compile {BLUE}{file}")
        print(f"{RESET}{err}")
        exit()
elif file.endswith("java"):
    print(f"\r{RESET}Compiling {BLUE}{file}",end="")
    err = subprocess.run(["javac",file]).stderr
    if err != None:
        print(f"\r{RED}Failed to compile {BLUE}{file}")
        print(f"{RESET}{err}")
        exit()
constraints = json.load(open("constraints.json","r"))
timelimit = constraints[name]["time"]
if not file.endswith(".cpp"):
    timelimit*=2
    timelimit+=2000
print(f"\r{RESET}Running {BLUE}{file}\033[K\n\nCase\t{MAGENTA}Subtask{RESET}")
testcases = json.load(open(f"cases/{name}.json","r"))
prev, cnt = 0, 0
solved = []
for case in testcases:
    while len(solved) < case["subtask"]:
        solved.append(True)
for case in testcases:
    if case["subtask"] != prev:
        cnt = 0
        prev = case["subtask"]
    cnt+=1
    print(f"\r\033[K{RESET}{BLUE}{cnt}\t{MAGENTA}{prev}{RESET} :\t{YELLOW}Running{RESET}",end="")
    input = case["input"]
    if input.startswith("%%"):
        seed = input[input.find(":")+1:]
        input = subprocess.run([f"generators/{name}",str(prev),seed],text=True,capture_output=True).stdout
    if file.endswith(".cpp"):
        cmd = ['./Main']
    elif file.endswith(".java"):
        cmd = ['java',file[:-5]]
    elif file.endswith(".py"):
        cmd = ['python3',file]
    total = 0
    errored = False
    start = time.time()
    try:
        res = subprocess.run(cmd,input=input+"\n",timeout=timelimit/1000,text=True,capture_output=True)
        total = time.time()-start
        if res.returncode != 0:
            res = res.stderr
            errored = True
        else:
            res = res.stdout
    except subprocess.TimeoutExpired:
        res = ""
        pass
    if errored:
        print(f"\r\033[K{RESET}{BLUE}{cnt}\t{MAGENTA}{prev}{RESET} :\t{RED} Error{RESET}")
        print(f"{RESET}{res}")
        solved[case["subtask"]-1] = False
    elif res == "":
        print(f"\r\033[K{BLUE}{cnt}\t{MAGENTA}{prev}{RESET} :\t{RED}Time Limit Exceeded{RESET}")
        solved[case["subtask"]-1] = False
    else:
        real = case["output"]
        if real.startswith("%%"):
            try:
                works = subprocess.run([f"validators/{name}"],text=True,capture_output=True,input=input+"\n"+res,timeout=1).stdout=="1"
            except subprocess.TimeoutExpired or subprocess.SubprocessError:
                works = False
        else:
            works = real.strip() == res.strip()
        if works:
            print(f"\r\033[K{BLUE}{cnt}\t{MAGENTA}{prev}{RESET} :\t{GREEN}{total:.3}s {RESET}{RESET}")
        else:
            print(f"\r\033[K{BLUE}{cnt}\t{MAGENTA}{prev}{RESET} :\t{RED}Incorrect output{RESET}")
            solved[case["subtask"]-1] = False
print(f"\n{RESET}Solved subtasks: ")
for s in solved:
    if s:
        print("\033[42m   ",end="\033[0m ")
    else:
        print("\033[41m   ",end="\033[0m ")
print()
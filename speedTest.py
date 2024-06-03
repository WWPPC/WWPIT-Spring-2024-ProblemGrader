import time, subprocess, json, os
GREEN = '\x1b[32m'
RED = '\x1b[31m'
RESET = '\x1b[39m'
BLUE = '\x1b[34m'
if not os.path.exists("solutions") or not os.path.exists("generators") or not os.path.exists("validators"):
    print(f"{RED}You must first run {RESET}\n\tpython3 compile.py")
solutions = os.listdir(f"solutions")
count = len(solutions)
print(f"\rFinished {BLUE}0/{count} {RESET}tests",end="")
data = {}
for ind,sol in enumerate(solutions):
    testcases = json.load(open(f"cases/{sol}.json","r"))
    maxT = 0
    for case in testcases:
        input = case["input"]
        if input.startswith("%%"):
            input = subprocess.run([f"./generators/{sol}",str(case["subtask"]),input[input.find(":")+1:]],text=True,capture_output=True).stdout
        t = time.time()
        subprocess.run([f"./solutions/{sol}"],input=input,text=True,capture_output=True)
        maxT = max(maxT,(time.time()-t)*1000)
    print(f"\rFinished {BLUE}{ind+1}/{count} {RESET}tests",end="")
    data[sol] = {"time":round(maxT*1.5)}
print(f"\r{GREEN}All tests finished{RESET}")
json.dump(data,open("constraints.json","w"))
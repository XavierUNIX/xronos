import subprocess

GREEN ='\033[22;32m'
ENDC = '\033[0m'

proc = subprocess.Popen(['env', 'TZ=EST5EDT', 'date'],stdout=subprocess.PIPE)
timeoutput, stderr = proc.communicate()
timestr = timeoutput.decode(encoding='UTF-8').rstrip()
datestr = timestr[:-17]
yearstr = timestr[24:]

print (GREEN+datestr+yearstr+ENDC)

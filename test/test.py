import subprocess
import sys

#  case1 no dead 
# ./philo 1 800 200 200
if sys.argv[1] == "1":
    result = subprocess.run(["../philo", "1", "800", "200", "200"])
    print(result)

#  case2 no dead 
# ./philo 5 800 200 200
elif sys.argv[1] == "2":
    result = subprocess.run(["../philo", "5", "800", "200", "200"])
    print(result)

#  case3 no dead 
# ./philo 5 800 200 200 7
elif sys.argv[1] == "3":
    result = subprocess.run(["../philo", "5", "800", "200", "200", "7"])
    print(result)

#  case4 may be dead 
# ./philo 4 410 200 200
elif sys.argv[1] == "4":
    result = subprocess.run(["../philo", "4", "410", "200", "200"])
    print(result)

#  case5 may be dead 
# ./philo 4 310 200 100
elif sys.argv[1] == "5":
    result = subprocess.run(["../philo", "4", "310", "200", "100"])
    print(result)

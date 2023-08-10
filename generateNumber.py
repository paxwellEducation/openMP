import random
import subprocess
from math import floor
import time

# Number of random numbers to generate
num_numbers = int(input("Enter the number of random numbers to generate: "))

# Generate the random numbers
random.seed(random.randint(0, 1000))
random_numbers = [random.randint(0, 255) for _ in range(num_numbers)]

# Calculate the average
average = sum(random_numbers) / num_numbers

# Write the numbers and the average to input.txt
with open('input.txt', 'w') as f:
    f.write(str(num_numbers) + '\n')
    for number in random_numbers:
        f.write(str(number) + '\n')
        
# Run the C++ program
start = time.time()
cmd = "./averagepx"
with open("input.txt", "r") as infile:
    result = subprocess.run(cmd, stdin=infile, capture_output=True, text=True)
    print(f"Average: {result.stdout}, real average: {floor(average)} ")
end = time.time()


start1 = time.time()
cmd = "./averageN"
with open("input.txt", "r") as infile:
    result = subprocess.run(cmd, stdin=infile, capture_output=True, text=True)
    print(f"Average: {result.stdout}, real average: {floor(average)} ")
end1 = time.time()



print(f"Time taken for C program usethread: {end - start}")

print(f"Time taken for C program notthread: {end1 - start1}")




    




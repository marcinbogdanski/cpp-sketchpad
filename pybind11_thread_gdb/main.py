import time
import example

p = example.Pet('Molly')
p2 = example.Pet('Charly')

# allow 5 iterations, after 3rd one of the threads called "Molly" will crash
time.sleep(5)

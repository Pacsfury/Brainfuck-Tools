import sys

memory = [0] * 30000
ptr = 0

memory[ptr] = (memory[ptr] + 9) & 255
while memory[ptr] != 0:
    ptr += 1
    memory[ptr] = (memory[ptr] + 9) & 255
    ptr -= 1
    memory[ptr] = (memory[ptr] - 1) & 255
ptr += 1
memory[ptr] = (memory[ptr] - 9) & 255
sys.stdout.write(chr(memory[ptr]))
memory[ptr] = (memory[ptr] - 3) & 255
sys.stdout.write(chr(memory[ptr]))
memory[ptr] = (memory[ptr] + 7) & 255
sys.stdout.write(chr(memory[ptr]))
sys.stdout.write(chr(memory[ptr]))
memory[ptr] = (memory[ptr] + 3) & 255
sys.stdout.write(chr(memory[ptr]))
ptr += 2
ptr += 1
memory[ptr] = (memory[ptr] + 6) & 255
while memory[ptr] != 0:
    ptr -= 1
    memory[ptr] = (memory[ptr] + 6) & 255
    ptr += 1
    memory[ptr] = (memory[ptr] - 1) & 255
ptr -= 1
memory[ptr] = (memory[ptr] - 4) & 255
sys.stdout.write(chr(memory[ptr]))
ptr -= 2
memory[ptr] = (memory[ptr] + 8) & 255
sys.stdout.write(chr(memory[ptr]))
memory[ptr] = (memory[ptr] - 8) & 255
sys.stdout.write(chr(memory[ptr]))
memory[ptr] = (memory[ptr] + 3) & 255
sys.stdout.write(chr(memory[ptr]))
memory[ptr] = (memory[ptr] - 6) & 255
sys.stdout.write(chr(memory[ptr]))
memory[ptr] = (memory[ptr] - 8) & 255
sys.stdout.write(chr(memory[ptr]))
ptr += 2
while memory[ptr] != 0:
    memory[ptr] = (memory[ptr] - 1) & 255
ptr += 1
while memory[ptr] != 0:
    memory[ptr] = (memory[ptr] - 1) & 255
memory[ptr] = (memory[ptr] + 6) & 255
while memory[ptr] != 0:
    ptr -= 1
    memory[ptr] = (memory[ptr] + 6) & 255
    ptr += 1
    memory[ptr] = (memory[ptr] - 1) & 255
ptr -= 1
memory[ptr] = (memory[ptr] - 3) & 255
sys.stdout.write(chr(memory[ptr]))
ptr -= 2

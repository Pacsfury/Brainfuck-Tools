# Brainf**k Tools
---

## What does BF Tools provide?

BF Tools provides basic tools needed for BF coding and debugging. Right now, it contains:

* **A BF interpreter** to directly execute your BF files
* **Two transpilers**:
  * **To C++** to run your BF files in C++ code
  * **To Python** to run your BF files in Python code

## How to execute

### Interpret code

To run your BF code, use this syntax: (_replace `bftools` with the executable_)
```bash
bftools run file.bf
```

### Transpile code

To transpile your BF code, use this syntax: (_replace `bftools` with the executable_)
```bash
bftools to file.bf lang
```

`lang` can be `python` or `cpp`

## Optimizations Example

When transpiling code like `+++++++[>+++++++<-]`, **BF Tools** doesn't just do a literal translation. It optimizes the output automatically.

**Generated Python Output:**
```python
import sys

memory = [0] * 30000
ptr = 0

memory[ptr] = (memory[ptr] + 7) & 255
while memory[ptr] != 0:
    ptr += 1
    memory[ptr] = (memory[ptr] + 7) & 255
    ptr -= 1
    memory[ptr] = (memory[ptr] - 1) & 255
```

---

## Contributing

Contributions make the open-source community an amazing place! If you want to add a new transpilation target, a memory visualizer, or a benchmark tool, your help is welcome.

1. **Fork** this repository.
2. **Create** a new branch with your feature (`git checkout -b feature/AmazingFeature`).
3. **Commit** your changes (`git commit -m 'Add some AmazingFeature'`).
4. **Push** to the branch (`git push origin feature/AmazingFeature`).
5. **Open** a Pull Request.
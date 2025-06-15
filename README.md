# scientific-computing
This is things that I am learning from book - Scientific Computing with C++

I am structuring it as folders for each chapter

## Workspace Structure

This workspace is structured to allow each C++ file to compile and run independently. This is particularly useful for exercises where each file has its own `main()` function.

```
scientific-computing/
├── chapter1/
│   └── recapChapter1.cpp
├── chapter2/
│   └── test_independent.cpp
├── chapter3/
│   └── ...
└── ...
```

## How to Use

1. **Open any .cpp file** you want to work with
2. **Compile the file** using one of these methods:
   - Press `F5` to compile and debug
   - Press `Ctrl+F5` to compile and run without debugging
   - Press `Ctrl+Shift+B` to just compile
   - Terminal: `g++ filename.cpp -o filename && ./filename`

3. **Create new exercise files** by simply creating a new .cpp file in the appropriate chapter folder. Each file should contain its own `main()` function.

## Configuration

The workspace is configured with:
- `tasks.json`: Set up to compile the currently active file
- `launch.json`: Configured to debug the currently active file

These configurations ensure that any .cpp file can be compiled and run independently.

## Best Practices

1. Organize files by chapter folders
2. Name files descriptively (e.g., `exercise1_2.cpp`, `matrix_operations.cpp`)
3. Include comments at the top of each file explaining its purpose
4. Each file should be self-contained with its own `main()` function

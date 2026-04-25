# Sparse Matrix Hackathon

## What This Does
Converts text sentences into a 2D word-frequency matrix and stores only the non-zero values using a Linked List representation, saving memory compared to a full dense matrix.

## Files
- `sparse_utils.h` — Header file with variable and function declarations
- `sparse_utils.c` — Builds the matrix from the sentences
- `main.c` — Displays the matrix and implements the Linked List sparse representation

## How to Compile and Run
```bash
gcc main.c sparse_utils.c -o sparse_matrix_demo
./sparse_matrix_demo
```
On Windows:
```bash
sparse_matrix_demo.exe
```

## Method Used
Each non-zero entry in the matrix is stored as a Node containing:
- Row index
- Column index
- Value
- Pointer to next node

Zeros are skipped entirely, so only useful data is stored.

## Memory Saved
- Original matrix: 4000 bytes (10 × 100 × 4)
- Linked list: 1440 bytes (60 nodes × 24 bytes)
- Reduction: ~64%

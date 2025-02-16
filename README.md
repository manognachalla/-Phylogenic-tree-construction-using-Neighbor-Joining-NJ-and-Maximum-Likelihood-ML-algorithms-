# Phylogenetic Tree Construction Tool

A C++ program for constructing phylogenetic trees from sequence data using Neighbor-Joining, Fitch-Margoliash, or UPGMA algorithms. The program supports both FASTA and PAML format sequence files and can also generate random trees for testing purposes.

## Features

- Three tree construction algorithms:
  - Neighbor-Joining (NJ): Fast and widely used method
  - Fitch-Margoliash (FM): More accurate branch lengths through weighted least squares optimization
  - UPGMA: Produces ultrametric trees with molecular clock assumption
- Multiple distance calculation methods:
  - Fractional k-mer count (default)
  - Mahalanobis distance
  - Cosine distance
- Support for multiple input formats:
  - FASTA format
  - PAML format (with multiple replicates)
  - Random distance matrix generation

## Compilation

To compile the program, use g++ with C++11 support:

```bash
g++ -o phylo_tree main.cpp tree.cpp neighbor_joining.cpp fitch_margoliash.cpp upgma.cpp tree_io.cpp -std=c++11
```

## Usage

### Basic Usage

```bash
./phylo_tree <input_file> [options]
```

### Command Line Options

- Algorithm Selection:
  - `-nj` : Use Neighbor-Joining algorithm (default)
  - `-fm` : Use Fitch-Margoliash algorithm
  - `-upgma` : Use UPGMA algorithm

- Distance Calculation Methods:
  - `-m` : Use Mahalanobis distance
  - `-c` : Use Cosine distance
  - (default: fractional k-mer count)

- K-mer Length:
  - `-k <INT>` : Set k-mer length (default: 8)

- PAML Replicates:
  - `-replicates <INT>` : Number of replicates to parse in PAML files (default: 1)

- Verbose Output:
  - `-v` : Enable verbose output

### Examples

1. Basic usage with FASTA file (using default Neighbor-Joining):
```bash
./phylo_tree sequences.fasta
```

2. Using Fitch-Margoliash algorithm:
```bash
./phylo_tree sequences.fasta -fm
```

3. Using UPGMA algorithm:
```bash
./phylo_tree sequences.fasta -upgma
```

4. Using Mahalanobis distance with k-mer length 6:
```bash
./phylo_tree sequences.fasta -m -k 6
```

5. Processing PAML file with 5 replicates:
```bash
./phylo_tree sequences.paml -replicates 5
```

6. Generate a random tree with 10 leaves using UPGMA:
```bash
./phylo_tree -random 10 -upgma
```

### Output

The program generates a Newick format tree file named `output.txt` in the current directory. For PAML files with multiple replicates, the file will contain one tree per line.

## Algorithm Details

### Neighbor-Joining (NJ)
- Fast and widely used method
- Constructs trees based on the principle of minimum evolution
- Good for large datasets
- Computationally efficient: O(n³) time complexity

### Fitch-Margoliash (FM)
- Uses weighted least squares optimization
- More accurate branch lengths
- Better for non-ultrametric distances
- Computationally more intensive than NJ
- Features:
  - Branch length optimization after each node addition
  - Iterative tree improvement

### UPGMA (Unweighted Pair Group Method with Arithmetic Mean)
- Produces ultrametric trees (molecular clock assumption)
- Simple and intuitive hierarchical clustering method
- Good for datasets where evolutionary rates are roughly constant
- Features:
  - Guaranteed ultrametric property
  - Height-based tree construction
  - Computationally efficient: O(n²) time complexity
- Best suited for:
  - Closely related sequences
  - Data that follows a molecular clock
  - Situations where ultrametric trees are desired

## Distance Calculation Methods

1. **Fractional k-mer Count (Default)**
   - Counts k-mer frequencies and normalizes them
   - Good balance between speed and accuracy

2. **Mahalanobis Distance (-m)**
   - Takes into account the correlation between k-mers
   - Better for sequences with varying composition

3. **Cosine Distance (-c)**
   - Treats k-mer profiles as vectors
   - Good for comparing sequence composition patterns

## Input File Formats

### FASTA Format
```
>Sequence1
ATGCTAGCTAGCT
>Sequence2
ATGCTAGCTAGCT
```

### PAML Format
Supports multiple sequence alignments with replicates as generated by PAML's Evolver module.

## Notes

- For large sequences, increasing k-mer length might improve accuracy but will increase memory usage
- The Fitch-Margoliash algorithm is slower but generally produces more accurate branch lengths
- Use verbose mode (-v) to monitor progress for large datasets
- Output trees are in Newick format and can be visualized using tools like FigTree or iTOL

## Contributing

Feel free to submit issues and enhancement requests!

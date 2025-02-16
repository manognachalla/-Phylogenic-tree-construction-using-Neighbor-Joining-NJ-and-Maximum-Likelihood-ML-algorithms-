#ifndef TREE_H
#define TREE_H

#include <vector>
#include <string>
#include <map>

// Define the nodes of the tree
struct node {
    int id, parent, level, child1, child2;
    float child1_distance, child2_distance;
    bool isleaf;
    std::string name, subtree;
};

// Sequences and their names
struct sequence {
    std::vector<std::string> seq;
    std::vector<std::string> name;
};

// Distance matrix struct
struct dmatrix_row {
    std::vector<float> distances;
    float sum;
    int id;
};

// Tree class declaration
class Tree {
public:
    std::vector<node> tree;
    std::string newick;
    Tree(sequence);
    Tree(std::vector<dmatrix_row>);
    void joinNodes(int, int, float, float);
};

// Function declarations for sequence processing
sequence read_fasta(std::string filename);
std::vector<sequence> read_paml(std::string filename, int n_replicates);
std::vector<std::vector<float>> count_kmer_frequencies(sequence& sequences, int& kmer_length);
std::vector<dmatrix_row> distance_matrix(std::vector<std::vector<float>>& frequencies, sequence& sequences, int kmer_length, std::string method);

// Neighbor Joining algorithm declarations
void neighbor_joining(std::vector<dmatrix_row>& D, Tree& tree, bool verbose);
void neighbor_joining_tree(std::vector<dmatrix_row>& D, std::string output, bool verbose);

// Fitch-Margoliash algorithm declarations
void fitch_margoliash(std::vector<dmatrix_row>& D, Tree& tree, bool verbose);
void fitch_margoliash_tree(std::vector<dmatrix_row>& D, std::string output, bool verbose);
float calculate_tree_fit(const Tree& tree, const std::vector<dmatrix_row>& D);
void optimize_branch_lengths(Tree& tree, const std::vector<dmatrix_row>& D);

// File I/O and utility functions
void write_to_file(std::string filename, std::vector<std::string> to_write);
void fasta_to_newick(std::string& filename, int kmer_length, std::string method, std::string algorithm, std::string output, bool verbose);
void paml_to_newick(std::string& filename, int kmer_length, int n_replicates, std::string method, std::string algorithm, std::string output, bool verbose);
std::vector<dmatrix_row> random_distance_matrix(int size);
void random_newick_tree(int size, std::string algorithm, std::string output, bool verbose);
void help();

// UPGMA algorithm declarations
void upgma(std::vector<dmatrix_row>& D, Tree& tree, bool verbose);
void upgma_tree(std::vector<dmatrix_row>& D, std::string output, bool verbose);

#endif

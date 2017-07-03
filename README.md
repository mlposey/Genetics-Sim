# A Genetics Simulator

## Introduction
This was a semester project for a course on object-oriented programming. The
task was to build program that could read in genetic information from two
parent organisms and then create a variable number of offspring. Doing so
required acquisition of domain knowledge (genetics) and an understanding of
design patterns and the software development lifecycle.

## Definition Files
The simulation creates an initial knowledge base from a definition file. That
file contains descriptions of:
* an organism
* genes that organism can have
* two parents and the gene configurations which they are made of

`external/instructor_files` contains two sample definition files that you can
use when running the program. If building from source, these files are copied
to the build directory using CMake.

## The Reproduction Process
Reproduction mimics genetic processes closely, with a few simplifications. In
`src/core`, you will find models of components such as alleles, genes, chromosomes,
and organisms. Organisms are composed of unpaired collections of chromosomes.
This is slightly easier than the human case. From there, much is the same.

Chromosomes contain two strands on which genes are placed. During
reproduction, the chromosomes of two parents are used to produce new
chromosomes for an offspring organism. Much is left to chance. Certain
complexities such as chromosomal crossover may occur. In that case, the alleles
on a gene exchange during genetic recombination. The occurrence of crossover,
as well as the variety of genes created, is printed in a final tally upon
program exit.

## Building The Code
Final development has been done using CMake 3.7 as the build system. There
are two build targets of interest: `genetics` and `tests`. The former is the
program itself and the latter builds the test suit. All tests were written using
[Google Test](https://github.com/google/googletest), which CMake will pull from
the GitHub repository and build as part of the process.

`cd` into the cloned directory and run the following:
```
cmake .
make -j<# of threads to use>
```
This builds all projects. You can specify either `genetics` or `tests` to
narrow compilation. E.g., `make -j4 tests`.

A new directory, `build`, should now exist in the root. It contains the target
executables.
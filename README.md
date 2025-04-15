# Classical Algorithms for Multi-objective Integer Programs

This repository is a submodule of [Quantum Approximate Multi-Objective Optimization (arXiv:2503.22797)](https://github.com/stefan-woerner/qamoo)
and includes code for classical MOIP algorithms accompanying the paper [Quantum Approximate Multi-Objective Optimization](https://arxiv.org/abs/2503.22797)
by Ayse Kotil, Elijah Pelofske, Stephanie Riedmüller, Daniel J. Egger, Stephan Eidenbenz, Thorsten Koch, and Stefan Woerner.

Both algorithms are written in C++ using the commercial solver CPLEX. 
Please follow the installation information given in the corresponding readme files.


## DCM

### License

This project is a modified version of the implementation of the [DCM algorithm by Hadi Charkhgard](http://hdl.handle.net/1959.13/1062187).

Modifications made in this repository:
- Deletion of unused algorithmic options from main
- Output path as additional argument for the main
- Modified output data to include the time of each found solution
- changed time limit to 20.000 seconds.

Please note that I am not the original author of the algorithm or its initial implementation. 
Credit for the original work goes to the respective authors and contributors.
All original code from that repository retains its original license. 
You can find a copy of the license in dcm/LICENSE.

Modifications made in this repository are also subject to the terms of the original license, unless otherwise specified.


### Algorithm

DCM (Disjunctive Constraint Method) is an exact algorithm that enumerates all non-dominated points by decomposing the objective space
in search regions via disjunctive constraints. 
The resulting subproblems are solved by an epsilon constraint method calling the solver CPLEX. 
Each found non-dominated point redefines the decomposition.
DCM guarantees each non-dominated point to be generated exactly once, and it limits the number of subregions
and the number of sets of disjunctive constraints.

Natashia Boland, Hadi Charkhgard, and Martin Savels-
bergh, “A new method for optimizing a linear function
over the efficient set of a multiobjective integer program,”
European Journal of Operational Research 260, 904–919
(2017).




## DPA



### License

This project is a modified version of the implementation of the [DPA algorithm by Kerstin Dächert](https://github.com/kerstindaechert/DefiningPointAlgorithm).

Modifications made in this repository:
- Deletion of unused algorithmic options from main
- Output path and timeout as additional argument for the main
- Modified output data to include 
  - the time of each found solution
  - the total solving time
  - the solution in the decision space

Please note that I am not the original author of the algorithm or its initial implementation.
Credit for the original work goes to the respective authors and contributors.
All original code from that repository retains its original license.
You can find a copy of the license in dpa/LICENSE.

Modifications made in this repository are also subject to the terms of the original license, unless otherwise specified.

### Algorithm

DPA (Disjunctive Constraint Method) is an exact algorithm that enumerates all non-dominated points by decomposing the objective space
in search regions and solve the resulting subproblems by
scalarization methods calling the solver CPLEX. Each
found non-dominated point redefines the decomposition.
The search region is a union of non-disjoint rectangular sets.
In each iteration, the IP restricted to one rectangular
search region is solved by the augmented (DPA-a) epsilon constraint method.
The algorithm guarantees that the number of local upper bound vectors is
minimal and that each non-dominated point is generated
exactly once.


Kerstin Dächert, Tino Fleuren, and Kathrin Klamroth,
“A simple, efficient and versatile objective space algorithm
for multiobjective integer programming,” Mathematical
Methods of Operations Research 100, 351–384 (2024).

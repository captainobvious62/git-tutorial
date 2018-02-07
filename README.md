# Git Tutorial
These are the lecture slides and demonstration code for a Git presentation for the [Aminzadeh Research Group](http://gen.usc.edu/). The premise of this project was to teach about git basics (``git add``, ``git commit``, ``git log``), git workflows (``git branch``, ``git merge``), and possibly higher-level features (``git stash``, ``git rebase``, etc.). There is roughly equal amount of lecture and theory as there is demonstration and real-world use cases. The demonstration is a simple Tic-Tac-Toe game. The implementation details are as follows.

The PDFs were created with [LaTeX](http://www.latex-project.org/), they can be found under *source*. There are several dependencies, but any distribution of [MiKTeX](https://miktex.org/), [MacTex](http://www.tug.org/mactex/), or most Linux distribution software should contain all the necessary packages. *demo.tex* can be compiled with ``pdflatex``, *slides.tex* uses ``xelatex``.

The demonstration code is written entirely with C++14 (not backwards compatible with older standards). It can compiled with GNU or Clang (i.e. ``clang++ *.cpp -std=c++14``) and ran with no parameters (i.e. ``./a.out``). The *demo* directory contains both the source code as it was written and a **separate** git repository — this is intentional. It was not added as a subtree or the like because it is used during the demonstration as a standalone repository.

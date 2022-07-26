# Makefiles

- At the minimum, a build system lets you automate the building and linking of 
files in your codebase.
- Makes sure that you only recompile the parts that you've changed, or the 
files that rely on those that were changed.
- Makes maintenance easier and avoid writing redundant code in the build script

Bash isn't a build system because it's not a great programming environment. It
doesn't allow you to meet point 2 above - you have to recompile everything. 
This is the problem that makefiles are trying to solve

In a Makefile, the syntax is to have the first line of each "rule" has the 
rule name followed by any dependancies, and below lines are indended once and 
state any shell commands. Makefile comments start with a `#` symbol

```Make
# This rule has no dependancies 
clean:
    rm -rf *.o
    rm -rf *.gch
```

By convention, we have a `make all` command that runs all the other commands
that are involved in the build system, and a `make clean` command that deletes
and cleans up the repo. 

You can use regex in the name of the makefile commands - and the % is a 
wildcard. This is probably the same in the rest of regex but I can't recall

The `all` rule will trigger when you run `make` with no specifier. You should
make sure that it depends on the right commands to run. Often, the build and 
linker stages are in different commands in a Makefile. 

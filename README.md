# 42 Pipex

This project is the discovery in detail and by programming of a UNIX mechanism that you already know. 
In this projec't we'll make our own implementation of the pipes we know and love from shell (``|``). 
To do so, we will start using a whole new set of functions that will introduce to us the concept of multiple 
processes, using pipes, forks and dups.

> ⚠️ **Warning**: Don't copy/paste code you don't understand: it's bad for you, and for the school.


## About the project 

This programm is executed in the following way

```shell
$> ./pipex file1 cmd1 cmd2 file2
```

Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with
their parameters.

The execution of the pipex program should do the same as the next shell command:

```
$> < file1 cmd1 | cmd2 > file2
```

Explore more in the pipex.pdf file!!!

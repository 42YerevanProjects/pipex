# 42 Pipex

This project is the discovery in detail and by programming of a UNIX mechanism that you already know. 
In this projec't we'll make our own implementation of the pipes we know and love from shell (``|``). 
To do so, we will start using a whole new set of functions that will introduce to us the concept of multiple 
processes, using pipes, forks and dups.

> ⚠️ **Warning**: Don't copy/paste code you don't understand: it's bad for you, and for the school.


## About the project 

In this project we are asked to code a program which will immitate the behavior of this shell command:

```shell
❯ < file1 cmd1 | cmd2 > file2
```
The idea of the program is that we take an infile and two commands, and pass the infile as the standard input to the first command, and then pipe the output of the first command to the second command, and finally save it all to a second file. Now that we've seen the command, let's break it down:

* ``<``: Used to denote that we will be passing the next argument as the standard input (stdin)
* ``file1``: Path to the file we want to open as the standard input. It must exist and should be opened read-only
* ``cmd1``: First command. It will receive the stdin and run a command with it, if applicable
* ``|``: Transforms the standard output (stdout) of the first command into the standard input (stdin) for the next command
* ``cmd2``: Receives the standard output of the first command as stdin and runs a command with it, if applicable
* ``>``: Redirects whatever is on the standard output (stdout) into a file, creating it if it does not exist
* ``file2``: Path to an output file which may or may not exist. If it exists, it will be truncated (emptied) and should be opened write-only

### The Pipex Algorithm

Our own implementation of the previous command will have a similar look. We will compile an executable called ``pipex``, which will only accept 4 commands in the mandatory part. This is what it expects to receive:

```shell
❯ ./pipex file1 cmd1 cmd2 file2
```

As mentioned before, this project is done with the help of a new set of tools: pipes, forks and dups, among others. Here's a brief description of what these functions do:

| Function | Descripton | Return Value |
| :-------:| :---------:| :----------: |
| ``pipe(fd)`` | Recives a ``fd[2]`` and opens ``fd[0]`` for reading and ``fd[1]`` for writing | ``-1`` on error |
| ``fork()`` | Splits process creating a child process with pid ``0`` | Process id of both processess (child = ``0``, parent > ``0``), ``-1`` on error |
| ``dup2(oldfd, newfd)`` | Closes ``newfd`` if needed, then duplicates ``oldfd`` into ``newfd`` | ``-1`` on error |
| ``execve(path, cmd, envp)`` | Receives full path of executable, NULL-terminated array of parameters, and environment. Replaces current process with that of the specified command | ``-1`` on error |


### Error Handling & fd Leaks

This project introduced to some the idea of file descriptor leaks. Leaving one file open longer than usual can really break things, so 
be careful with that.

1) As you may have noticed from the table of the new functions, they all may result in an error for all sorts of reasons. This is why aside from the usual malloc protection we have to check and properly manage scenarios when these new functions may result in an error. Also we need to check that the ``infile`` and ``outfile`` exist and/or have the correct permissions. Not to mention that the commands from the input may not exist.

2) It is very important to keep in mind that children after a fork will inherit all open file descriptors. For this reason it is very 
important to close every possible file descriptor inside the child process to avoid these kinds of leaks. Be carefull with them!

Resources

You can find some links and books below that might be useful during the project. You can find all the books in resources folder. 
Note that you do not have to read the books completly but you will find a lot of useful information there.

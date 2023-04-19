# Simple Shell Project for <a href="https://www.holbertonschool.com/">Holberton School</a>
A simple UNIX command line interpreter(in **C** ) that reads and implements basic commands from user input.

## Installation
All files compiled on Ubuntu 20.04

**Clone repo**:
`$ git clone https://github.com/solp22/holbertonschool-simple_shell.git`

**Compile**
`$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh `

**Run simple_shell**:
#### Interactive Mode
`$ ./hsh `

A prompt will follow upon running `./hsh` <br />
Simple_shell is ready to take commands: <br />
`($)  `

#### NonInteractive Mode
Pipe a command into the `hsh` shell as follows:
`$ echo "ls -la" | ./hsh`

## Usage
The following built-in functions are available in our shell
* `env`
* `exit`

Functions found by traversing the environment variable `PATH` may also be executed.
Examples of these functions:
* `ls` with or without arguments
* `pwd`
* `touch`

## C Functions and System calls allowed
```
all functions from strings.h
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
vfprintf (man 3 vfprintf)
sprintf (man 3 sprintf)
putchar (man 3 putchar)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

```

## File Descriptions


## Authors
Sol Puentes<a href='https://github.com/solp22'>Sol Puente Github</a>

Marcos Perdomo<a href='https://github.com/MarcosPerdomoVaz'>Marcos Perdomo Github</a>

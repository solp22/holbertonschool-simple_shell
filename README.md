# Simple Shell Project for <a href="https://www.holbertonschool.com/">Holberton School</a>
A simple UNIX command line interpreter(in **C** ) that reads and implements basic commands from user input.

<details>
    <summary><h2>Synopsis</h2></summary>
    The HSH simple_shell is a program that reads commands provided by a user through Standard Input Stream and attempts to execute them by means of low level system procedures. This is by using built in functions, or searching for executable programs in the operating system.

    The shell has two operating modes:

    **Interactive** and **Non-interactive**.
    In **Interactive mode**, the shell will display a prompt ($) indicating that the user can write and execute a command. After the command is run, the prompt will appear again a wait for a new command. This can go indefinitely as long as the user does not exit the shell.

    In **Non-interactive mode**, the shell will need to be run with a command input piped into its execution so that the command is run as soon as the Shell starts. In this mode no prompt will appear, and no further input will be expected from the user.

    In both modes, commands can be written with their absolute path or simply their executable name if they exist in one of the folders defined by the environmental variable PATH or as built in functions of the Shell.

</details>

<details>
    <summary><h3>Requirements</h3></summary>
     *Allowed editors: vi, vim, emac* s.
     
     *  You are not allowed to use global*  variables.
     
     *  No more than 5 functions per file* .
     
     *  it is not necessary to upload the test network to * your repository.
     
     *  The prototypes of all your functions should be included in your header file called main.h.
     
     *  Note that we will not provide the putchar function for this project.
</details>

<details>
    <summary><h3>C Functions and System calls allowed</h3></summary>
> all functions from strings.h
> access (man 2 access)
> chdir (man 2 chdir)
> close (man 2 close)
> closedir (man 3 closedir)
> execve (man 2 execve)
> exit (man 3 exit)
> _exit (man 2 _exit)
> fflush (man 3 fflush)
> fork (man 2 fork)
> free (man 3 free)
> getcwd (man 3 getcwd)
> getline (man 3 getline)
> getpid (man 2 getpid)
> isatty (man 3 isatty)
> kill (man 2 kill)
> malloc (man 3 malloc)
> open (man 2 open)
> opendir (man 3 opendir)
> perror (man 3 perror)
> printf (man 3 printf)
> fprintf (man 3 fprintf)
> vfprintf (man 3 vfprintf)
> sprintf (man 3 sprintf)
> putchar (man 3 putchar)
> read (man 2 read)
> readdir (man 3 readdir)
> signal (man 2 signal)
> stat (__xstat) (man 2 stat)
> lstat (__lxstat) (man 2 lstat)
> fstat (__fxstat) (man 2 fstat)
> strtok (man 3 strtok)
> wait (man 2 wait)
> waitpid (man 2 waitpid)
> wait3 (man 2 wait3)
> wait4 (man 2 wait4)
> write (man 2 write)
</details>

<details>
    <summary><h3>Installation</h3></summary>
All files compiled on Ubuntu 20.04

**Clone repo**:
`$ git clone https://github.com/solp22/holbertonschool-simple_shell.git`
</details>
<details>
    <summary><h3>Compilation</h3></summary>

    In order to test the HSH simple shell, you will need to open a terminal in a Linux distribution and go to the folder you just cloned from GitHub. In there, you will need to compile the program, which was tested in GNU GCC 5.5.0 with different error flags such as:

> **-Wall:**  Enables all the warnings about constructions.
> 
> **-Wextra :**  Enables some extra warning flags that are not enabled by  **-Wall**.
> 
> **-Werror:**  Make all warnings into hard errors.
> 
> **-pedantic:**  Issue all the mandatory diagnostics listed in the C standard.

The compilation code goes as follows:

    test@ubuntu:~/simple_shell$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

By default, the name of the executable will be **hsh**, but you can change it if you desire to do so.

**Execution:**

Once the program is compiled you will need to execute the shell with the following code:

Interactive mode: 

    test@ubuntu:~/simple_shell$ ./hsh

Non-interactive mode:

    test@ubuntu:~/simple_shell$ echo "command" | ./hsh
</details>

<details>
    <summary><h2>Files descriptions</h2></summary>

</details>

<details>
    <summary><h2>Authors</h2></summary>
Sol Puente <a href='https://github.com/solp22'> Sol Puente Github</a>

Marcos Perdomo <a href='https://github.com/MarcosPerdomoVaz'> Marcos Perdomo Github</a>

Mariana Echeto <a href="">Maria Echeto Github</a>
</details>

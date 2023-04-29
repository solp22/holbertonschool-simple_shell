<h1 align="center"> Holberton School Simple Shell Project </h1>
<p align= "justify">This is the second group project, carried out by Holberton students. The goal of this assignment is to replicate some of the basic functionalities of the standard Unix shell, including executing commands and running scripts. It also encourages group and team work with a randomly assigned partner.</p>
<p align= "justify"> A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts. </p>

<details>
  <summary><h2>Project Requirements</h2></summary>
    <ul>
      <li>Allowed editors: vi, vim, emacs</li>
      <li>All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89</li>
      <li>All files should end with a new line</li>
      <li>A README.md file, at the root of the folder of the project is mandatory</li>
      <li>The code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl</li>
      <li>Your shell should not have any memory leaks</li>
      <li>It is not allowed to use global variables</li>
      <li>No more than 5 functions per file</li>
      <li>All your header files should be include guarded</li>
      <li>Use system calls only when you need to</li>
    </ul>
</details>

<details>
  <summary><h2>How does it work?</h2></summary>
    <p align="justify">Our shell reads commands provided by a user through Standard Input Stream and attempts to execute them by means of low level system procedures. This is by using built-in functions, or searching for executable programs in the operating system.</p>
    <p align="justify">The shell has two operating modes: <b>Interactive</b> and <b>Non-interactive</b>.<p>
    <p align="justify">In <b>Interactive mode</b>, the shell will display a prompt (★) indicating that the user can write and execute a command. After the command is run, the prompt will appear again and wait for a new command. This can go indefinitely as long as the user does not exit the shell.</p>
    <p align="justify">In <b>Non-interactive mode</b>, the shell will need to be run with a command input piped into its execution so that the command is run as soon as the Shell starts. In this mode no prompt will appear, and no further input will be expected from the user.</p>
    <p align="justify">In both modes, commands can be written with their absolute path or simply their executable name if they exist in one of the folders defined by the environment variable PATH or as built-in functions of the Shell.</p>
</details>

<details>
  <summary><h2>Functions and system calls used</h2></summary>
  <ul>
    <li>access (man 2 access)</li>
    <li>execve (man 2 execve)</li>
    <li>exit (man 3 exit)</li>
    <li>fork (man 2 fork)</li>
    <li>free (man 3 free)</li>
    <li>getline (man 3 getline)</li>
    <li>isatty (man 3 isatty)</li>
    <li>malloc (man 3 malloc)</li>
    <li>perror (man 3 perror)</li>
    <li>printf (man 3 printf)</li>
    <li>sprintf (man 3 sprintf)</li>
    <li>strtok (man 3 strtok)</li>
    <li>strdup (man 3 strdup)</li>
    <li>strlen (man 3 strlen)</li>
    <li>strcmp (man 3 strcmp)</li>
    <li>strncmp (man 3 strncmp)</li>
    <li>waitpid (man 2 waitpid)</li>
  </ul>
</details>

<details>
  <summary><h2>Usage</h2></summary>
  <p>To use this shell clone this repository and compile the files in the following way:</p>
  
  ```
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
  ```
  
  <p>Using interatcive mode it should work this way:</p>
  
  ```
  $ ./hsh
  ★ /bin/ls
  hsh main.c shell.c
  ★
  ★ exit
  $
  ```
  
  <p>And using non-interactive mode it should work this way:</p>
  
  ```
  $ echo "/bin/ls" | ./hsh
  hsh main.c shell.c test_ls_2
  $
  $ cat test_ls_2
  /bin/ls
  /bin/ls
  $
  $ cat test_ls_2 | ./hsh
  hsh main.c shell.c test_ls_2
  hsh main.c shell.c test_ls_2
  $
  ```
  
</details>

<details>
<summary><h2>Files</h2></summary>

### [shell.c](/shell.c/)

### [path.c](/path.c/)

### [tokenizer.c](/tokenizer.c/)

### [execute_command.c](/execute_command.c/)

### [free_array.c](/free_array.c/)

### [main.h](/main.h/)

</details>

<p align="center">Authors:</p>
<p align="center"><a href= "https://github.com/solp22">Sol Puente</a></p>
<p align="center"><a href= "https://github.com/marulaska">Mariana Echeto</a></p>

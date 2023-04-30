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
  git clone https://github.com/solp22/holbertonschool-simple_shell.git
  ```
  
  ```
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
  ```
  
  <p>Using interactive mode it should work this way:</p>
  
  ```
  $ ./hsh
  ★ /bin/ls
  hsh main.c shell.c
  ★
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
  
  <h3>Built-ins</h3>
  <p>You can type 'exit' to exit the shell like so:</p>
  
  ```
  $ ./hsh
  ★ exit
  $
  ```
  
  <p>And you can also type 'env' to print a list of all current environment variables:</p>
  
  ```
  $ ./hsh
  ★ env
  HOSTNAME=41e118c3a4d9
  LANGUAGE=en_US:en
  PWD=/holbertonschool-simple_shell
  TZ=America/Los_Angeles
  HOME=/root
  LANG=en_US.UTF-8
  LESSCLOSE=/usr/bin/lesspipe %s %s
  TERM=xterm
  LESSOPEN=| /usr/bin/lesspipe %s
  SHLVL=1
  LC_ALL=en_US.UTF-8
  PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
  OLDPWD=/
  _=./hsh
  ★
  ```
  
</details>

<details>
<summary><h2>Files</h2></summary>

### [shell.c](/shell.c/)
<p align="justify">This file contains the main code of the shell. It reads the input given and passes it to the other functions to be tokenized, handle the command's path and finally, being executed. It also handles cases such as the exit built-in, sending a NULL input, and giving a NULL path.</p>

### [path.c](/path.c/)
This file contains the functions that are vital for handling the path.
<ul>
  <li><b>_getenv</b> - This function searches for an environment variable by iterating through the environ array and comparing each element to the specified string. If a match is found, the function returns a pointer to the value of the variable. If no match is found, the function returns NULL.</li>
  <li><b>_which</b> - This function tokenizes the path's value and stores it in an array. It then appends the command to each directory to find which is the correct path for executing the command, it it finds an executable path it returns the value, if not, it returns NULL.</li>
  <li><b>print_env</b> - This function is in charge of the env built-in. When the user passes 'env', the shell prints a list of all current environment variables.</li>
</ul>

### [tokenizer.c](/tokenizer.c/)
This file contains a function that is in charge of tokenizing strings depending on the delimiter given, and returns an array with each token.

### [execute_command.c](/execute_command.c/)
This file has the functions that will enable the command to be executed.
<ul>
  <li><b>execute_command</b> - executes the command by using the fork system call to create a child process and then calling the execve function. The parent function will simply wait for the child to finish its process by using the system call waitpid.
  <li><b>execute_command_ap</b> - handles the execution of a command when the absolute path is given.
</ul>

### [free_array.c](/free_array.c/)
This file has a simple function to free an array and make it easier to save lines of code.

### [main.h](/main.h/)
This file contains all the libraries used, as well as the environ variable and the prototypes of each function.
</details>

<p align="center">Authors:</p>
<p align="center"><a href= "https://github.com/solp22">Sol Puente</a></p>
<p align="center"><a href= "https://github.com/marulaska">Mariana Echeto</a></p>

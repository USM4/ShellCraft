# ShellCraft

## Overview (ALL YOU NEED TO RUN IT IS TO HAVE DOCKER IN YOUR MACHINE)
This project is a **simple shell** implemented in **C**, designed to execute commands similar to a Unix shell. It supports basic command execution, argument parsing, and process handling.

## Features
- Executes built-in and external commands
- Handles multiple arguments
- Implements a basic prompt
- Supports interactive and non-interactive modes
- Handles process creation using `fork()` and `execve()`

## Requirements
- CC compiler
- Make utility

## Installation
Clone the repository:
```sh
git clone https://github.com/your-username/simple_shell.git
cd simple_shell
```

## Compilation
Use the provided **Makefile** to compile the project:
```sh
make
```
This generates an executable named **shell**.

## Usage
All you need is docker and run this:
```sh
docker build -t minishell .
docker run -it minishell
```
You will see a prompt where you can type commands:
```
➜ minishell$ ls -l
➜ minishell$ echo "Hello, World!"
➜ minishell$ exit
```

## Makefile Commands
| Command        | Description                                  |
|---------------|----------------------------------------------|
| `make`        | Compiles the shell                          |
| `make clean`  | Removes the compiled executable and objects |
| `make re`     | Cleans and recompiles the minishell             |

## Example Session
```
$ ./minishell
minishell$ ls
file1.c  file2.c  shell  Makefile  README.md
minishell$ echo "ShellCraft in C"
ShellCraft in C
minishell$ exit
```

## Contributing
Feel free to fork the repository and submit pull requests!

---
**Author:** Oussama Redoine (USM4)


# Pipex

Pipex is a project designed to simulate piping in a Unix shell environment. It enables the user to chain commands using pipes, redirecting output from one command as input to the next. The project mimics the behavior of shell piping and input/output redirection, providing an essential understanding of process management and file descriptor manipulation in Unix-like systems.

## Features

- **Pipe Simulation**: Pipex allows users to chain multiple commands, passing the output of one command as input to the next.
- **Input/Output Redirection**: The project also supports redirection of input and output to/from files.
- **Process Management**: It simulates how processes are created and managed in a Unix environment.
- **Error Handling**: Pipex ensures proper error handling for common issues like invalid commands or missing files.

## Installation

To use Pipex, clone the repository and compile the source files.

```bash
git clone https://github.com/your-username/pipex.git
cd pipex
make
Ensure that you have make installed and are working in a Unix-like environment (Linux, macOS, etc.).

Usage
Once installed, Pipex can be executed from the command line as follows:

bash
Copy code
./pipex <infile> <cmd1> <cmd2> <outfile>
Parameters
<infile>: The file containing the input to be processed.
<cmd1>: The first command to be executed.
<cmd2>: The second command to be executed.
<outfile>: The file where the final output is written.
For example:

bash
Copy code
./pipex input.txt "grep hello" "awk '{print $1}'" output.txt
This will execute the following steps:

Read input.txt.
Pipe its contents to grep hello, searching for lines containing the word "hello".
Pipe the output of grep to awk '{print $1}', extracting the first word of each line.
Write the result to output.txt.
Requirements
A Unix-like operating system (Linux, macOS, etc.).
A C compiler (e.g., GCC or Clang).
Basic knowledge of Unix commands and pipes.
Example
For example, given a file file.txt with the following content:

Copy code
hello world
hello pipex
goodbye world
Running the following command:

bash
Copy code
./pipex file.txt "grep hello" "awk '{print $2}'" output.txt
Will create output.txt containing:

Copy code
world
pipex
Project Structure
css
Copy code
pipex/
│
├── src/
│   ├── main.c
│   ├── pipex.c
│   └── utils.c
│
├── include/
│   └── pipex.h
│
├── Makefile
└── README.md
main.c: Contains the entry point of the program and handles user input.
pipex.c: Implements the core functionality for pipe handling and command execution.
utils.c: Includes helper functions like error handling, file management, and argument parsing.
pipex.h: Header file containing function declarations and necessary includes.
Contributing
Feel free to fork the project, open issues, and submit pull requests for improvements or bug fixes.

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Commit your changes (git commit -am 'Add new feature').
Push to the branch (git push origin feature-branch).
Create a new pull request.

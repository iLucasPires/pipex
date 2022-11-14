<p align="center">
    <img src="https://game.42sp.org.br/static/assets/achievements/pipexm.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-orange.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-115%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

# pipex

This project is about creating a pipe system between two processes. The first process will take the commands and arguments from the standard input, and the second process will take the commands and arguments from the standard output. The first process will execute the first command and pass the output to the second process, which will execute the second command and pass the output to the standard output.

## How to use
- Clone the repository
- Run `make` to compile the executable
- Run `./pipex file1 cmd1 cmd2 file2` to execute the program

## Mandatory part

- [x] The executable file must be named pipex.
- [x] The project must be written in accordance with the Norm.
- [x] The executable must take three arguments: the name of the first file, the name of the second file, and the command line to execute between the two files.

## Bonus part

- [x] The executable must take four arguments: the name of the first file, the name of the second file, the command line to execute before the first file, and the command line to execute after the second file.
- [x] The executable must handle multiple commands in the command line.
- [x] The executable must handle errors.
- [ ] The executable must be able to handle the command line as a Heredoc.

## Example

two commands

``` bash
./pipex infile "ls -l" "wc -l" outfile
```

more than two commands

``` bash
./pipex infile "ls -l" "grep a" "wc -l" outfile
```

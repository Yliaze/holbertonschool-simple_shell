
# Simple Shell

Our Simple Shell is a command-line interface program written in C language that allows users to interact with their operating system by executing shell commands. 
It is designed to replicate the basic functionalities of a Unix shell, such as the ability to navigate the file system, run executables, and manage processes.

# Table of Contents

-   How to Install and Run the Project
-   How to Use the Project
-   Credits

# Table of Contents

![This is a flowchart of our Simple Shell](https://github.com/Yliaze/holbertonschool-simple_shell/blob/main/Simple%20Shell%20Flowchart.drawio.png?raw=true)

# How to Install and Run our Simple Shell

To install and run Simple Shell, follow these steps:

1.  Clone the repository using the following command:
```c
git clone https://github.com/Yliaze/holbertonschool-simple_shell.git
```
    
2.  Navigate to the directory where the repository was cloned.
3.  Compile the program by running the following command:
```c
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
    
4.  Run the program by typing the following command: 
```c
./hsh
```

# How to Use our Simple Shell

To use Simple Shell, type a command and press Enter. The program will execute the command and display the output on the screen.

Here are some examples of commands that you can run:

-   `ls`: List the contents of the current directory.
-   `mkdir`: Create a new directory.
-   `echo`: Display a message on the screen.
-   `exit`: Exihet the sll.

You can also run commands that require arguments, such as:

-   `ls -l`: List the contents of the current directory in long format.
-   `mkdir newdir`: Create a new directory called "newdir".
-   `echo "Hello, Taieb!"`: Display the message "Hello, Taieb!" on the screen.

# Credits

This Simple Shell was created by Axel Malka ([@Maxel6](https://github.com/Maxel6)) and Benjamin Alazet ([@Yliaze](https://github.com/Yliaze)) as a project for their web development training at Holberton School.
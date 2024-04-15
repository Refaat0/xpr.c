# xpr.c
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Make](https://img.shields.io/badge/Makefile-E8E8E8.svg?style=for-the-badge&logo=GNU&logoColor=black)

>xpr.c is a command line application that uses a "Read-Eval-Print-Loop" interface to evaluate mathematical expressions provided by a user.  

<p align="center">
  <img src="./assets/ss.png" />
</p>

## About The Project
This project was meant to be a gateway into the world of low-level computer programming. I wanted to work on a project that would introduce me to concepts such as lexical analysis & parsing,
and thought that this project would be a great place to start (it was!). This project will be used as a stepping stone for future low level projects I want to work on, 
such as other parsers, interpreters, compilers, and languages. 

### Under The Hood
xpr.c is a command line application that uses a "Read-Eval-Print-Loop" interface to evaluate mathematical expressions provided by a user. The application starts off in the "Read" state which fetches a string from the user, preferably one that represents an infix expression like `2+2*(4/2*(4*2)^2)`. The application then moves on the the "Eval" state which will validate that the string is infact an
infix expression, tokenize the string into a sequence of tokens, reoder the tokens into postfix notation using The Shunting Yard algorithm, then  evaluate the postfix expression using a stack based algorithm.

### Limitations
xpr.c only supports the following  mathematical operators: `^ * / + -`. It also **does not support** multi-digit operands, floating point operands, or signed operands (coming soon!)

## Getting Started
These instructions will help you get a copy of this project up & running on your machine.

### Prerequisites 
You **must** have a gcc & make installed on your machine to compile & build this project

### Installation 
Clone the repository to your local machine:
```
C:\Users\Refaat\Desktop\mathematical-expression-evaluator> git clone https://github.com/Refaat0/xpr.c .
```

Build the project with make:
```
C:\Users\Refaat\Desktop\mathematical-expression-evaluator> make
```

Run the program:
```
C:\Users\Refaat\Desktop\mathematical-expression-evaluator> xpr.exe
```

## Usage
After running the program you will be dropped into a REPL interface. At this point you can type almost any infix expression you want such as `2+2*(4/2*(4*2)^2)`. Please see
[limitations](###Limitations) for more details
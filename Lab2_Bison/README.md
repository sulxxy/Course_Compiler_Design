# Implementing a Parser using Bison

## Problem Decription
This exercise consists of the implementation of a syntax analyzer for RTSL.

To create the  parser, the *Bison* parser generator will be used. The parser will use the tokens produced
by the ![lexer](). 

The parser must correctly accept all the input codes which are a correct implementation of RTSL, and should not accept codes with syntax errors. Additionally, a number of semantic checks have to be implemented.

### RTSL Grammar
There is no formal specification of the RTSL language. However, it is based on GLSL, which in turn is very similar to C. The paper provided in the previous assignment describes the additional features and differences between RTSL and GLSL.

A grammar specification of GLSL can be found in chapter 9 of
![GLSLangSpec.4.40.pdf](https://www.opengl.org/registry/doc/GLSLangSpec.4.40.pdf)

To start your implementation, we suggest to have a look at following ANSI C lexer and parser
implementation:
* ![ANSI-C-grammar-l](http://www.quut.com/c/ANSI-C-grammar-l-2011.html)
* ![ANSI-C-grammar-y](http://www.quut.com/c/ANSI-C-grammar-y.html)
(note that this grammar has two shift/reduce conflicts)

Be aware that many ANSI C features are not implemented in RTLS, for instance, there are no external declarations, pointers, atomic and alignment specifiers. Your goal is to implement a parser able to understand all the features used in the provided test sets.

While RTSL grammar is similar to C specification, there are few extra features to handle:
* a translation unit corresponds to a single input shader file (a .rtsl file), therefore the parser should not care about implementing yywrap()logic (use %option noyywrap);
* a translation unit is the full processed code, and it should have a shader definition (e.g., class Example : rt_Material) and zero or more interface methods, depending on the shader type (e.g., a Light can only have constructor() and illumination()). This information is available in Table 1 from the RTLS reference paper (and copied later in this document). Note that a shader may implement one of the functions in the interface specification for that shader  type, but implementing a wrong one is considered a (semantic) error (e.g., a primitive cannot implement illuminance(), as it is designed for light );
* a declaration may have a qualifier, e.g. public vec3 position.
![alt tag]()

### Output
As expected output, you will have to produce two different outputs for each input shader (.rtsl).

On stdout, you should print some information of the ongoing parsing, namely the head of (some) production rules. Those include generic statement, if/else, function definition and shader definition (with the shader type). Use as reference the output file provided in the assignment tar.gz file in order to understand what to print.
On stderr, you should print only information about errors during parsing. You should print
* Nothing, if the file is correctly parsed
* A simple generic “Syntax error” message, for general parsing error
* A specific error message for few specific semantic errors

## Solution
### Syntax Analysis
To analyse the syntax of RTSL language, we just need to build its grammar definition. 

### Semantic Checking
As mentioned above, some simple semantic checking needs to be done in this part. My general idea is, since we are just asked to check semantic errors about the legality of states and interfaces in a shader(in RTSL, a source file holds a shader), I only need to judge what the current shader is. And when got a state or interface from Lexer, we need to know whether it belongs to the current shader. This can be esasily done throw some help function. 
To do this, we need to maintain some string arrays for every shader, which contain the states and interfaces for each shader. When read a shader from lexer, save it to a global variable(current_shader), and when read a state or interface, check it in the current shader's lists(check_state(char* text) and check_interface(char* text)).

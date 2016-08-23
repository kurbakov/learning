In case of the code optimization's need, I would do the following:

##### Step 0: Check weather the code works at all. If not => debugger can help.

In GCC => -g flag will allow debugging in the program. Our goal => make the code work correctly.

##### Step 1: Find the slowest part of the code, or part that can be optimized.

If we are talking about big projects, reading the code is not the best idea. There are bench of the code profiler. For example in GCC/G++ is a flag "-pg". This flag allows us to analyse the code and also gives us the tips, what we can improve in the code.

Link: https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html#Instrumentation-Options

Our goal: find the possible optimization parts of the code.

##### Step 2: Optimization of the code.

Usually we have a slow code because of the to many nested for loops, duplication of the function, wrong datatypes (not optimized for the memory), also in some cases we can face the speed limit of the external library, that is included in the project.

Also make sense to check some big objects we copy. So reduce the memory complexity. It will allow us to increase the speed.

And also important to add, that everything that we can remove from for loop must be removed and called as minimum times as possible.

##### Step 3: Pray that it will help or ask for help your college.

Maybe it sounds stupid, but external view is sometimes way better that 3 hours for reading by yourself the code.

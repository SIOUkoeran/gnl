# Function name 
get_next_line
# Prototype 
char *get_next_line(int fd)
# Turn in files
get_next_line.c, get_next_line_utils.c, get_next_line.h
# Parameters
File descriptor to read from
# Return value
-  Read line : correct behavior
-  NULL : nothing else to read or an error occurred
# External functs
read, malloc, free
# Description 
write a function which return a line read from a file descriptor
- with a single static variable.
- To be able to manage multiple file descriptors with your get_next_line
# Instruction
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

Calling your function get_next_line in a loop will then allow you to read the text
available on the file descriptor one line at a time until the end of it.
• Your function should return the line that has just been read. If there is nothing
else to read or if an error has occurred it should return NULL.



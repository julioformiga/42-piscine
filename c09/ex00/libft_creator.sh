#!/bin/bash
cc *.c -Wall -Werror -Wextra -c
ar rcs libft.a *.o

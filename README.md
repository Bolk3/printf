_This activity has been created as part of the 42 curriculum by resonnet_

#   Description
printf is a project that aims to reproduce some part of said function.

the mendatory flags are:
- %c: char
- %s: string
- %p: pointer value in hexadecimal
- %i and %d: int
- %u: unsigned int
- %x: an int in lowercase hexadecimal
- %X: an int in uppercase hexadecimal
- %%: the % char

##  Attributes
intput:
- const char *format
- ..., 0 to n 

##  known issues

#   Instruction

|command        |effect                                 |
|:--------------|--------------------------------------:|
|`make`         |compile and create libftprintf.a       |
|`make clean`   |remove the .o of the lib               |
|`make fclean`  |`make clean` and remove libftprintf.a  |
|`make re`      |`make fclean` and `make`               |

#   References

- [stdio.h page](https://www.w3schools.com/c/c_ref_stdio.php)
- [stdarg.h page](https://koor.fr/C/cstdarg/cstdarg.wp)

_No Ai has been used during this project_
#   Data Structure and Algorithm

##  Data Structure
```c
enum e_type {
	STR,
	CHR,
	INT,
	UINT,
	PTR,
	LOW_X,
	UPP_X,
	ERROR,
	PERCENT
};
```

```c
typedef struct s_print 
{
	enum e_type	type;
	char		*data;
	int			size;
} t_print;
```

##  Algorithm

# _printf()
## Description
This repo contains a replicated version of the C standard library function, printf.  
### Project requirements
- Code compliance with [Betty](https://github.com/holbertonschool/Betty) style and document guidelines.
- Code compiled using flags: `-Wall`, `-Werror`, `-Wextra`, `-pedantic`, `-Wno-format`
- Cannot use global variables.
- Restricted to no more than 5 functions per file.
- Function prototypes should be included in header file `holberton.h`
- Header files should be include guarded.
- Authorized functions and macros:
..* `write` (`man 2 write`)
..* `malloc` (`man 3 malloc`)
..* `free` (`man 3 free`)
..* `va_start` (`man 3 va_start`)
..* `va_end` (`man 3 va_end`)
..* `va_copy` (`man 3 va_copy`)
..* `va_arg` (`man 3 va_arg`)


## File Descriptions
- `holberton.h`: Header file containing  `<stdarg.h>`, constant `BUFFER_SIZE`, `directive` structure, all program function prototypes.
- `_printf.c`: entry point main function
- `get_directive_function.c`: calls pointer function corresponding to it's format selector
- `get_int_length.c`: counts the number of digits in an integer.
- `helper_funcs.c`: helper functions for formatting _printf arguments:
      - `_strlen`: counts characters in string 
      - `reverseStr`: reverses order of characters in a string
      - `dectohex`: converts a number from base 10 to base 16
      - `uitohex`: converts an unsigned integer to base 16

- `put_c_s_perc_i_ui.c`: write data types to buffer
      - `put_char`: writes a 1-byte character to buffer
      - `put_string`: writes character array to buffer
      - `put_percent`: writes a single % character to buffer
      - `put_int`: writes an integer to buffer
      - `put_unsigned`: writes an unsigned integer to buffer
      
- `put_hex_bi_oct_pointer.c`: write numbers of varying base to buffer
      - `put_hex_lower`: writes lower case hex number to buffer
      - `put_hex_upper`: writes upper case hex number ot buffer
      - `put_binary`: writes a binary number to buffer
      - `put_oct`: writes a base 8 number to buffer
      - `put_pointer_address`: prints address of pointer
      
 - `put_rev-rot13.c`: functions for writing to a rot13 encrypted string to buffer

## Team

*Stuart Kuredjian* - [Github](https://github.com/dbconfession78) || [Twitter](https://twitter.com/StueyGK)

*Christian Agha* - [Github](https://github.com/ChristianAgha) || [Twitter](https://twitter.com/ChristyanAgha)

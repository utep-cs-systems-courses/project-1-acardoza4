Tokenizer:
====================
# About Tokenizer

Tokenizer takes the user's input and tokenizes it separated by a space, as
well as storing the tokenized strings in a history that can be viewed later
on. It consists of three separate c files: user_int.c, history.c and
tokenizer.c.

## How To Run Tokenizer:

Tokenizer is compiled with ***make*** in the terminal, then it can be run
using ***./tokenizer*** in the terminal as well.

Tokenizer will display a **$** sing, indicating it is ready for the user's input. The
input can be as long as 30 characters. Tokenizer will show the tokenized
string and store it in history.

To view an input stored in history, the user can enter ***!#***  where # is
the index of the desired input (e.g ***$!1*** will show the first tokenized
string). If the index provided has no tokens, an error will be displayed.

If the user wants to quit the program, entering ***q*** will end
Tokenizer. Tokenizer will display the user's history and a goodbye message,
indicating a successful termination.

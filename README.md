* Shady Flag Library

This is a library for parsing command line flags.
Just include the .h file and you're good to go.
Example:
```int hello = flag_int("--testing", 420, "<something> Hello World");```
This will put on the variable hello the value following the --testing command
line flag, or the default value 420 if the flag is not present.

# Alias-Sudo
Configurable c program to modify ~/.bashrc to run a custom sudo.

The program just appends "alias sudo='sudo SUDO_COMMAND; sudo'". This could be used to get root from a non-root code execution.

If SUDO_COMMAND has no output then when a user runs a command, at least in my setup, nothing would alert the user an alias is be substituted.

Build with:

    $gcc sudo-make-me-a-sandwich.c

Run with:

    $./a.out

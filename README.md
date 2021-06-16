# Alias-Sudo
Configurable c program to modify ~/.bashrc to run a custom sudo.

The program just appends "alias sudo='sudo SUDO_COMMAND; sudo'". 

This is a simple proof of concept to show one reason why running untrusted code is bad, even when not as root.

Build with:

    $gcc sudo-make-me-a-sandwich.c

Run with:

    $./a.out

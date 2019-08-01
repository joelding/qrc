

# SHELL PROGRAMMING
## life cycle of an environment variable
- `VARNAME="my value"` set variable **only** for current shell
- `export VARNAME="my value"`  set variable for current shell and **all processes** started from current shell
- To set it **permanently** for all future bash sessions add such line to your `.bashrc` file in your `$HOME` directory.
- To set it permanently, and **system wide** (all users, all processes) add set variable in /etc/environment: `sudo -H gedit /etc/environment` This file only accepts variable assignments like:
`VARNAME="my value"` Do not use the `export` keyword here.

**references**
1. [link](https://askubuntu.com/questions/58814/how-do-i-add-environment-variables)


> Written with [StackEdit](https://stackedit.io/).
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTgxODI3ODc1OF19
-->
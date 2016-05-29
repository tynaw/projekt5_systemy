# projekt5_systemy
This is a simple IPC system.

# PRECONDITIONS

To use "aspell" feature, you should have at least one dictionary
available on your system. Go to:

ftp://ftp.gnu.org/gnu/aspell/dict/0index.html

pick your language, download, unzip file and follow the README 
instructions available in downloaded folder. 

# INSTALLATION

To use it, please use one simple command:

make

to build whole project.

Then, run 

./server [key]

and

./client [key]

in separated terminals. Key is an integer value which should be the same
for both client and server. You'll be able to send simple message between
terminals using IPC!

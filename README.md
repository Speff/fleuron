# fleuron

fleuron is a simple C library used to time functions. Initialize the `Fleuron` datastructure with `fleuron_init()`. Call `fleuron_add(Fleuron variable, char* comment)` to set timing points. `fleuron_print(Fleuron variable)` prints all timing points to the console. `fleuron_delete(Fleuron variable)` frees the datastructure.

Compile with MinGW64

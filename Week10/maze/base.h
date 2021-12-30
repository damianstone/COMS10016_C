/* The base module provides success and fail functions. */

// Report a test success message plus newline. Avoids the need for stdio.h.
void succeed(char *message);

// Report a test failure or bug, and stop the program.
void fail(char *message);

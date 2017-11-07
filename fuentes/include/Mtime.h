#ifndef _MTIME
#define _MTIME

#include <stdio.h>
#include <ctime>

    #if defined _WIN32 || defined _WIN64
        #include <windows.h>
        /////////// Declaración de la clase TIEMPO /////////////

        class Mtime
        {
        public:
            /* retorna "a - b" en segundos */
            double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
        };

    #endif
#endif // _MTIME

/*Copyright 2014 Almudena Garcia Jurado-Centurion

This file is part of Practica1_AMC.

Practica1_AMC is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Practica1_AMC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Practica1_AMC.  If not, see <http://www.gnu.org/licenses/>.*/


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

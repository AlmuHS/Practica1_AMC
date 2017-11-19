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


#include "Mtime.h"
/* retorna "a - b" en segundos */

#if defined _WIN32 || defined _WIN64
	double Mtime::performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
    {
		LARGE_INTEGER freq;
        QueryPerformanceFrequency(&freq);
        return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
    }
#endif

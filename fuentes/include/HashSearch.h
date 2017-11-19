/*Copyright 2017 Almudena Garcia Jurado-Centurion

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


#ifndef HASHSEARCH_H
#define HASHSEARCH_H

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

#include "vector_ops.h"

using namespace std;


class HashSearch
{
    vector<list<int> > hash_opened;
    vector<int> hash_closed;

    public:
        HashSearch();

        void add_element_opened(vector<int> &v);

        void add_element_closed(vector<int> &v);

        int closed_hash(int intempts, int key, int size);

        int search_element_opened(int key);

        int search_element_closed(int key);

        void show_closed_table();

        void show_opened_table();

};

#endif // HASHSEARCH_H

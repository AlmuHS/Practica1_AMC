#ifndef GENVECTOR_H
#define GENVECTOR_H

#include <vector>
#include <iostream>

class GenVector
{
    private:
        std::vector<int> v;

    public:
        GenVector(std::vector<int> v);

        std::vector<int> GenRandomVector();

        void showVector(const std::vector<int> v);
        void showVector();
};

#endif // GENVECTOR_H

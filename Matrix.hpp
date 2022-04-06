#include <iostream>
#include <vector>
#include <string>

namespace zich{

class Matrix
{
    std::vector<double> _list;
    int _col;
    int _row;
    
    void posSize(int col,int row);
    void sameSize(Matrix mat1,Matrix mat2);
    int sum() const;

    public:

    Matrix(std::vector<double> list,int col,int row);
    Matrix operator+(const Matrix & mat);
    Matrix &operator+=(const Matrix & mat);
    Matrix &operator++();

    Matrix operator-(const Matrix & mat);
    Matrix &operator-=(const Matrix & mat);
    Matrix &operator--();

    bool operator>(const Matrix & mat);
    bool operator>=(const Matrix & mat);
    bool operator==(const Matrix & mat);
    bool operator<=(const Matrix & mat);
    bool operator<(const Matrix & mat);
    bool operator!=(const Matrix & mat);

    Matrix operator*(const Matrix & mat);
    Matrix operator*=(const Matrix & mat);
    Matrix operator*(const double mul);
    Matrix operator*=(const double mul);
    

    friend std::ostream &operator<<(std::ostream &os, const Matrix &a);
    // friend std::istream &operator>>(std::istream &os, Matrix &mat);
    friend Matrix operator*(const double a, Matrix &b);
    friend Matrix operator-(Matrix &a);

    void print();
    double multiplication(const int Row, const Matrix &b, const int Col);

};
};
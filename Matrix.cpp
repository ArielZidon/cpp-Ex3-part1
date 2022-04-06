#include "Matrix.hpp"

using namespace std;

namespace zich{
Matrix::Matrix(std::vector<double> list,int col,int row)
{
    posSize(col,row);
    if(col*row!=list.size())
        throw std::invalid_argument("not equal");
    this->_list = list;
    this->_col = col;
    this->_row=row; 
}

void Matrix::posSize(int col,int row)
{
    if(row<=0 || col<=0)
         throw std::invalid_argument("received negative value");
}

void Matrix::sameSize(Matrix mat1,Matrix mat2)
{
    if(mat1._row!=mat2._row || mat1._col!=mat2._col)
        throw std::invalid_argument("the matrix didnt have the same size");
    
}

int Matrix::sum() const
{
    size_t length = (size_t)(this->_row*this->_col);
    int sum = 0;
    for(size_t i = 0;i<length;i++)
    {
        sum+=this->_list[i];
    }
    return sum;
}

// void Matrix::print()
// {
//     int length = this->_row*this->_col;
//     std::cout<<"[";
//     for(size_t i = 0;i<length;i++)
//     {   
//         if(((int)(i))%this->_row==0 && i!=0)
//         {
//             std::cout<<"]\n[";
//         }
//         else if(i!=0)
//             std::cout<<" ";

//         std::cout<<this->_list[i];
//     }
//     std::cout<<"]";
// }

Matrix Matrix::operator+(const Matrix & mat)
{
    sameSize(*this,mat);
    size_t length = (size_t)(this->_row*this->_col);
    std::vector<double> res;
    res.resize(length);
    for(size_t i=0;i<length;i++)
    {
        res[i]= mat._list[i]+this->_list[i];
    }
    
    return Matrix(res,_col,_row);
}

Matrix &Matrix::operator+=(const Matrix & mat)
{
    sameSize(*this,mat);
   *this=(*this)+mat;
   return *this;
}

Matrix &Matrix::operator++()
{
    size_t length = (size_t)(this->_row*this->_col);
    for(size_t i=0;i<length;i++)
    {
        this->_list[i]+=1;
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix & mat)
{
    sameSize(*this,mat);
    size_t length = (size_t)(this->_row*this->_col);
    std::vector<double> res;
    res.resize(length);
    for(size_t i=0;i<length;i++)
    {
        res[i]= this->_list[i]-mat._list[i];
    }
    return Matrix(res,_col,_row);
}
Matrix &Matrix::operator-=(const Matrix & mat)
{
    sameSize(*this,mat);
    *this=(*this)-mat;
   return *this;
}
Matrix &Matrix::operator--()
{
    size_t length = (size_t)(this->_row*this->_col);
    for(size_t i=0;i<length;i++)
    {
        this->_list[i]-=1;
    }
    return *this;
}

bool Matrix::operator>(const Matrix & mat)
{
    if(this->sum()>mat.sum())
        return true;
    else
        return false;
}
bool Matrix::operator>=(const Matrix & mat)
{
    if(this->sum()>=mat.sum())
        return true;
    else
        return false;
}
bool Matrix::operator==(const Matrix & mat)
{
    size_t length = (size_t)(_col*_row);
    for(size_t i = 0;i<length;i++)
    {
        if(mat._list[i]!=this->_list[i])
            return false;
    }
    return true;
}
bool Matrix::operator<=(const Matrix & mat)
{
       if(this->sum()<=mat.sum())
        return true;
    else
        return false;
}
bool Matrix::operator<(const Matrix & mat)
{
       if(this->sum()<mat.sum())
        return true;
    else
        return false;
}
bool Matrix::operator!=(const Matrix & mat)
{
    size_t length = (size_t)(_col*_row);
    for(size_t i = 0;i<length;i++)
    {
        if(mat._list[i]!=this->_list[i])
            return true;
    }
    return false;
}

double Matrix::multiplication(const int Row, const Matrix & mat, const int Col)
{
    double sum = 0;
    for (int i = 0; i < this->_col; i++)
    {
        sum += this->_list[(size_t)(this->_col * Row + i)] * mat._list[(size_t)(mat._col * i + Col)];
    }
    return sum;
}

Matrix Matrix::operator*(const Matrix & mat)
{   
    if(_row!=mat._col)
        throw std::invalid_argument("received negative value");

    vector<double> res;
    res.resize((size_t)(_col*mat._row));
    double mul =0;
    
    for(int i=0;i<_col;i++)
    {
        for(int j=0;j<mat._row;j++)
        {
            res[(size_t)(i * mat._col + j)] = multiplication(i,mat,j);
        }
    }

    return Matrix(res,_col,mat._row);   
}

Matrix Matrix::operator*=(const Matrix & mat)
{
    return mat;
}

Matrix Matrix::operator*(const double mul)
{
    size_t length = (size_t)(this->_row*this->_col);
    for(size_t i=0;i<length;i++)
    {
        if(this->_list[i]!=0)
        {
            this->_list[i]*=mul;
        }
    }
    return *this;   
}

Matrix Matrix::operator*=(const double mul)
{
    size_t length = (size_t)(_col*_row);
    for(size_t i = 0;i<length;i++)
    {
        if(this->_list[i]!=0)
            this->_list[i]*=mul;
    }
    return *this;
}

ostream &operator<<(ostream &os, const Matrix &mat)
    {
        int length = mat._row*mat._col;
        os<<'[';
        for(size_t i = 0;i<length;i++)
        {   
            if(((int)(i))%mat._row==0 && i!=0)
            {
                os<<"]\n[";
            }
            else if(i!=0)
                os<<" ";

            os<<mat._list[i];
        }
        os<<"]"<< endl;

        return os;
    }
    
    Matrix operator*(const double val, Matrix &mat)
    {
        return mat * val;
    }

    Matrix operator-(Matrix &a)
    {
        return a * -1;
    }
}



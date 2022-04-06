
#include "Matrix.hpp"
#include<iostream>
#include<stdexcept>
#include "doctest.h"
#include <algorithm>


using namespace std;
using namespace zich;

vector<double> unit = {1, 0, 0, 0, 1, 0, 0, 0, 1};         // unit matrix 3*3
vector<double> zero16 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // zero matrix 4*4

vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1}; // matrix 3*3
   

TEST_CASE("operator + -  = < > =< =>")
{
    Matrix mat1(unit, 3, 3);
    Matrix mat2(unit, 3, 3);
    mat1 *= 3;
    mat2 *= 5;
    Matrix mat4(unit, 3, 3);
    mat4*= 8;
    Matrix one({1, 1, 1, 1, 1, 1, 1, 1, 1}, 3, 3);

    SUBCASE("+ -  Test")
    {

        cout<<mat1<<endl;
        cout<<mat2<<endl;
        cout<<mat4<<endl;
        cout<<"---------------------"<<endl;
        CHECK(((mat1 + mat2) == mat4) == true);
        CHECK(((mat4 - mat2) == mat1) == true);
        CHECK(((mat4 - mat1) == mat2) == true);
        CHECK((one == mat1) == false); // the matrix ix not equal although their amount is equal
    }

    SUBCASE("== != Test")
    {
        CHECK(((mat4- mat2) != mat1) == false);
        CHECK(((mat4 - mat1) != mat2) == false);
        CHECK(((mat1 + mat2) != mat4) == false);
        CHECK((one != mat1) == true); // the matrix ix not equal although their amount is equal
    }

    SUBCASE("< <= Test")
    {
        // cout<<mat1<<endl;
        // cout<<mat2<<endl;
        // cout<<mat4<<endl;
        // cout<<"---------------------"<<endl;
        
        CHECK((mat2 <mat4 ) == true);
        CHECK((mat1 <= mat2) == true);
        CHECK((mat1 <= mat1) == true);
        CHECK((mat1 <= one) == true);
        CHECK((mat2 <= mat1) == false);
        CHECK((one == one) == true);
        CHECK((mat4 < mat2) == false);
        CHECK((mat2 < mat4) == true);
        CHECK((mat1 <= mat2) == true);
        CHECK((mat2 <= mat1) == false);
        CHECK((mat4 <= mat2) == false);
        CHECK((mat4 <= mat1) == false);
        CHECK((mat1 <= mat1) == true);
        CHECK((mat2 <= mat2) == true);
        CHECK((mat1 <= mat1) == true);
        CHECK((mat4 <= mat4) == true);
        CHECK((mat2 < mat1) == false);
        CHECK((mat4 < mat1) == false);
        CHECK((mat4 < mat2) == false);
    }
    SUBCASE("> >= Test")
    {
        CHECK((mat2 >= mat1) == true);
        CHECK((mat4 >= mat2) == true);
        CHECK((mat4 >= mat1) == true);
        CHECK((mat1 >= mat1) == true);
        CHECK((mat2 >= mat2) == true);
        CHECK((mat1 >= mat1) == true);
        CHECK((mat4 >= mat4) == true);
        CHECK((mat2 > mat1) == true);
        CHECK((mat4 > mat1) == true);
        CHECK((mat4 > mat2) == true);
        CHECK((mat1 >= one) == true);
        CHECK((mat2 >= one) == true);
        CHECK((mat4 >= one) == true);
    }
}

TEST_CASE("Constructor and operator")
{

    SUBCASE("mathing bettwin the vector and the size of the matrix")
    {
        SUBCASE("Good Size For Zero16")
        {
            CHECK_NOTHROW(Matrix(zero16, 16, 1));
            CHECK_NOTHROW(Matrix(zero16, 1, 16));
            CHECK_NOTHROW(Matrix(zero16, 4, 4));
            CHECK_NOTHROW(Matrix(zero16, 8, 2));
            CHECK_NOTHROW(Matrix(zero16, 2, 8));
            CHECK_NOTHROW(Matrix(unit, 3, 3));
            CHECK_NOTHROW(Matrix(unit, 3, 3));
            CHECK_NOTHROW(Matrix(unit, 1, 9));
            CHECK_NOTHROW(Matrix(unit, 9, 1));

        }

        SUBCASE("Bad Size For Zero16")
        {
            for(int i = 0;i<30;i++)
            {
                for(int j=0;j<30;j++)
                {
                    if(i*j!=16)
                    {
                        CHECK_THROWS(Matrix(zero16, i, j));
                    }
                    if(i*j!=9)
                    {
                        CHECK_THROWS(Matrix(unit, i, j));
                    }

                }
            }
    
        }
    }

    SUBCASE("Constructor Test")
    {
        SUBCASE("positive size")
        {
            CHECK_THROWS(Matrix(unit, 4, -1));
            CHECK_THROWS(Matrix(unit, 7, 0));
            CHECK_THROWS(Matrix(unit, -3, 9));
            CHECK_THROWS(Matrix(unit, 1, -3));
            CHECK_THROWS(Matrix(unit, -4, -1));
            CHECK_THROWS(Matrix(unit, -7, 0));
            CHECK_THROWS(Matrix(unit, -3, 9));
            CHECK_THROWS(Matrix(unit, -1, -3));
            CHECK_THROWS(Matrix(unit, 0, 0));
            for(int i = 0;i>-50;i--)
            {
                for(int j = 0;j>-50;j--)
                {
                        CHECK_THROWS(Matrix(unit, i, j));
                }
            
            }
            
        }
    }

SUBCASE("Operator+ Test")
{
    Matrix z44(zero16, 4, 4); // 4*4 matrix
    Matrix z82(zero16, 8, 2); // 8*2 matrix
    Matrix z28(zero16, 2, 8); // 2*8 matrix
    Matrix u33(unit, 3, 3);  // 3*3 matrix
    Matrix u19(unit, 1, 9);  // 1*9 matrix
    Matrix u91(unit, 3, 3);  // 9*1 matrix
    CHECK_NOTHROW(u33 + u33);
    CHECK_THROWS(u33+z44);
    CHECK_THROWS(z82+z44);
    CHECK_THROWS(z28+z44);
    CHECK_THROWS(u33+z28);
    CHECK_THROWS(u33+z82);
}

SUBCASE("Operator- Test")
{
    Matrix z44(zero16, 4, 4); // 4*4 matrix
    Matrix z82(zero16, 8, 2); // 8*2 matrix
    Matrix z28(zero16, 2, 8); // 2*8 matrix
    Matrix u33(unit, 3, 3);  // 3*3 matrix
    Matrix u19(unit, 1, 9);  // 1*9 matrix
    Matrix u91(unit, 3, 3);  // 9*1 matrix
    CHECK_NOTHROW(u33 - u33);
    CHECK_THROWS(u33-z44);
    CHECK_THROWS(z82-z44);
    CHECK_THROWS(z28-z44);
    CHECK_THROWS(u33-z28);
    CHECK_THROWS(u33-z82);
}
SUBCASE("Operator* double Test")
{
    Matrix mat1(unit, 3, 3);
    Matrix mat2(unit, 3, 3);
    mat2*10;
    for(int i;i<20;i++)
    CHECK((mat2*i==mat1*10*i) == true);
}
SUBCASE("Operator* double Test")
{
    Matrix mat1(unit, 3, 3);
    Matrix mat2(unit, 3, 3);
    Matrix mat3(unit, 3, 3);
    mat1*3;
    mat2*3;
    mat3*9;
    for(int i=0;i<50;i++)
        CHECK((i*mat1*mat2==i*mat3) == true);
    
    Matrix mat4(zero16,4,4);
    for(int i=0;i<100;i++)
        CHECK_THROWS(i*mat4*mat3);
}

}  

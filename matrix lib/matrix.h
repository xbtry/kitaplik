#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
enum RCodes
        {
            SUCCESS = 0,
            ERR_EXCESS_SIZE_ARRAY = -1,
            ERR_EXCESS_SIZE_PUTELEM = -2,
            ERR_EXCESS_SIZE_GETELEM = -3,
        };

template <class T>
class Matrix
{
    private:
        T *matrix;
        int row;
        int column;
        
    public:
        //========================================================================//
        //Kurucu & Yıkıcı fonksiyonlar
        //Constructor&Destructor

        Matrix(int row, int column);
        Matrix(int row, int column,T* elem);
        ~Matrix(){delete[] matrix;}

        //========================================================================//
        //Getir & Koy fonksiyonları
        //Gets & Puts

        T getElem(int row, int column) const;
        int putElem(int row,int column,T elem);
        int putArray(T* array);
             
        //========================================================================//
        //Operatör aşırı-yükleme
        //Operator Overloading
        
        Matrix<T> operator * (const Matrix &matf) const;

        //========================================================================//
        //Diğer Fonksiyonlar
        //Other funcs
        void printMat();
        void zeroMat();
};

//Sade kurma fonksiyonu
template <class T>
Matrix<T>::Matrix(int row, int column){
    matrix = new T[row*column];
    this->row = row;
    this->column = column;
    zeroMat();

}
//Diziyle birlikte kurma fonksiyonu
template <class T>
Matrix<T>::Matrix(int row, int column,T* elem){
    putArray(elem);
}

//Operator Overloading
template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &matf) const{
    Matrix<T> newmatrix(this->row,matf.column);
    T temp;
    for(int i = 1; i < this->row+1; i++)
    {
        for(int j = 1; j < matf.column+1; j++)
        {
            for(int k = 1; k < matf.row+1; k++)
            {
                temp += matf.getElem(k,j) * getElem(i,k);
                //std::cout << "MATB[" << i << "][" << k << "] = " << matf.getElem(i,k) << '\n';
                //std::cout << "MATA[" << k << "][" << j << "] = " << getElem(k,j) << '\n';
                if(k == matf.row)
                {
                    newmatrix.putElem(i,j,temp);
                    temp = 0;
                }                    
            }
        }
    }
    newmatrix.printMat();
    return newmatrix;
}

//Tek bir eleman döndüren fonksiyon.
template <class T>
T Matrix<T>::getElem(int row, int column) const{
    if (row != 0 && column != 0 && matrix != nullptr)
    {
        //Satır ve sütun numaralarını kontrol et, büyükse veya küçükse -1 dön.
        //Check row and column values,if its bigger or smaller than actual values, return -1.
        if(column <= this->column || column != 0 && row <= this->row || row != 0 )
        {
        //1 Boyutlu Dizi için tekrar düzenle, yani eleman sayısını dizinin 0dan başladığını göze alarak ayarla.
        //(İstenen Satır-1) x (Sütun) + (İstenen Sütun-1)
        //Re-Design for 1D array. Set element number according to arrays, because arrays start 0, not 1;
        int elem_num = (this->column*(row-1)) + (column-1); 
        if (elem_num < 0) 
            return -1;
        else
            return matrix[elem_num];  
        }    
    }
    else{
        //HATA
        return ERR_EXCESS_SIZE_GETELEM;
    }  
}

template <class T>
int Matrix<T>::putElem(int row,int column,T elem){
    
    if (row != 0 && column != 0 && matrix != nullptr){
        int elem_num = (this->column*(row-1)) + (column-1); 
        if(elem_num < 0)
            return -1;
        else
            matrix[elem_num] = elem;        
    }
    else{
        //HATA 
        return ERR_EXCESS_SIZE_PUTELEM;
    }
}

//Matrise 1 boyutlu dizi koyar.
//Replaces Matrix elements to 1D array.
template <class T>
int Matrix<T>::putArray(T* array){
    for (int i = 0; i < (row*column); i++)
    {
        matrix[i] = array[i];
    }
    return 0;
}

//0 matrisi oluşturur.
//Fill the matrix with 0's.
template <class T>
void Matrix<T>::zeroMat()
{
    /*for(int frow = 0; frow < this->row; frow++)
    {
        for(int fcolumn = 0; fcolumn < this->column; frow++)
        {
            putElem(frow,fcolumn,0);
        }
    }*/
    for(int i=0; i < row*column; i++)
    {
        int rowN = (int)(i/column)+1;
        int columnN = (i%column)+1;
        putElem(rowN,columnN,0);
    }
}

template <class T>
void Matrix<T>::printMat()
{
    for(int i=0; i < row*column; i++)
    {
        int rowN = (int)(i/column)+1;
        int columnN = (i%column)+1;
        std::cout << "MATRIX [" << rowN << "] [" << columnN << "] = " << getElem(rowN,columnN)<< '\n';
        
    }
    std::cout << "========================================\n";
}

#endif
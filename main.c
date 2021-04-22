#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct matrix
{
    int size;

    int* matrix;

};

//6
int det(struct matrix mat)
{
    if(mat.size == 2)
    {
        return (*(mat.matrix + 0) *  *(mat.matrix + 2)) - (*(mat.matrix + 0) *  *(mat.matrix + 2));
    }
    else if (mat.size == 3)
    {
        return (*(mat.matrix + 0) *  *(mat.matrix + 4) * *(mat.matrix + 8))
            + (*(mat.matrix + 3) *  *(mat.matrix + 7) *  *(mat.matrix + 2))
            + (*(mat.matrix + 6) *  *(mat.matrix + 1) *  *(mat.matrix + 5))
            - (*(mat.matrix + 2) *  *(mat.matrix + 4) *  *(mat.matrix + 6))
            - (*(mat.matrix + 5) *  *(mat.matrix + 7) *  *(mat.matrix + 0))
            - (*(mat.matrix + 8) *  *(mat.matrix + 1) *  *(mat.matrix + 3));
    }
}

//5
bool areEqual(struct matrix mat1, struct matrix mat2)
{
    int i = 0;

    for (; i < mat1.size * mat1.size; i++)
    {
        if( *(mat1.matrix + i) != *(mat2.matrix + i))
            return 0;
    }

    return 1;
}

//1
struct matrix Add(struct matrix mat1, struct matrix mat2)
{
    int i = 0;

    struct matrix retMat;
    retMat.size = mat1.size;
    retMat.matrix = (int*)malloc(retMat.size* retMat.size * sizeof(int));

    for (; i < mat1.size * mat1.size; i++)
    {
        *(retMat.matrix + i) = *(mat1.matrix + i) + *(mat2.matrix + i);
    }

    return retMat;
}

//2
struct matrix Subb(struct matrix mat1, struct matrix mat2)
{
    int i = 0;

    struct matrix retMat;
    retMat.size = mat1.size;
    retMat.matrix = (int*)malloc(retMat.size* retMat.size * sizeof(int));

    for (; i < mat1.size * mat1.size; i++)
    {
        *(retMat.matrix + i) = *(mat1.matrix + i) - *(mat2.matrix + i);
    }

    return retMat;
}

//3
struct matrix MultMats(struct matrix mat1, struct matrix mat2)
{


    struct matrix retMat;
    retMat.size = mat1.size;
    retMat.matrix = (int*)malloc(retMat.size* retMat.size * sizeof(int));


    for (int i = 0; i < mat1.size; i++)
    {

        for ( int j = 0; j < mat1.size; j++)
        {
            *(retMat.matrix + i*retMat.size + j) = 0;
            for (int i1 = 0; i1 < mat1.size; i1++)
            {
                *(retMat.matrix + i*retMat.size + j)
                    += *(mat1.matrix + i * (mat1.size) + i1) * (*(mat2.matrix + i1 * (mat1.size) + j));
            }

        }

    }

    return retMat;
}

//4
struct matrix Mult(struct matrix mat1, int mult)
{
    int i = 0;

    struct matrix retMat;
    retMat.size = mat1.size;
    retMat.matrix = (int*)malloc(retMat.size* retMat.size * sizeof(int));

    for (; i < mat1.size * mat1.size; i++)
    {
        *(retMat.matrix + i) = *(mat1.matrix + i) * mult;
    }

    return retMat;
}

void displayMat(struct matrix mat)
{
    int i = 0;
    for (; i < mat.size * mat.size; i++)
    {
        if (i % mat.size == 0)
            printf(" \n ");

        printf(" %d ", *(mat.matrix + i));
    }
}

int* ReadNewElements(int numOfElems)
{
    int* newRow = (int*)malloc((numOfElems) * sizeof(int));
    int newNum;

    int counter = 0;
    while (counter < numOfElems)
    {
        scanf("%d", &newNum);
        *(newRow + counter) = newNum;
        counter += 1;
    }

    return newRow;
}

//7
void transposeHelp(int *array, int size){

    int new_array[size * size];

    int i = 0;
    for (; i < size; ++i )
    {
        int j = 0;
        for (; j < size; ++j )
        {
            int index1 = i*size+j;
            int index2 = j*size+i;

            new_array[index2] = array[index1];
        }
    }

    i = 0;
    for (; i<size*size; i++)
    {
        array[i] = new_array[i];
    }
}

//7
struct matrix Transpose(struct matrix* mat)
{
    transposeHelp(mat->matrix, mat->size);
}

//8
int diagSum(struct matrix mat)
{
    int sum = 0;

    int i = 0;
    for (; i < mat.size * mat.size; i+=mat.size + 1 )
    {
        sum += *(mat.matrix + i);

    }
    return sum;
}

//10
bool isLowerTriangularMatrix(struct matrix mat)
{
    int i = 0;
    for (; i < mat.size; i++ )
    {
        int j = i + 1;
        for (; j < mat.size; j++ )
        {
            if( *(mat.matrix + i + j * mat.size ) != 0)
                return 0;
        }
    }

    return 1;
}

//9
bool isUpperTriangularMatrix(struct matrix mat)
{
    Transpose(&mat);
    bool isMatLowerTriangularMatrix = isLowerTriangularMatrix(mat);
    Transpose(&mat);

    return isMatLowerTriangularMatrix;
}

int counteZeros(struct matrix mat, bool *foundNeg)
{
    int i = 0;
    int counter = 0;
    for (; i < mat.size * mat.size; i++)
    {
        if(*(mat.matrix + i) == 0)
            counter++;
        else if(*(mat.matrix + i) < 0)
        {
            *foundNeg = true;
        }
    }

    return counter;
}

//12
bool isRunny(struct matrix mat)     //czy rzadka
{
    bool negli;     //tylko dlatego ze funckja tego wyumaga
    return counteZeros(mat, &negli) >= mat.size*mat.size;
}

//11
bool isIdentity(struct matrix mat)
{
    bool foundNeg = false;
    //gdy liczba zer jest rowna liczbie elementow bez diagonali
    //oraz suma na diagonali jest rowna mat.size(czyli same 1 na diagonali)
    //oraz nie ma liczb ujemnych w calej macierzy
    return (counteZeros(mat, &foundNeg) == mat.size * (mat.size - 1)  &&  diagSum(mat) == mat.size  &&  !foundNeg);
}

bool isSymetric(struct matrix mat)
{

    int i = 0;
    for (; i < mat.size; i++)
    {
        int j = 0;
        for (; j < mat.size; j++)
        {
            if(*(mat.matrix + mat.size * i + j) != *(mat.matrix + j * mat.size + i))
                return 0;
        }
    }

    return 1;
}

int main()
{
    struct matrix mat1;
    struct matrix mat2;

    mat1.size = 2;
    mat2.size = 2;

    mat1.matrix = ReadNewElements( mat1.size *  mat1.size );
    mat2.matrix = ReadNewElements(mat2.size * mat2.size );

    displayMat(mat1);
    printf("\n");

    displayMat(mat2);
    printf("\n");

    printf("Macierz 1 == Macierz 2 :  %d", areEqual(mat1, mat2));

    printf("\n\nMacierz 1 T: \n");
    Transpose(&mat1);
    displayMat(mat1);

    printf("\n\nMacierz 1 T znowu: \n");
    Transpose(&mat1);
    displayMat(mat1);

    printf("\n\nMacierz 1 * Macierz 2: \n");
    displayMat(MultMats(mat1, mat2));

    printf("\n\nMacierz 1 suma diag: %d", diagSum(mat1));

    printf("\n\nMacierz 1  jest gorna trojk: %d", isUpperTriangularMatrix(mat1));

    printf("\n\nCzy maciesz jednostkowa (M1): %d", isIdentity(mat1));

    printf("\n\nCzy maciesz symetryczna (M1): %d", isSymetric(mat1));

    printf("\n");

}



#include <iostream>
#include <Math.h>

using namespace std;

void showNumberAsArray(unsigned short arr)
{
    cout << "[ ";
    unsigned short counter = 16;
    while (arr != 0)
    {
        if((arr & 1)!=0)
            cout << (arr & 1) * counter << " ";
        arr = arr >> 1;
        counter--;
    }
    cout << "]";
    cout << endl;
}

unsigned short getComplementOfArray(unsigned short arr)
{
    return  ~(arr);
}

unsigned short getCommonPart(unsigned short arr1, unsigned short arr2)
{
    return (arr1 & arr2);
}

unsigned short getSumOfArrays(unsigned short arr1, unsigned short arr2)
{
    return (arr1 | arr2);
}

unsigned short getDiffOfArrays(unsigned short arr1, unsigned short arr2)
{
    return ((arr1 ^ arr2) & arr1);
}

unsigned short getSymmDiffOfArrays(unsigned short arr1, unsigned short arr2)
{
    return (arr1 ^ arr2);
}

bool includes(unsigned short arr, unsigned short pos)
{
    pos = 16 - pos;
    unsigned short ret = arr >> pos;

    return (ret & 1);
}

void add(unsigned short&arr, unsigned short element)
{
    element = 16 - element;
    arr = (arr | short(pow(2, element)));
}

void del(unsigned short& arr, unsigned short element)
{
    element = 16 - element;
    unsigned short power = 1 << element;    //power = 2^(element)
    arr = getDiffOfArrays(arr, power);
}

unsigned short getCardinality(unsigned short arr)
{
    unsigned short counter = 0;
    while (arr != 0)
    {
        if ((arr & 1) != 0)
            counter++;
        arr = arr >> 1;
    }

    return counter;
}


int main()
{
    unsigned short arrayRandom= 0b0000111000101010;
    unsigned short arrayNine= 0b0000000000001001;

    cout << endl;
    showNumberAsArray(arrayRandom);
    showNumberAsArray(arrayNine);
    cout << endl;

    cout << "getComplementOfArray: " << endl;
    showNumberAsArray(getComplementOfArray(arrayRandom));

    cout << "getCommonPart: " << endl;
    showNumberAsArray(getCommonPart(arrayRandom, arrayNine));

    cout << "getSumOfArrays: " << endl;
    showNumberAsArray(getSumOfArrays(arrayRandom, arrayNine));

    cout << "getDiffOfArrays: " << endl;
    showNumberAsArray(getDiffOfArrays(arrayRandom, arrayNine));

    cout << "includes 5: " << endl;
    cout<< includes(arrayRandom, 5)<<endl;

    cout << "added 2 to arrayNine: " << endl;
    add(arrayNine, 2);
    showNumberAsArray(arrayNine);

    cout << "deleted 13 from arrayNine: " << endl;
    del(arrayNine, 13);
    showNumberAsArray(arrayNine);

    cout << "getCardinality of  arrayNine: " << endl;
    cout << getCardinality(arrayNine);


}


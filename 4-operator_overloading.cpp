#include <iostream>
#include <string> 

using namespace std;

class ComplexNumber
{
private:
	float re;
	float im;

public:

	ComplexNumber(float realpart = 0, float imaginarypart = 0)
	{
		re = realpart;
		im = imaginarypart;
	}

	friend ostream& operator<< (ostream& output, const ComplexNumber& cn)
	{
		string outputString = cn.re != 0 ? to_string(cn.re) : "";

		if (cn.im > 0)
		{
			if (cn.re != 0)
				outputString += "+" + to_string(cn.im) + "i";
			else
				outputString += to_string(cn.im) + "i";;
		}
		else if (cn.im < 0)
		{
			outputString += to_string(cn.im) + "i";
		}


		output << outputString;
		return output;
	};

	friend istream& operator>> (istream& input, ComplexNumber& cn)
	{
		input >> cn.re >> cn.im;

		return input;
	};

	friend ComplexNumber operator + (ComplexNumber& cn1, ComplexNumber& cn2)
	{
		float resultReal = cn1.re + cn2.re;
		float resultIm = cn1.im + cn2.im;

		ComplexNumber result(resultReal, resultIm);

		return result;
	}

	ComplexNumber& operator += (ComplexNumber& cn2)
	{
		*this = *this + cn2;
		return *this;

	};

	//prefix
	friend ComplexNumber operator ++ (ComplexNumber& cn1)
	{
		float resultReal = cn1.re + 1;
		float resultIm = cn1.im;

		ComplexNumber result(resultReal, resultIm);


		cn1 = result;

		return result;
	}

	//postfix
	ComplexNumber operator ++ (int)
	{
		return ComplexNumber(re, im++);;
	}

	friend ComplexNumber operator - (ComplexNumber& cn1, ComplexNumber& cn2)
	{
		float resultReal = cn1.re - cn2.re;
		float resultIm = cn1.im - cn2.im;

		ComplexNumber result(resultReal, resultIm);

		return result;
	};

	friend ComplexNumber operator - (ComplexNumber& cn1)
	{
		float resultReal = -cn1.re;
		float resultIm = -cn1.im;

		ComplexNumber result(resultReal, resultIm);

		return result;
	};

	ComplexNumber& operator -= (ComplexNumber& cn2)
	{
		//ComplexNumber result(re - cn2.re, im - cn2.im);

		*this = *this - cn2;
		return *this;

	};

	//prefix
	friend ComplexNumber operator -- (ComplexNumber& cn1)
	{
		float resultReal = cn1.re - 1;
		float resultIm = cn1.im;

		ComplexNumber result(resultReal, resultIm);


		cn1 = result;

		return result;
	}

	//postfix
	ComplexNumber operator -- (int)
	{
		return ComplexNumber(re, im--);
	}

	friend ComplexNumber operator * (ComplexNumber& cn1, ComplexNumber& cn2)
	{
		float resultReal = cn1.re * cn2.re - (cn1.im * cn2.im);

		float resultIm = cn1.re * cn2.im + (cn1.im * cn2.re);

		ComplexNumber result(resultReal, resultIm);

		return result;
	};

	ComplexNumber& operator *= ( ComplexNumber& cn2)
	{
		*this = *this * cn2;;
		return *this;
	};

	friend ComplexNumber operator / (ComplexNumber& cn1, ComplexNumber& cn2)
	{
		ComplexNumber coupling = !cn2;		//coupling == sprzezenie (?)
		ComplexNumber numerator = cn1 * coupling;
		ComplexNumber denumerator = cn2 * coupling;

		if (denumerator.re == 0) return ComplexNumber(0, 0);

		ComplexNumber result(numerator.re / denumerator.re, numerator.im / denumerator.re);


		return result;

	};

	ComplexNumber& operator = (ComplexNumber cn2)
	{
		re = cn2.re;
		im = cn2.im;
		return *this;
	};

	ComplexNumber& operator /= (ComplexNumber cn2)
	{
		*this = *this / cn2;
		return *this;
	};

	friend ComplexNumber operator ! (ComplexNumber& cn1)
	{
		float resultReal = cn1.re;
		float resultIm = -cn1.im;

		ComplexNumber result(resultReal, resultIm);

		//cn1 = result;
		return result;
	};

	friend bool operator == (ComplexNumber& cn1, ComplexNumber& cn2)
	{
		return cn1.re == cn2.re && cn1.im == cn2.im;
	};

	friend bool operator != (ComplexNumber& cn1, ComplexNumber& cn2)
	{
		return !(cn1 == cn2);
	};

};

int main()
{
	ComplexNumber num1(0, 0);
	ComplexNumber num2(0, 0);



	cout << "poddaj liczbe zespolona(num1): " << endl;
	cin >> num1;
	cout << "poddaj liczbe zespolona(num2): " << endl;
	cin >> num2;

	
	cout << "---------------------- " << endl;

	cout << "NUM1: \t" << num1 << endl;
	cout << "NUM2: \t" << num2 << endl;

	cout << "---------------------- " << endl;

	cout << "SUMA: \t\t" << num1 + num2 << endl;
	cout << "ROZNICA: \t" << num1 - num2 << endl;
	cout << "ILOCZYN: \t" << num1 * num2 << endl;
	cout << "ILORAZ: \t" << num1 / num2 << endl;

	cout << "---------------------- " << endl;

	cout << "ROWNOSC(1 i 2): \t" << (num1 == num2) << endl;
	cout << "NIEROWNOSC(1 i 2): \t" << (num1 != num2) << endl;

	cout << "---------------------- " << endl;

	num1 += num2;
	cout << "num1 += num2:  \t" << num1 << endl;
	num1 -= num2;
	cout << "num1 -= num2:  \t" << num1 << endl;
	num1 *= num2;
	cout << "num1 *= num2:  \t" << num1 << endl;
	num1 /= num2;
	cout << "num1 /= num2:  \t" << num1 << endl;

	cout << "---------------------- " << endl;

	cout << "-num1:  \t" << -num1 << endl;
	cout << "!num1:  \t" << !num1 << endl;

	cout << "---------------------- " << endl;

	cout << "NUM2: \t\t" << num2 << endl;
	cout << "++NUM2: \t" << ++num2 << endl;
	cout << "--NUM2: \t" << --num2 << endl;

	cout << "---------------------- " << endl;

	cout << "NUM2++: \t" << num2++ << endl;
	cout << "NUM2: \t\t" << num2 << endl;

	cout << "NUM2--: \t" << num2-- << endl;
	cout << "NUM2: \t\t" << num2 << endl;

	cout << "---------------------- " << endl;

	cout << "NUM1: \t" << num1 << endl;
	cout << "NUM2: \t" << num2 << endl;


	cout << "---------------------- " << endl;
	num1 = num2;
	cout << "NUM1=NUM2:"<< endl;
	cout << "NUM1: \t" << num1 << endl;
	cout << "NUM2: \t" << num2 << endl;

}


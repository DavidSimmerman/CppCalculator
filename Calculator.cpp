#include <iostream>
#include <string>

using namespace std;

class calcFunctions
{
public:
	char getFunction()
	{
		string funcStr;
		cout << "Add, Subtract, Multiply, Divide: ";
		cin >> funcStr;

		char funcChar = toupper(funcStr.front());
		return funcChar;
	}
	float getNum(int iter, float prevAnswer)
	{
		string sNum;
		string sNumTestAns;
		float finalAns;
		
		if(iter == 1)
		{
			cout << "Enter your first number: ";
			cin >> sNum;
		}
		else if (iter == 2)
		{
			cout << "Enter your second number: ";
			cin >> sNum;
		}

		sNumTestAns = toupper(sNum.front());

		if (sNumTestAns == "A")
		{
			return prevAnswer;
		}
		else
		{
			finalAns = stof (sNum);
			return finalAns;
		}
	}
	bool qRepeat()
	{
		string repeatResponse;
		cout << "Would you like to perform another calculation? (y/n): ";
		cin >> repeatResponse;
		repeatResponse = toupper(repeatResponse.front());

		if (repeatResponse == "Y") {
			cout << "===============================================================\n";
			return true;
		}
		else
		{
			return false;
		}

	}
};

class Calculations 
{
public:
	float add(float x,float y)
	{
		float addAns = x + y;
		cout << x << "+" << y << "=" << addAns << endl;
		return addAns;
	}
	float sub(float x, float y)
	{
		float subAns = x - y;
		cout << x << "-" << y << "=" << subAns << endl;
		return subAns;
	}
	float mult(float x, float y)
	{
		float multAns = x * y;
		cout << x << "x" << y << "=" << multAns << endl;
		return multAns;
	}
	float div(float x, float y)
	{
		float divAns = x / y;
		cout << x << "/" << y << "=" << divAns << endl;
		return divAns;
	}
};

int main()
{
	calcFunctions calcFunc;
	Calculations calc;

	bool repeat = true;
	float answer = 0;
	float numOne;
	float numTwo;
	char function;
	
	while (repeat)
	{
		function = calcFunc.getFunction();

		numOne = calcFunc.getNum(1, answer);
		numTwo = calcFunc.getNum(2, answer);

		if (function == 'A')
		{
			calc.add(numOne, numTwo);
		}
		else if (function == 'S')
		{
			calc.sub(numOne, numTwo);
		}
		else if (function == 'M')
		{
			calc.mult(numOne, numTwo);
		}
		else if (function == 'D')
		{
			calc.div(numOne, numTwo);
		}

		repeat = calcFunc.qRepeat();
	}
}


#include <iostream>
#include <vector>
using namespace std;

int maxThreeNumbers(int num1, int num2, int num3);
void printCount1ToN();
int checkPrimeNumOrNot();
void checkEvenOrOdd(int);
void sumNumTillN();
int sumOfEvenNumTillN();
void printAreaOfCircle();
void printFactorialOfNumber();
void printPrimeFrom1ToN();
void printDigitsOfInteger();
void createNumberUsingDigits();
void printBinaryRepresentationOfDecimal();
void printDecimalRepresentationOfBinary();
void countSetBits();
vector<double> convertTemperature(double);
int main()
{

    // int max=maxThreeNumbers(3,55,55);
    // cout<<"Maximumn "<<max<<endl;

    // printCount1ToN();

    // if(checkPrimeNumOrNot()){
    //     cout<<"Prime No.";
    // }else{
    //     cout<<"Not a prime no";
    // }

    // checkEvenOrOdd(100);

    // sumNumTillN();

    // cout<<"Sum of Even Number till n is"<<sumOfEvenNumTillN();

    // printAreaOfCircle();

    // printFactorialOfNumber();

    // printPrimeFrom1ToN();

    // printDigitsOfInteger();

    // createNumberUsingDigits();

    // printBinaryRepresentationOfDecimal();

    printDecimalRepresentationOfBinary();

    // countSetBits();

    return 0;
}

int maxThreeNumbers(int num1, int num2, int num3)
{
    if (num1 >= num2 && num1 >= num3)
    {
        return num1;
    }
    else if (num2 >= num3)
    {
        return num2;
    }
    else
    {
        return num3;
    }
}

void printCount1ToN()
{
    int n;
    cout << "Enter N:";
    cin >> n;
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
}
int checkPrimeNumOrNot()
{
    int num;
    cout << "Enter a number :\n";
    cin >> num;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false; // not a prime
        }
    }
    return true; // prime no
}

void checkEvenOrOdd(int num)
{
    // approach 1 using modulus
    // if(num%2){
    //     cout<<"Odd Number";
    // }else{
    //     cout<<"Even Number";
    // }

    // approach 2 using bitwise
    // if(num&1){
    //     cout<<"Odd Number";
    // }else{
    //     cout<<"Even Number";
    // }

    // approach 3 w/o using bitwise and modulus
    if (!(num == num / 2 * 2))
    {
        cout << "Odd Number";
    }
    else
    {
        cout << "Even Number";
    }
}

void sumNumTillN()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "sum of numbers from 1 to " << n << " is " << sum;
}

int sumOfEvenNumTillN()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!(i & 1))
            sum += i;
    }
    return sum;
}

void printAreaOfCircle()
{
    const float PI = 22 / 7;
    double r;
    cout << "enter radius of a circle:";
    cin >> r;
    cout << "\n";
    cout << "Area of circle is :" << PI * pow(r, 2);
}

void printFactorialOfNumber()
{
    int n;
    cin >> n;
    int factorial = 1;
    while (n > 1)
    {
        factorial *= n--;
    }
    cout << "Factorial : " << factorial;
}

void printPrimeFrom1ToN()
{
    int n;
    cin >> n;
    for (int num = 2; num <= n; num++)
    {
        int i = 2;
        for (; i < num; i++)
        {
            if (num % i == 0)
            {
                break;
            }
        }
        if (i == num)
        {
            // prime number
            cout << num << " ";
        }
    }
}

void printDigitsOfInteger()
{
    int num;
    cin >> num;

    int number = num;
    int reverseNum = 0;
    while (number)
    {
        int lastDigit = number % 10;
        reverseNum = reverseNum * 10 + lastDigit;
        number /= 10;
    }
    cout << "Reverse Number: " << reverseNum << endl;
    cout << "Printing Digits " << endl;
    while (reverseNum)
    {
        int lastDigit = reverseNum % 10;
        cout << lastDigit << " " << endl;
        reverseNum /= 10;
    }
}

void createNumberUsingDigits()
{
    // i/p -> 3 (1,8,9)
    // o/p -> 189
    int numDigits;
    cout << "Enter number of digits:";
    cin >> numDigits;
    int input;
    int ans = 0;
    for (int i = 0; i < numDigits; i++)
    {
        cout << "Enter Digit " << i + 1 << ": ";
        cin >> input;
        ans = ans * 10 + input;
    }
    cout << "Number: " << ans;
}

void printBinaryRepresentationOfDecimal()
{
    // i/p -> 13
    // o/p -> 1101
    int num;
    cin >> num;
    int ans = 0;
    int unit = 0;
    // approach 1 using divide
    // while(num){
    //     int quotient = num%2;
    //     ans = ans + quotient*pow(10,unit++);
    //     cout<<ans<<endl;
    //     num/=2;
    // }

    // appraoch 2 using bitwise rightshift
    // what we are doing above fetching quotient & reducing number by dividing with 2
    // 13->6->3->1->0
    // rightmost bit 1,0,1,1,0 (num&1) ->rightmost bit
    while (num)
    {
        int rightMostBit = num & 1;
        ans = ans + rightMostBit * pow(10, unit++);
        cout << ans << endl;
        num >>= 1; // rightshift by 1 bit on each iteration num=num/2
    }
    cout << "Binary Representation: " << ans;
}

void printDecimalRepresentationOfBinary()
{
    // i/p  -> 111(storing as integer not binary)
    // o/p -> 7

    int n;
    cin >> n;
    int ans = 0;
    int unit = 0;
    // approach 1 using modulus
    // while(n){
    //     int lastDigit=n%10;
    //     ans = ans + lastDigit*pow(2,unit++);
    //     n/=10;
    // }

    // approach 2 using bitwise
    while (n)
    {
        int lastDigit = n % 10;
        ans = ans + (lastDigit << unit++);
        n /= 10;
    }
    cout << "Binary Representtaion :" << ans;
}

void countSetBits()
{
    // i/p 5
    // o/p 2 (101) 2 1's in 5 binary representaion
    int num;
    cin >> num;
    int count = 0;
    while (num)
    {
        num = num & (num - 1);
        count++;
    }
    cout << "Count " << count;
}

// leetcode
vector<double> convertTemperature(double celsius)
{
    double kelvin = celsius + 273.15;
    double fahrenheit = celsius * 1.80 + 32.00;

    vector<double> ans;
    ans.push_back(kelvin);
    ans.push_back(fahrenheit);
    return ans;
}
// gfg
//  Input: n = 10, k = 2
//  Output: 14
int setKthBit(int n, int k)
{
    // Code here
    return n | (1 << k);
}

// leetcode
int reverse(int x)

{
    bool isNegative = false;
    int ans = 0;
    if (x <= INT_MIN)
    {
        return 0;
    }
    if (x < 0)
    {
        isNegative = true;
        x = -x;
    }

    while (x)
    {
        if (ans > INT_MAX / 10)
            return 0;
        int lastDigit = x % 10;
        ans = ans * 10 + lastDigit;
        x /= 10;
    }

    return isNegative ? -ans : ans;
}

int bitwiseComplement(int n)
{

    int m = n;
    int mask = 0;

    // edge case
    if (n == 0)
        return 1;

    while (m)
    {
        mask = (mask << 1) | 1;
        m >>= 1;
    }

    int ans = ~n & mask;
    return ans;
}

bool isPowerOfTwo(int n)
{

    // Approach 1
    // if(n <= 0){
    //     return false;
    // }
    // while(n>1){
    //     if(n%2) return false; //if number is 1 but remainder but is
    //     giving 1 so not a power of 2 n>>=1;
    // }
    // return true;

    // Approach 2
    // for(int i=0;i<=30;i++){ // max store 2^30 bcoz its max values 2^31-1
    // so not 31
    //     int ans = pow(2,i);
    //     if(n==ans) return true;
    // }
    // return false;

    // approach 3 using previous ans instead of using pow every time
    int ans = 1;
    for (int i = 0; i <= 30; i++)
    {
        if (n == ans)
            return true;
        if (ans < INT_MAX / 2)
            ans = ans * 2;
    }
    return false;
}

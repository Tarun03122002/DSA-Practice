#include <iostream>

using namespace std;

void print4R4CSquare();
void print3R5CRectangle();
void print5R5CHollowRectangle();
void printHalfPyramid();
void printInvertedHalfPyramid();
void printNumericHalfPyramid();
void printNumericInvertedHalfPyramid();
void printHollowSquare();
void printHollowInvertedHalfPyramid();
void printFullPyramid();
void printInvertedFullPyramid();
void printSolidDiamond();
void printHollowFullPyramid();
void printHollowFullPyramidPrintingsingleCharactersAfterSpace();
void printHollowFullDiamond();
void printStarsOutsideHollowDiamond();
void fancyPatternHalfPyramid();
void printHollowInveertedHalfPyramid();
void printFancyPattern();                     // refer problem 18 notes for pattern design
void printFancyPattern19QNotes();             // refer problem 19 notes for pattern design
void printNumericHollowInvertedHalfPyramid(); // refer problem 20
void numericPalindromeEquilateralPyramid();   // refer problem 21
void printFancyPatternQ22();                  // refer problem 22
void printSolidHalfDiamond();
void floydTriangleQ24();
void butterflyPaternQ25();
void fullPyramid26();
void fancyPattern27();
void fancyPatternQ28();
void pascalTraingleQ29();
int main()
{
    // print4R4CSquare();
    // print3R5CRectangle();
    // print5R5CHollowRectangle();
    // printHalfPyramid();
    // printInvertedHalfPyramid();
    // printNumericHalfPyramid();
    // printNumericInvertedHalfPyramid();
    // printHollowSquare();
    // printHollowInvertedHalfPyramid();
    // printFullPyramid();
    // printInvertedFullPyramid();
    // printSolidDiamond();
    // printHollowFullPyramid();
    // printHollowFullPyramidPrintingsingleCharactersAfterSpace();
    // printHollowFullDiamond();
    // printStarsOutsideHollowDiamond();
    // fancyPatternHalfPyramid();
    // printHollowInveertedHalfPyramid();
    // printFancyPattern();
    // printFancyPattern19QNotes();
    // printNumericHollowInvertedHalfPyramid();
    // numericPalindromeEquilateralPyramid();
    // printFancyPatternQ22();
    // printSolidHalfDiamond();
    // floydTriangleQ24();
    // butterflyPaternQ25();
    // fullPyramid26();
    // fancyPattern27();
    fancyPatternQ28();
    // pascalTraingleQ29();
}

void print4R4CSquare()
{
    int totalRows = 4;
    int totalCols = 4;
    for (int row = 0; row < totalRows; row++)
    {
        for (int col = 0; col < totalCols; col++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print3R5CRectangle()
{
    int totalRows = 3;
    int totalCols = 5;
    for (int row = 0; row < totalRows; row++)
    {
        for (int col = 0; col < totalCols; col++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print5R5CHollowRectangle()
{
    int totalRows = 5;
    int totalCols = 5;
    for (int row = 0; row < totalRows; row++)
    {
        for (int col = 0; col < totalCols; col++)
        {
            if (row == 0 || row == totalRows - 1 || col == 0 || col == totalCols - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void printHalfPyramid()
{
    int totalRows;
    cout << "Enter total no of rows:\n";
    cin >> totalRows;
    for (int row = 0; row < totalRows; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

void printInvertedHalfPyramid()
{
    int totalRows;
    cout << "Enter total no of rows:\n";
    cin >> totalRows;
    for (int row = 0; row < totalRows; row++)
    {
        for (int col = 0; col < totalRows - row; col++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

void printNumericHalfPyramid()
{
    int totalRows;
    cout << "Enter total no of rows:\n";
    cin >> totalRows;
    for (int row = 0; row < totalRows; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << col + 1;
        }
        cout << endl;
    }
}

void printNumericInvertedHalfPyramid()
{
    int totalRows;
    cout << "Enter total no of rows:\n";
    cin >> totalRows;
    cout << "\n";
    for (int row = 0; row < totalRows; row++)
    {
        for (int col = 0; col < totalRows - row; col++)
        {
            cout << col + 1;
        }
        cout << endl;
    }
}

void printHollowSquare()
{
    int totalRows;
    cout << "Enter total no of rows:\n";
    cin >> totalRows;
    for (int row = 0; row < totalRows; row++)
    {
        for (int col = 0; col < totalRows; col++)
        {
            if (row == 0 || row == totalRows - 1 || col == 0 || col == totalRows - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void printHollowInvertedHalfPyramid()
{
    int totalRows;
    cout << "Enter total no of rows:\n";
    cin >> totalRows;
    for (int row = 0; row < totalRows; row++)
    {
        for (int col = 0; col < totalRows - row; col++)
        {
            if (row == 0 || row == totalRows - 1 || col == 0 || col == totalRows - row - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

void printFullPyramid()
{
    int totalRows;
    cout << "Enter total no of rows:\n";
    cin >> totalRows;
    for (int row = 0; row < totalRows; row++)
    {
        // printing space
        for (int col = 0; col < totalRows - row - 1; col++)
        {
            cout << " ";
        }
        // printing *
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }
        cout << '\n';
    }
}

void printInvertedFullPyramid()
{
    int totalRows;
    cout << "Enter total no of rows:\n";
    cin >> totalRows;
    for (int row = 0; row < totalRows; row++)
    {
        // printing space
        for (int col = 0; col < row; col++)
        {
            cout << " ";
        }
        // printing *
        for (int col = 0; col < totalRows - row; col++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}

void printSolidDiamond()
{
    int totalRows;
    cout << "Enter total no of rows:\n";
    cin >> totalRows;

    // printing full pyramid
    for (int row = 0; row < totalRows; row++)
    {

        // printing space
        for (int col = 0; col < totalRows - row - 1; col++)
        {
            cout << " ";
        }
        // printing *
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }
        cout << "\n";
    }

    // printing inverted half pyramid
    for (int row = 0; row < totalRows; row++)
    {

        // printing space
        for (int col = 0; col < row; col++)
        {
            cout << " ";
        }
        // printing *
        for (int col = 0; col < totalRows - row; col++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}

void printHollowFullPyramid()
{
    int n;
    cout << "Enter no of rows:\n";
    cin >> n;
    cout << endl;
    for (int row = 0; row < n; row++)
    {
        // printing space
        for (int col = 0; col < n - row - 1; col++)
        {
            cout << " ";
        }
        // approaching with printing two characters
        // print * at first and last column
        for (int col = 0; col < row + 1; col++)
        {
            if (col == 0 || col == row + 1 - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void printHollowFullPyramidPrintingsingleCharactersAfterSpace()
{
    int n;
    cout << "Enter number of rows" << endl;
    cin >> n;
    cout << "\n";
    for (int row = 0; row < n; row++)
    {
        // printing space
        for (int col = 0; col < n - row - 1; col++)
        {
            cout << " ";
        }
        // approaching with printing one character
        // print * at first and last column
        for (int column = 0; column < 2 * row + 1; column++)
        {
            if (column == 0 || column == 2 * row)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void printHollowFullDiamond()
{
    int n;
    cout << "Enter number of rows" << endl;
    cin >> n;
    cout << "\n";
    // printing Hollow Full pyramid
    for (int row = 0; row < n; row++)
    {
        //  printing space
        for (int col = 0; col < n - row - 1; col++)
        {
            cout << " ";
        }
        // print two characters
        for (int col = 0; col < row + 1; col++)
        {
            if (col == 0 || col == row)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    // printing hollow inverted full pyramid
    for (int row = 0; row < n; row++)
    {
        // printing space
        for (int col = 0; col < row; col++)
        {
            cout << " ";
        }
        // print two chars
        for (int col = 0; col < n - row; col++)
        {
            if (col == 0 || col == n - row - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void printStarsOutsideHollowDiamond()
{

    // diamon input always even -> total rows
    int n;
    cout << "Enter even no of rows for hollow diamond";
    cin >> n;
    while (n & 1)
    {
        cout << "Only even no allowed";
        cin >> n;
    }
    int nRows = n / 2;
    // stars oustide hollow full pyramid
    for (int row = 0; row < nRows; row++)
    {
        // printing stars
        for (int col = 0; col < nRows - row; col++)
        {
            cout << "*";
        }
        // printing space
        for (int col = 0; col < 2 * row + 1; col++)
        {
            cout << " ";
        }
        // printing stars
        for (int col = 0; col < nRows - row; col++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // stars oustide hollow inverted full pyramid
    for (int row = 0; row < nRows; row++)
    {
        // printing stars
        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }

        // print space
        for (int col = 0; col < 2 * nRows - 1 - 2 * row; col++)
        {
            cout << " ";
        }

        // printing stars
        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// for design refer problem 16 notes
void fancyPatternHalfPyramid()
{
    int n;
    cout << "Enter total no of row:\n";
    cin >> n;
    cout << "\n";
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < 2 * row + 1; col++)
        {
            // odd column print *
            if (col & 1)
            {
                cout << "*";
            }
            else
            {
                cout << row + 1;
            }
        }
        cout << endl;
    }
}

void printHollowInveertedHalfPyramid()
{
    int n;
    cout << "Enter total no of rows:";
    cin >> n;
    cout << endl;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n - row; col++)
        {
            if (row == 0 || row == n - 1 || col == 0 || col == n - row - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

void printFancyPattern()
{
    int n;
    cout << "Enter total no of rows:\n";
    cin >> n;
    cout << endl;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            if (row == 0 || row == n - 1 || col == 0)
            {
                cout << col + 1;
            }
            else if (col == row + 1 - 1)
            {
                cout << " " << col + 1;
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

void printFancyPattern19QNotes()
{
    int n;
    cout << "Enter total no of rows:";
    cin >> n;
    for (int row = 0; row < n; row++)
    {
        int character = 1 + 'A' - 1;

        for (int col = 0; col < row + 1; col++, character++)
        {
            cout << (char)character;
        }
        character--;
        while (character > 'A')
        {
            character--;

            cout << (char)character;
        }
        cout << "\n";
    }
}

void printNumericHollowInvertedHalfPyramid()
{
    int n;
    cout << "Enter total no of rows:\n";
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        int character = row + 1;
        for (int col = 0; col < n - row; col++, character++)
        {
            if (row == 0 || row == n - 1 || col == 0 || col == n - row - 1)
            {
                cout << character;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void numericPalindromeEquilateralPyramid()
{
    int n;
    cout << "Enter total no of rows:";
    cin >> n;
    for (int row = 0; row < n; row++)
    {
        // print space(inverted half pyramid)
        for (int col = 0; col < n - row - 1; col++)
        {
            cout << " ";
        }
        // print half pyramid(left)
        int character = 1;
        for (int col = 0; col < row + 1; col++, character++)
        {
            cout << character;
        }
        // print half pyramid(right)
        character--;
        while (character > 1)
        {
            character--;
            cout << character;
        }
        cout << "\n";
    }
}

void printFancyPatternQ22()
{
    int n;
    cout << "Enter total no of rows:";
    cin >> n;
    for (int row = 0; row < n; row++)
    {
        // printing *
        for (int col = 0; col < 2 * n - 2 - row; col++)
        {
            cout << "*";
        }

        // printing triangle
        for (int col = 0; col < 2 * row + 1; col++)
        {
            // odd column (*)
            if (col & 1)
            {
                cout << "*";
            }
            else
            {
                cout << row + 1;
            }
        }
        // printing *
        for (int col = 0; col < 2 * n - 2 - row; col++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void printSolidHalfDiamond()
{
    int n;
    cout << "Enter total no of rows";
    cin >> n;
    int nRows = n / 2;
    int nRowInHalfPyramid, nRowInInvertedHalfPyramid;

    if (nRows & 1)
    {
        nRowInHalfPyramid = nRows + 1;
    }
    else
    {
        nRowInHalfPyramid = nRows;
    }
    // printing half pyramid
    for (int row = 0; row < nRowInHalfPyramid; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }
        cout << '\n';
    }

    // printing inverted half pyramid

    nRowInInvertedHalfPyramid = nRows;
    for (int row = 0; row < nRowInInvertedHalfPyramid; row++)
    {
        for (int col = 0; col < nRowInInvertedHalfPyramid - row; col++)
        {
            cout << "*";
        }
        cout << '\n';
    }
}

void floydTriangleQ24()
{
    int n;
    cout << "Enter total no of rows:";
    cin >> n;
    // n-1*n
    int character = 1;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row + 1; col++, character++)
        {
            cout << character;
            if (character >= 1 && character <= 9)
            {
                cout << "  ";
            }
            else if (character >= 10 && character <= 99)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void butterflyPaternQ25()
{
    // only for even
    int n;
    cout << "Enter no of rows";
    cin >> n;
    int nRowsUpper = n / 2;
    int nRowsLower = n / 2;
    for (int row = 0; row < nRowsUpper; row++)
    {
        // printing stars
        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }
        // printing space
        for (int col = 0; col < nRowsUpper + 2 - 2 * row; col++)
        {
            cout << " ";
        }
        // print stars
        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int row = 0; row < nRowsLower; row++)
    {
        // printing stars(Inverted Half Pyramid)
        for (int col = 0; col < nRowsLower - row; col++)
        {
            cout << "*";
        }
        // printing trinagle space
        for (int col = 0; col < 2 * row; col++)
        {
            cout << " ";
        }
        // printing inverted half pyramid
        for (int col = 0; col < nRowsLower - row; col++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void fullPyramid26()
{
    int n;
    cout << "Enter total no of rows:";
    cin >> n;
    for (int row = 0; row < n; row++)
    {
        // printing space(inverted hp)
        for (int col = 0; col < n - row - 1; col++)
        {
            cout << " ";
        }
        // printing triangle 2 chars at a time
        int character = 1;
        for (int col = 0; col < row + 1; col++, character++)
        {
            if (col == 0 || col == row || row == n - 1)
                cout << character << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void fancyPattern27()
{
    int n;
    cin >> n;
    int nRowsUpper, nRowsLower;
    if (n & 1)
    {
        nRowsUpper = n / 2 + 1;
    }
    else
    {
        nRowsUpper = n / 2;
    }
    int character = 1;
    int row0 = 0;
    // fancy pattern
    for (; row0 < nRowsUpper; row0++)
    {
        for (int col = 0; col < 2 * row0 + 1; col++)
        {

            // odd colums print *
            if (col & 1)
            {
                cout << "*";
            }
            else
            {
                cout << character;
                character++;
            }
        }
        cout << endl;
    }

    // fancy pattern inverted
    nRowsLower = n / 2;
    int startCharacter = character - nRowsLower;
    for (int row = 0; row < nRowsLower; row++)
    {
        character = startCharacter;
        for (int col = 0; col < 2 * nRowsLower - 2 * row - 1; col++)
        {
            if (col & 1)
            {
                cout << '*';
            }
            else
            {
                cout << character;
                character++;
            }
        }
        cout << endl;
        startCharacter = startCharacter - (nRowsLower - row - 1);
    }
    //    78910
    //    456
    //    23
    //    1
}

void fancyPatternQ28()
{
    //My approach
    // int n;
    // cout << "Enter number of rows";
    // cin >> n;
    // int nRowsHalfPyramid, nRowsInvertedHalfPyramid;
    // if (n & 1)
    // {
    //     nRowsHalfPyramid = (n / 2) + 1;
    // }
    // else
    // {
    //     nRowsHalfPyramid = n / 2;
    // }
    //  Half pyramid
    // for (int row = 0; row < nRowsHalfPyramid; row++)
    // {
    //     int character = 1;
    //     for (int col = 0; col < row + 1; col++)
    //     {
    //         // printing stars
    //         if (col == 0)
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             cout << character;
    //             character++;
    //         }
    //     }
    //     character--;
    //     for (int col = character; col > 1; col--)
    //     {
    //         character--;
    //         cout << character;
    //     }
    //     // last column * print
    //     if (character == 1)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // nRowsInvertedHalfPyramid = n / 2;
    //  inverted half pyramid
    // for (int row = 0; row < nRowsInvertedHalfPyramid; row++)
    // {
    //     int character = 1;
    //     for (int col = 0; col < nRowsInvertedHalfPyramid - row; col++)
    //     {
    //         if (col == 0)
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             cout << character++;
    //         }
    //     }
    //     character--;
    //     while (character > 1)
    //     {
    //         character--;
    //         cout << character;
    //     }
    //     // last charcter already print ,we have to * at last column
    //     if (character == 1)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }


    // other approach(Lakshay bhai) instead of divinding in half and inverted we fix in one go
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        // row less than = n/2 growing phase
        // greater than n/2 shrinking phase
        int cond = row<=n/2 ? 2*row: 2*(n-1-row);
        int character =1 ;
        for(int col=0;col<=cond;col++){
            if(col==0){
                cout<<"*";
            }
            if(col<=cond/2){
                cout<<character++;
            }else{
                cout<<cond-col+1;
            }
            if(col==cond){
                cout<<"*";
            }
        }
        cout<<endl;
    }
}

void pascalTraingleQ29()
{
    int n;
    cout << "Enter total no of rows:\n";
    cin >> n;
    cout << "\n";
    for (int row = 1; row <= n; row++)
    {
        int C=1;
        for (int col = 1; col <= row ; col++)
        {
           cout<<C<<"  ";
           C=C*(row-col)/col;
        }
        cout << endl;
    }
}
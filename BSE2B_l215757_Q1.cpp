#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
void fileoutput(char**, int);
bool fileinput(char**& , int*& , int&, int& );
void fill(char**, int);
bool updowncheck(char**, char*, int, int);
bool downupcheck(char**, char*, int, int);
bool rightleftcheck(char**, char*, int, int);
bool leftrightcheck(char**, char*, int, int);
bool BottomleftTRightcheck(char**, char*, int, int);
bool TRightBottomleftcheck(char**, char*, int, int);
bool BRightTLeftcheck(char**, char*, int, int);
bool TLeftBRightcheck(char**, char*, int, int);
void updownenter(int , int , int , char*, char**);
void TLeft_BRightenter(int, int, int, char*, char**);
void BRight_TLeftenter(int, int, int, char*, char**);
void BottomLeft_TopRightenter(int, int, int , char*, char**);
void TRight_BottomLeftenter(int, int, int , char*, char**);
void rightleftenter(int, int, int, char*, char**);
void leftrightenter(int, int, int, char*, char**);
void downupenter(int, int, int , char*, char**);
int index(int* size, int count)
{
    int max = 0, i = 0, index = -1;
    while (i < count)
    {
        if (size[i] > max && size[i] != -1)
        {
            max = size[i];           //picks largest words from the list and sends them to main when called
            index = i;
        }
        i++;
    }
    return index;
}
void fill(char** grid, int max)
{
    srand(time(0));
    char random = 'A';
    int ran = 0;                    //fills the empty spaces in the grid by random letters
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            ran = rand() % 26;
            if (grid[i][j] == ' ')
                grid[i][j] = random + ran;
        }
    }
}
bool orientation(char** grid, char* arr, int index, int* sizes, int max)
{
    bool done = false;
    srand(time(0));
    static int pick=0;

    while (!done)             //recieves a word and size and randomly selects how to put that word in the grid
    { 
        switch (pick)
        {                     //incase the word doesnot fit anywhere in the selected orientation, then it randomly picks another orientation
           case 3:done = updowncheck(grid, arr, sizes[index], max);
                   break;
           case 2:done = downupcheck(grid, arr, sizes[index], max);  
                   break;
           case 4:done = leftrightcheck(grid, arr, sizes[index], max);
                   break;
           case 6:done = rightleftcheck(grid, arr, sizes[index], max);
                    break;
           case 1:done = TLeftBRightcheck(grid, arr, sizes[index], max);
                    break;
           case 7:done = BRightTLeftcheck(grid, arr, sizes[index], max);
                    break;
           case 8:done = TRightBottomleftcheck(grid, arr, sizes[index], max);
                    break;
           case 0:done = BottomleftTRightcheck(grid, arr, sizes[index], max);
                    break;
           case 5:done = downupcheck(grid, arr, sizes[index], max);
               break;
           case 9:done = rightleftcheck(grid, arr, sizes[index], max);
               break;

           default:pick=rand()%10;
               break;
        }
        pick++;
    }
            return done;
}
void fileoutput(char** grid, int max)
{
    ofstream fout;
    fout.open("wordsearchpuzzle.txt");
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            fout << grid[i][j] << " ";
        }
        fout << endl;
    }                   //prints grid in text file
    fout.close();
}
void BottomLeft_TopRightenter(int row, int col, int size, char* arr, char** grid)
{
    for (int i = 0; i < size; i++)
    {
        grid[row][col] = arr[i];
        col++;
        row--;
    }                   //enters word in grid 
}

void TRight_BottomLeftenter(int row, int col, int size, char* arr, char** grid)
{
    for (int i = 0; i < size; i++)
    {
        grid[row][col] = arr[i];
        col--;
        row++;
    }
}

void BRight_TLeftenter(int row, int col, int size, char* arr, char** grid)
{
    for (int i = 0; i < size; i++)
    {
        grid[row][col] = arr[i];
        col--;
        row--;
    }
}

void TLeft_BRightenter(int row, int col, int size, char* arr, char** grid)
{
    for (int i = 0; i < size; i++)
    {
        grid[row][col] = arr[i];
        col++;
        row++;
    }
}
void rightleftenter(int row, int col, int size, char* arr, char** grid)
{
    for (int i = 0; i < size; i++)
    {
        grid[row][col] = arr[i];
        col--;
    }
}

void leftrightenter(int row, int col, int size, char* arr, char** grid)
{
    for (int i = 0; i < size; i++)
    {
        grid[row][col] = arr[i];
        col++;
    }
}

void downupenter(int row, int col, int size, char* arr, char** grid)
{
    for (int i = 0; i < size; i++)
    {
        grid[row][col] = arr[i];
        row--;
    }
}

void updownenter(int row, int col, int size, char* arr, char** grid)
{
    for (int i = 0; i < size; i++)
    {
        grid[row][col] = arr[i];
        row++;
    }
}

bool BottomleftTRightcheck(char** grid, char* arr, int size, int max)
{
    bool found = false;
    for (int i = max - 1; i >= 0; i--)
    {
        int m = 0;     //checks if received word fits anywhere in a bottomleft to top right diagonal
        for (int j = 0; j<max;j++)
        {
            int ind = i, ind2 = j;
            while (m < size && ind >= 0 && ind2 < max &&(grid[ind][ind2] == ' ' || grid[ind][ind2] == arr[m]))
            {
                if (m == size - 1)
                    found = true;
                ind2++;
                ind--;
                m++;
            }
            if (found)
            {
                BottomLeft_TopRightenter(i, j, size, arr, grid);  //enters the word where it finds space
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}

bool TRightBottomleftcheck(char** grid, char* arr, int size, int max)
{
    bool found = false;      //checks if received word fits anywhere in a top right to bottomleft diagonal
    for (int i = 0; i<max; i++)
    {
        int m = 0;
        for (int j = max - 1; j >= 0; j--)
        {
            int ind = i, ind2 = j;
            while (m < size && ind2 >= 0 && ind < max && (grid[ind][ind2] == ' ' || grid[ind][ind2] == arr[m]))
            {
                if (m == size - 1)
                    found = true;
                ind2--;
                ind++;
                m++;
            }
            if (found)
            {
                TRight_BottomLeftenter(i, j, size, arr, grid);  //if it does, then it enters the word
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}

bool BRightTLeftcheck(char** grid, char* arr, int size, int max)
{
    bool found = false;
    for (int i = max-1;i>=0;i--)   //checks if received word fits anywhere in a bottom right to top left diagonal 
    {
        int m = 0;
        for (int j = max-1;j>=0;j--)
        {
            int ind = i, ind2 = j;
            while (m < size && ind2 >= 0 && ind >= 0 && (grid[ind][ind2] == ' ' || grid[ind][ind2] == arr[m]) )
            {
                if (m == size - 1)
                    found = true;
                ind2--;
                ind--;
                m++;
            }
            if (found)
            {
                BRight_TLeftenter(i, j, size, arr, grid); //enters the word into grid when finds space
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}

bool TLeftBRightcheck(char** grid, char* arr, int size, int max)
{                 //checks if received word fits anywhere in a top left to bottom right diagonal
    bool found = false;
    for (int i = 0; i < max; i++)
    {
        int m = 0;
        for (int j =0;j<max;j++)
        {
            int ind = i, ind2 = j;
            while (m < size && ind2 < max && ind < max && (grid[ind][ind2] == ' ' || grid[ind][ind2] == arr[m]))
            {
                if (m == size - 1)
                    found = true;
                ind2++;
                ind++;
                m++;
            }
            if (found)
            {
                TLeft_BRightenter(i, j, size, arr, grid);  //enters the word where it finds space
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}

bool rightleftcheck(char** grid, char* arr, int size, int max)
{     //checks if received word fits anywhere from right to left
    bool found = false;
    for (int i = 0; i < max; i++)
    {
        int m = 0;
        for (int j =max-1; j >=0; j--)
        {
            int ind = i, ind2 = j;
            while (m < size && ind2 >= 0 && (grid[ind][ind2] == ' ' || grid[ind][ind2] == arr[m]))
            {
                if (m == size - 1)
                    found = true;
                ind2--;
                m++;
            }
            if (found)
            {
                rightleftenter(i, j, size, arr, grid); // enters word where it finds space
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}
bool leftrightcheck(char** grid, char* arr, int size, int max)
{          //checks if received word fits anywhere from left to right 
    bool found = false;
    for (int i = 0; i < max; i++)
    {
        int m = 0;
        for (int j=0;j<max;j++)
        {
            int ind = i, ind2 = j;
            while (m < size && ind2 < max && (grid[ind][ind2] == ' ' || grid[ind][ind2] == arr[m]) )
            {
                if (m == size - 1)
                    found = true;
                ind2++;
                m++;
            }
            if (found)
            {
                leftrightenter(i, j, size, arr, grid);  //enters the word where it finds space
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}

bool downupcheck(char** grid, char* arr, int size, int max)
{         //checks if received word fits anywhere from bottom to top
    bool found = false;
    for (int j = 0; j < max; j++)
    {
        int m = 0;
        for (int i = max-1; i>=0; i--)
        {
            int ind = i, ind2 = j;
            while ( m < size && ind >= 0 && (grid[ind][ind2] == ' ' || grid[ind][ind2] == arr[m]) )
            {
                if (m == size - 1)
                    found = true;
                ind--;
                m++;
            }
            if (found)
            {
                downupenter(i, j, size, arr, grid);
                return true;   //enters the word where it finds space

            }
            else
                m = 0;
        }
    }
    return false;
}
bool updowncheck(char** grid, char* arr, int size, int max)
{          //checks if received word fits anywhere from top to bottom
    bool found = false;
    for (int j=0; j<max; j++)
    {
        int m = 0;
        for (int i = 0; i < max; i++)
        {
            int ind = i, ind2 = j;
            while (m < size && ind < max && (grid[ind][ind2] == ' ' || grid[ind][ind2] == arr[m]) )
            {
                if (m == size - 1)
                    found = true;
                ind++;
                m++;
            }
            if (found)
            {
                updownenter(i, j, size, arr, grid);
                return true;    //enters the word where it finds space

            }
            else
                m = 0;
        }
    }
    return false;
}
bool fileinput(char**& array, int*& sizes, int& noofwords,int& max)
{       
    char* input = new char[30];
    int count = 0;
    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())   //opens input file
    {
        for (noofwords = 0; !fin.eof(); noofwords++)
        {
            count = 0;
            fin >> input;
            while (input[count] != 0)
                count++;
            if (max < count)    //counts the number of words
                max = count;
        }
        sizes = new int[noofwords];      // makes array to save words and sizes in corresponding indexes
        array = new char* [noofwords];
        for (int j = 0; j < noofwords; j++)
            array[j] = new char[max];
        fin.close();

    }
    else
    {
        cout << "Some error has occured.";
        return false;
    }
    fin.open("input.txt");
    if (fin.is_open())
    {

        for (int k = 0; !fin.eof(); k++)
        {
            fin >> input;
            int j = 0;
            for (j = 0; input[j] != 0; j++)
            {
                array[k][j] = input[j];
            }
            array[k][j] = 0;   //inputs words and their sizes
            sizes[k] = j;
        }

        return true;
    }
    else
        return false;

}
int main()
{
    char* input = new char[30];
    int noofwords = 0, max=0,count = 0;
    char** array = 0;
    int* sizes = 0;
    if (fileinput(array, sizes, noofwords, max))   //gets input and makes gird
    {
        char** grid = new char* [max];
        for (int i = 0; i < max; i++)
        {
            grid[i] = new char[max];
            for (int j = 0; j < max; j++)
                grid[i][j] = ' ';     //fills grid with space
        }
        int r = 0;
        while (r < noofwords)
        {
            int get = index(sizes, noofwords);    //goes through the sizes list and picks largest word

            if (orientation(grid, array[get], get, sizes, max)) //finds a place for picked word in the grid
            {
                r++;
                sizes[get] = -1;     //if it gets entered into grid then it's size is intitialized to -1 so it isn't picked again
            }
        }

        fill(grid, max); //after all words are entered into grid, the remaining indexes are filled with random letters
        fileoutput(grid, max);  //wordsearch grid written into textfile
    }
    else
        cout << "Some error has occured.";
    return 0;
}

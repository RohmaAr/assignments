#include<iostream>
#include<fstream>
using namespace std;
void fileinput(char**& grid, string*& array, int*& sizes, int& row, int& col, int& noofwords);

bool BottomleftTRightcheck(char** grid, string arr, int size, int index[], int row, int col)
{
    bool found = false;
    for (int i = row - 1; i >= 0; i--)
    {
        int m = 0; //sees if the word is present anywhere from bottomleft to top right
        for (int j = 0; j < col; j++)
        {
            int ind = i, ind2 = j;
            while (m < size && ind >= 0 && ind2 < col && grid[ind][ind2] == arr[m])
            {
                if (m == size - 1)
                {
                    index[2] = ind;
                    index[3] = ind2;  //enters the starting and ending indexes if word is found
                    found = true;
                }
                ind2++;    
                ind--;
                m++;
            }
            if (found)
            {
                index[0]=i;
                index[1] = j;
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}

bool TRightBottomleftcheck(char** grid, string arr, int size, int index[], int row, int col)
{
    bool found = false;      //checks if word is present anywhere in a top right to bottomleft diagonal
    for (int i = 0; i < row; i++)
    {
        int m = 0;
        for (int j = col - 1; j >= 0; j--)
        {
            int ind = i, ind2 = j;
            while (m < size && ind2 >= 0 && ind < row && grid[ind][ind2] == arr[m])
            {
                if (m == size - 1)
                {
                    index[2] = ind;
                    index[3] = ind2;  //enters indexes in array if found
                    found = true;
                }
                ind2--;
                ind++;
                m++;
            }
            if (found)
            {
                index[0]=i;
                index[1] = j;
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}

bool BRightTLeftcheck(char** grid, string arr, int size, int index[], int row, int col)
{
    bool found = false;
    for (int i = row - 1; i >= 0; i--)   //checks if received word is present anywhere in a bottom right to top left diagonal 
    {
        int m = 0;
        for (int j = col - 1; j >= 0; j--)
        {
            int ind = i, ind2 = j;
            while (m < size && ind2 >= 0 && ind >= 0 && grid[ind][ind2] == arr[m])
            {
                if (m == size - 1)
                {
                    index[2] = ind;
                    index[3] = ind2;  //enters indexes in array if found
                    found = true;
                }
                ind2--;
                ind--;
                m++;
            }
            if (found)
            {

                index[0] = i;
                index[1] = j;
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}

bool TLeftBRightcheck(char** grid, string arr, int size, int index[], int row, int col)
{                 //checks if received word is anywhere in a top left to bottom right diagonal
    bool found = false;
    for (int i = 0; i < row; i++)
    {
        int m = 0;
        for (int j = 0; j < col; j++)
        {
            int ind = i, ind2 = j;
            while (m < size && ind2 < col && ind < row && grid[ind][ind2] == arr[m])
            {
                if (m == size - 1) {
                    index[2] = ind;
                    index[3] = ind2;  //enters indexes in array if found
                    found = true;
                }
                ind2++;
                ind++;
                m++;
            }
            if (found)
            {

                index[0] = i;
                index[1] = j;
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}

bool rightleftcheck(char** grid, string arr, int size, int index[], int row, int col)
{     //checks if received word is anywhere from right to left
    bool found = false;
    for (int i = 0; i < row; i++)
    {
        int m = 0;
        for (int j = col - 1; j >= 0; j--)
        {
            int ind = i, ind2 = j;
            while (m < size && ind2 >= 0 && grid[ind][ind2] == arr[m])
            {
                if (m == size - 1)
                {
                    index[2] = ind;   //enters starting and ending indexes in array if found
                    index[3] = ind2;
                    found = true;
                }
                ind2--;      
                m++;
            }
            if (found)
            {

                index[0] = i;
                index[1] = j;
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}
bool leftrightcheck(char** grid, string arr, int size, int index[], int row, int col)
{          //checks if received word is found anywhere from left to right 
    bool found = false;
    for (int i = 0; i < row; i++)
    {
        int m = 0;
        for (int j = 0; j < col; j++)
        {
            int ind = i, ind2 = j;
            while (m < size && ind2 < col && grid[ind][ind2] == arr[m])
            {
                if (m == size - 1)
                {
                    index[2] = ind;
                    index[3] = ind2;  //enters the indexes into an array if found
                    found = true;
                }
                ind2++;
                m++;
            }
            if (found)
            {

                index[0]=i;
                index[1] = j;
                return true;

            }
            else
                m = 0;
        }
    }
    return false;
}

bool downupcheck(char** grid, string arr, int size, int index[], int row, int col)
{         //checks if received word is anywhere from bottom to top
    bool found = false;
    for (int j = 0; j < col; j++)
    {
        int m = 0;
        for (int i = row - 1; i >= 0; i--)
        {
            int ind = i, ind2 = j;
            while (m < size && ind >= 0 && grid[ind][ind2] == arr[m])
            {
                if (m == size - 1)
                {
                    index[2] = ind;
                    index[3] = ind2;  //enters ending indexes in array
                    found = true;
                }
                ind--;
                m++;
            }
            if (found)
            {

                index[0]=i;  //enters starting indexes in array
                index[1] = j;
                return true;   

            }
            else
                m = 0;
        }
    }
    return false;
}
bool updowncheck(char** grid, string arr, int size, int index[], int& row, int& col)
{          //checks if received word is present anywhere from top to bottom
    bool found = false;
    for (int j = 0; j < col; j++)
    {
        int m = 0;
        for (int i = 0; i < row; i++)
        {
            int ind = i, ind2 = j;
            while (m < size && ind < row && grid[ind][ind2] == arr[m])
            {
                if (m == size - 1)
                {
                    index[2] = ind;  //enters indexes in array if word is found
                    index[3] = ind2;
                    found = true;
                }
                ind++;
                m++;
            }
            if (found)
            {
                index[0]=i;
                index[1] = j;
                return true;    

            }
            else
                m = 0;
        }
    }
    return false;
}
void writetofile(int index[])
{
    ofstream fout;
    fout.open("foundindexes.txt",ios::app);
    if (index[0] != -1)
    {
        fout << "{" << index[0] << "," << index[1] << "}{" << index[2] << "," << index[3] << "}" << endl;
    }
    else
        fout<<"Not found"<<endl;
    fout.close();
}
int main()
{
	int row, col, noofwords;
	char** grid = nullptr;
	string* array = nullptr;
	int* sizes = nullptr;
	fileinput(grid, array,sizes,row,col,noofwords);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < noofwords; i++)
		cout << array[i] << " " << sizes[i] << endl;
    for (int i = 0; i < noofwords; i++)
    {
        int index[4] = { -1 ,-1,-1,-1};
         TRightBottomleftcheck(grid, array[i], sizes[i], index, row, col);
         BRightTLeftcheck(grid, array[i], sizes[i], index, row, col);
         leftrightcheck(grid,array[i],  sizes[i],  index,  row, col);
         rightleftcheck( grid, array[i], sizes[i], index, row, col);
         updowncheck(grid, array[i], sizes[i], index,  row, col);     //calling each search function 
         downupcheck( grid, array[i], sizes[i], index, row, col);
         TLeftBRightcheck( grid, array[i], sizes[i], index, row, col);
         BottomleftTRightcheck( grid, array[i],sizes[i], index, row, col);
         writetofile(index);   //writing found indexes into file
    }
    return 0;
}
void fileinput(char**& grid, string*& array, int*& sizes, int& row, int& col, int& noofwords)
{
	fstream fin;
	fin.open("wordsearch.txt");
	if (fin.is_open())
	{
		fin >> row >> col >> noofwords;
		array = new string[noofwords];
		sizes = new int[noofwords];
		grid = new char* [row];
		for (int i = 0; i < noofwords; i++)
		{
			fin >> array[i];
			int j = 0;
			while (array[i][j] != 0)
				j++;
			sizes[i] = j;
		}
		for (int i = 0; i < row; i++)
		{
			grid[i] = new char[col];
			for (int j = 0; j < col; j++)
				fin >> grid[i][j];
		}

	}
}

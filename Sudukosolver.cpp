#include<iostream>
using namespace std;
int sudoku[9][9];
bool zero(int arr[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr[i][j]==0)
            {
                return true;
            }
        }
    }
    return false;
}
void display(int arr[9][9])
{
    cout<<arr[0][0]<<" "<<arr[0][1]<<" "<<arr[0][2]<<"  "<<arr[0][3]<<" "<<arr[0][4]<<" "<<arr[0][5]<<"  "<<arr[0][6]<<" "<<arr[0][7]<<" "<<arr[0][8]<<endl;
    cout<<arr[1][0]<<" "<<arr[1][1]<<" "<<arr[1][2]<<"  "<<arr[1][3]<<" "<<arr[1][4]<<" "<<arr[1][5]<<"  "<<arr[1][6]<<" "<<arr[1][7]<<" "<<arr[1][8]<<endl;
    cout<<arr[2][0]<<" "<<arr[2][1]<<" "<<arr[2][2]<<"  "<<arr[2][3]<<" "<<arr[2][4]<<" "<<arr[2][5]<<"  "<<arr[2][6]<<" "<<arr[2][7]<<" "<<arr[2][8]<<endl<<endl;
    cout<<arr[3][0]<<" "<<arr[3][1]<<" "<<arr[3][2]<<"  "<<arr[3][3]<<" "<<arr[3][4]<<" "<<arr[3][5]<<"  "<<arr[3][6]<<" "<<arr[3][7]<<" "<<arr[3][8]<<endl;
    cout<<arr[4][0]<<" "<<arr[4][1]<<" "<<arr[4][2]<<"  "<<arr[4][3]<<" "<<arr[4][4]<<" "<<arr[4][5]<<"  "<<arr[4][6]<<" "<<arr[4][7]<<" "<<arr[4][8]<<endl;
    cout<<arr[5][0]<<" "<<arr[5][1]<<" "<<arr[5][2]<<"  "<<arr[5][3]<<" "<<arr[5][4]<<" "<<arr[5][5]<<"  "<<arr[5][6]<<" "<<arr[5][7]<<" "<<arr[5][8]<<endl<<endl;
    cout<<arr[6][0]<<" "<<arr[6][1]<<" "<<arr[6][2]<<"  "<<arr[6][3]<<" "<<arr[6][4]<<" "<<arr[6][5]<<"  "<<arr[6][6]<<" "<<arr[6][7]<<" "<<arr[6][8]<<endl;
    cout<<arr[7][0]<<" "<<arr[7][1]<<" "<<arr[7][2]<<"  "<<arr[7][3]<<" "<<arr[7][4]<<" "<<arr[7][5]<<"  "<<arr[7][6]<<" "<<arr[7][7]<<" "<<arr[7][8]<<endl;
    cout<<arr[8][0]<<" "<<arr[8][1]<<" "<<arr[8][2]<<"  "<<arr[8][3]<<" "<<arr[8][4]<<" "<<arr[8][5]<<"  "<<arr[8][6]<<" "<<arr[8][7]<<" "<<arr[8][8]<<endl<<endl;
}
bool inbox(int row,int coloumn,int value)
{
    int r,c,v;
    r=row/3;
    r=r*3;
    c=coloumn/3;
    c=c*3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(sudoku[r+i][c+j]==value)
            {
                return true;
            }
            else{continue;}
        }
    }
    return false;
}
bool inrow(int row,int value)
{
    for(int i=0;i<9;i++)
    {
        if(sudoku[row][i]==value)
        {
            return true;
        }
        else{
            continue;
        }
    }
    return false;
}
bool incoloumn(int coloumn,int value)
{
    for(int i=0;i<9;i++)
    {
        if (sudoku[i][coloumn]==value)
        {return true;}
        else{
            continue;
        }
    }
    return false;
}
void basicfilling(int arr[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(sudoku[i][j]==0)
            {
                int count=0,value;
                for(int k=1;k<10;k++)
                {
                    if(!inrow(i,k) && !incoloumn(j,k) && !inbox(i,j,k))
                    {
                        count++;
                        value=k;
                    }
                }
                if(count==1)sudoku[i][j]=value;
            }
        }
    }
}

void mainfilling(int arr[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(sudoku[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    if(!inbox(i,j,k))
                    {
                        int r,c,v,count1=0,count2=0;
                        r=i/3;
                        r=r*3;
                        c=j/3;
                        c=c*3;
                        for(int p=0;p<3;p++)
                        {
                            if(c+p!=j && (incoloumn(c+p,k) || (sudoku[r][c+p]!=0 && sudoku[r+1][c+p]!=0 && sudoku[r+2][c+p]!=0) ))count1++;
                            if(r+p!=i && (sudoku[r+p][j]!=0 || inrow(r+p,k)))count1++;

                            if(r+p!=i && (inrow(r+p,k) || (sudoku[r+p][c]!=0 && sudoku[r+p][c+1]!=0 && sudoku[r+p][c+2]!=0)))count2++;
                            if(c+p!=j && (sudoku[i][c+p]!=0 || incoloumn(c+p,k)))count2++;
                        }
                        if(count1==4 || count2==4)sudoku[i][j]=k;
                    }
                }
            }
        }
    }
    cout<<"done"<<endl;
}

int main()
{
    cout<<"Enter the sudoku without any extra spaces"<<endl;
    cout<<"Enter 0 in blank spaces"<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>sudoku[i][j];
        }
    }
    basicfilling(sudoku);
    while(zero(sudoku))
    {
        basicfilling(sudoku);
        mainfilling(sudoku);
    }
    cout<<"\n"<<endl;
    display(sudoku);
    cout<<"\n done";
    return 0;
}

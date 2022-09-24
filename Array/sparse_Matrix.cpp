#include <iostream>
using namespace std;

int display_original(int A[][10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//transpose of original matrix
int display_trans(int B[][10], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << B[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
//simple transpose
int print_compact(int A[][10], int row, int col, int zero)
{
    int size = (row * col) - zero;
    int compact[size][3];
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (A[i][j] != 0)
            {
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = A[i][j];
                k++;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << compact[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Transpose of matrix is " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << compact[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
int fast_transpose(int A[][10], int row, int col, int zero)
{
    int count = (row * col) - zero;
    int compact[count][3];
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (A[i][j] != 0)
            {
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = A[i][j];
                k++;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << compact[i][j] << " ";
        }
        cout << endl;
    }
    
    int sparse1[count+1][3];

    sparse1[0][0] = row;
    sparse1[0][1] = col;
    sparse1[0][2] = count;

    for(int i=0; i<count; i++)
    {
        for(int j=0; j<3; j++)
        {
            sparse1[i+1][j] = compact[i][j];
        }
    }

    // Fast Transpose
    int loc, i, col_no;
    int result[100][3];

    int total[sparse1[0][1]], index[sparse1[0][1]+1];

    for(i=0; i<sparse1[0][1]; i++)
    {
        total[i] = 0;
    }

    for(i=1; i<=sparse1[0][2]; i++)
    {
        col_no = sparse1[i][1];
        total[col_no]++;
    }

    index[0] =1;

    for(i=1; i<=sparse1[0][1]; i++)
    {
        index[i] = index[i-1] + total[i-1];
    }

    result[0][0] = sparse1[0][1];
    result[0][1] = sparse1[0][0];
    result[0][2] = sparse1[0][2];

    for(i=0; i<=sparse1[0][2]; i++)
    {
        col_no = sparse1[i][1];
        loc = index[col_no];
        result[loc][0] = sparse1[i][1];
        result[loc][1] = sparse1[i][0];        
        result[loc][2] = sparse1[i][2];
        index[col_no]++;
    }

    cout << "Fast Transpose Result";
    cout << "\n\tRows Columns Values";
    for(int i=1; i<=result[0][2]; i++)
    {
        cout << endl;
        for(int j=0; j<3; j++)
        {
            cout << " \t " << result[i][j];
        }
    }cout<<endl;
    return 0;
}
//Addition of two sparse matrix
int add_sparse(int mat1[][10], int mat2[][10], int row, int col, int zero1, int zero2)
{
    int size1 = (row * col) - zero1;
    int mat1com[size1][3];
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat1[i][j] != 0)
            {
                mat1com[k][0] = i;
                mat1com[k][1] = j;
                mat1com[k][2] = mat1[i][j];
                k++;
            }
        }
    }

    int size2 = (row * col) - zero2;
    int mat2com[size2][3];
    int l = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat1[i][j] != 0)
            {
                mat2com[l][0] = i;
                mat2com[l][1] = j;
                mat2com[l][2] = mat1[i][j];
                l++;
            }
        }
    }
    int add[size1][3];
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            add[i][1] = mat1[i][j];
            add[i][2] = mat1[i][j];

            add[i][3] = mat1com[i][3] + mat2com[i][3];
        }
    }
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << add[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    int mat1_row, mat1_col, mat2_row, mat2_col;
    cout << "enter size of first matrix" << endl;
    cin >> mat1_row >> mat1_col;
    cout << "enter size of second matrix" << endl;
    cin >> mat2_row >> mat2_col;
    int mat1[mat1_row][10];
    int mat2[mat2_row][10];
    int count_zero_mat1 = 0;

    cout << "enter " << mat1_row * mat1_col << " matrix elements for matrix 1" << endl;
    for (int i = 0; i < mat1_row; i++)
    {
        for (int j = 0; j < mat1_col; j++)
        {
            cin >> mat1[i][j];
            if (mat1[i][j] == 0)
            {
                count_zero_mat1++;
            }
        }
    }

    int count_zero_mat2 = 0;

    cout << "enter " << mat2_row * mat2_col << " matrix elements for matrix 1" << endl;
    for (int i = 0; i < mat2_row; i++)
    {
        for (int j = 0; j < mat2_col; j++)
        {
            cin >> mat2[i][j];
            if (mat2[i][j] == 0)
            {
                count_zero_mat2++;
            }
        }
    }
    cout << "original first matrix" << endl;
    display_original(mat1, mat1_row, mat1_col);
    cout << "original second matrix" << endl;
    display_original(mat2, mat2_row, mat2_col);
    cout << "\n \n";
    int q = 0;
    do
    {
        int g;
        cout << "enter 1 for transpose of original matrix " << endl;
        cout << "enter 2 for fast transpose" << endl;
        cout << "enter 3 for convert into sparse matrix and its transpose" << endl;
        cout << "enter 5 for exist" << endl;
        cin >> g;
        cout << "\n";
        switch (g)
        {
        case 1:
        {
            cout << "transpose of first matrix :" << endl;
            display_trans(mat1, mat1_row, mat1_col);
            cout << "transpose of second matrix :" << endl;
            display_trans(mat2, mat2_row, mat2_col);
            break;
        }
        case 2:
        {
            if (count_zero_mat1 > (mat1_row * mat1_col) / 2)
            {
                cout << "entered first matrix is sparse matrix:" << endl;
                cout << "compactible matrix is " << endl;
                fast_transpose(mat1, mat1_row, mat1_col, count_zero_mat1);
            }
            if (count_zero_mat2 > (mat2_row * mat2_col) / 2)
            {
                cout << "entered second  matrix is sparse matrix:" << endl;
                cout << "compactible matrix is " << endl;
                fast_transpose(mat2, mat2_row, mat2_col, count_zero_mat2);
            }
            else
            {
                cout << "matrix is not sparse matrix" << endl;
            }
            break;
        }
        case 3:
        {
            if (count_zero_mat1 > (mat1_row * mat1_col) / 2)
            {
                cout << "entered first matrix is sparse matrix:" << endl;
                cout << "compactible matrix is " << endl;
                print_compact(mat1, mat1_row, mat1_col, count_zero_mat1);
            }
            if (count_zero_mat2 > (mat2_row * mat2_col) / 2)
            {
                cout << "entered second  matrix is sparse matrix:" << endl;
                cout << "compactible matrix is " << endl;
                print_compact(mat2, mat2_row, mat2_col, count_zero_mat2);
            }
            else
            {
                cout << "matrix is not sparse matrix" << endl;
            }
            break;
        }
        case 5:
        {
            exit(0);
        }
        }
    } while (q >= 0);
}
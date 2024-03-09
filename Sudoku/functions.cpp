//#include <iostream>
//#include <conio.h>
//using namespace std;
//char input(char arr[9][9], int r, int c);
//void puzzle(char arr[9][9]);
//bool checkRow(char arr[9][9], char ch, int r, int c);
//bool checkCol(char arr[9][9], char ch, int r, int c);
//bool checkBox(char arr[9][9], char ch, int r, int c);
//void store(char arr[9][9], char ch, int r, int c);
//bool checkSudoku(char arr[9][9]);
//void board(char arr[9][9]);
//char arr[9][9];
//int main()
//{
//    char ch;
//    bool ro = false, co = false, bo = false, s=false;
//    int r, c;
//
//    puzzle(arr);
//    board(arr);
//    while (!s)
//    {
//        cout << "Enter the number (1-9)\t";
//        cin >> ch;
//        cout << "Row =\t";
//        cin >> r;
//        cout << "Column =\t";
//        cin >> c;
//        ro = checkRow(arr, ch, r, c);
//        co = checkCol(arr, ch, r, c);
//        bo = checkBox(arr, ch, r, c);
//        if (ro && co && bo)
//        {
//            store(arr, ch, r, c);
//        }
//        else
//        {
//            cout << "Number already exits in Row , Column or Grid" << endl;
//        }
//        board(arr);
//        s == checkSudoku(arr);
//    }
//}
//char input(char arr[9][9], int r, int c)
//{
//    char ch = _getch();
//    if (ch != '0' && ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != '7' && ch != '8' && ch != '9')
//    {
//        while (ch != '0' && ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != '7' && ch != '8' && ch != '9')
//            ch = _getch();
//    }
//    if (ch == '0')
//    {
//        ch == ' ';
//        return ' ';
//    }
//    return ch;
//}
//bool checkRow(char arr[9][9], char ch, int r, int c)
//{
//    cout << ch;
//    for (int i = 0; i < 9; i++)
//    {
//        if (arr[i][c] == ch)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//bool checkCol(char arr[9][9], char ch, int r, int c)
//{
//    for (int j = 0; j < 9; j++)
//    {
//        if (arr[r][j] == ch)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//bool checkBox(char arr[9][9], char ch, int r, int c)
//{
//    int i, j, a = 0, b = 0;
//    if (r % 3 == 0)
//    {
//        a = r;
//    }
//    else if (r % 3 == 1)
//    {
//        a = r - 1;
//    }
//    else if (r % 3 == 2)
//    {
//        a = r - 2;
//    }
//    if (c % 3 == 0)
//    {
//        b = c;
//    }
//    else if (c % 3 == 1)
//    {
//        b = c - 1;
//    }
//    else if (c % 3 == 2)
//    {
//        b = c - 2;
//    }
//    for (i = a; i < a + 3; i++)
//    {
//
//        for (j = b; j < b + 3; j++)
//        {
//            if (arr[i][j] == ch && (i != r || j != c))
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//void puzzle(char arr[9][9])
//{
//    int n;
//    /*char ar[9][9] = { {'4','8','9','3','1','5','2','6','7'},
//                      { '1','6','2','4','9','7','3','5','8' },
//                      { '3','5','7','2','8','6','9','1','4' },
//                      { '8','9','5','6','3','1','4','7','2' },
//                      { '6','2','1','7','4','8','5','9','3' },
//                      { '7','4','3','5','2','9','1','8','6' },
//                      { '9','1','4','8','7','3','6','2','5' },
//                      { '2','7','6','1','5','4',' ','3','9' },
//                      { '5','3','8','9','6','2','7','4','1' } }; */
//    char ar[9][9] = { {' ',' ',' ','2',' ','9',' ',' ','1'},
//                      {' ','8',' ',' ',' ',' ',' ',' ',' '},
//                      {' ',' ',' ',' ',' ','4',' ','6',' '},
//                      {'8',' ',' ',' ','9',' ',' ',' ',' '},
//                      {' ',' ','4',' ',' ',' ','9',' ',' '},
//                      {' ',' ',' ',' ',' ',' ',' ',' ','8'},
//                      {' ','1',' ',' ',' ','6',' ',' ',' '},
//                      {' ',' ',' ','9',' ',' ',' ','3',' '},
//                      {'7',' ',' ',' ','1',' ','2',' ',' '} };
//        for (int i = 0; i < 9; i++)
//        {
//            for (int j = 0; j < 9; j++)
//            {
//                arr[i][j] = ar[i][j];
//            }
//        }
//    
//
//}
//void store(char arr[9][9], char ch, int r, int c)
//{
//    arr[r][c] = ch;
//}
//bool checkSudoku(char arr[9][9])
//{
//    bool row = false, col = false, box = false;
//    for (int i = 0; i < 9; i++)
//    {
//        for (int j = 0; j < 9; j++)
//        {
//            box = checkBox(arr, arr[i][j], i, j);
//            row = checkRow(arr, arr[i][j], i, j);
//            col = checkCol(arr, arr[i][j], i, j);
//            if (!row && !col && !box)
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//void board(char arr[9][9])
//{
//    cout << "\t      ";
//    for (int i = 0; i < 9; i++)
//    {
//        cout << i << "     ";
//    }
//    cout << endl <<"\t   ";
//    for (int i = 0; i <= 54; i++)
//    {
//        cout << "-";
//    }
//    cout << endl;
//    for (int i = 0; i < 9; i++)
//    {
//        cout << "\t" << i << "  |  ";
//        for (int j = 0; j < 9; j++)
//            cout << arr[i][j] << "  |  ";
//        cout << endl << "\t   ";
//        for (int i = 0; i <= 54; i++)
//        {
//            cout << "-";
//        }
//        cout << endl;
//    }
//}

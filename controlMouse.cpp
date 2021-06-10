// controlMouse.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <windows.h>
#include <iostream>

void moveto(int x, int y)
{
    POINT p;
    GetCursorPos(&p);
    int diffx, diffy;
    diffx = x > p.x ? 1 : -1;
    diffy = y > p.y ? 1 : -1;
    //std::cout << "diffx=" << diffx << "diffy=" << diffy << "\n";
    for (int i = 0;i < 100;i++)
    {
        SetCursorPos((int)(p.x + (diffx * i)), (int)(p.y + (diffx * i)));
        Sleep(10);
    }
    SetCursorPos(x,y);
}

int main()
{
    bool leave=false;
    int count=0;
    LONG previous_x, previous_y;
    POINT p;
    GetCursorPos(&p);
    previous_x = p.x;
    previous_y = p.y;
    //std::cout << "p.x=" << p.x<< "p.y=" << p.y << "\n";
    while (!leave)
    {
        GetCursorPos(&p);
        if ((p.x == previous_x) && (p.y == previous_y))
        {
            //std::cout << "Match!\n";
            //update xy
            previous_x = p.x;
            previous_y = p.y;
            if ((p.x) >= 800)
            {
                previous_x = 0;
            }
            if ((p.y) >= 600)
            {
                previous_y = 0;
            }
            //SetCursorPos((int)(previous_x +20),(int)(previous_y +20));
            moveto((int)(previous_x + 100), (int)(previous_y + 100));
            count++;
            //std::cout << "Move to"<< "p.x=" << (int)(previous_x + 20) << "p.y=" << (int)(previous_y + 20) << "\n";
        }
        else
        {
            //std::cout << "no Match!\n";
            GetCursorPos(&p);
            //update xy
            previous_x = p.x;
            previous_y = p.y;
            //std::cout << "p.x=" << p.x << "p.y=" << p.y << "\n";
        }

        if (count >= 20)
        {
            count = 0;
            mouse_event(MOUSEEVENTF_RIGHTDOWN, p.x, p.y,0,0);
            mouse_event(MOUSEEVENTF_RIGHTUP, p.x, p.y, 0, 0);
        }
        //GetCursorPos(&p);
        //std::cout << "p.x="<<p.x << "p.y=" << p.y <<"\n";
        printf("p.x= %d p.y= %d \n",p.x,p.y);
        //SetCursorPos(200, 200);
        Sleep(1000);

    }


    std::cout << "control end!!\n";

    return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案

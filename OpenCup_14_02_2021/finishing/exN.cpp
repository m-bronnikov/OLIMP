// Made by Lina Veltman
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

//pawn 8
//others 2

int main(int argc, char* argv[])
{
    int k1, k2;
    std::cin >> k1 >> k2;
    std::string str;
    
    std::vector<int> first(12, 0);
    
    for (int i = 0; i < k1; ++i)
    {
        std::cin >> str;
        
        if (str[0] == 'b') // black
        {
            std::cin >> str;
            if (str[0] == 'r') // rook 4
            {
                ++first[4];
            }
            else if (str[0] == 'b') // bishop 2
            {
                ++first[2];
            }
            else if (str[0] == 'q') // queen 1
            {
                ++first[1];
            }
            else if (str[0] == 'p') // pawns 5
            {
                ++first[5];
            }
            else if (str[1] == 'n') // knight 3
            {
                ++first[3];
            }
            else if (str[1] == 'i')// king 0
            {
                ++first[0];
            }
        }
        else
        {
            std::cin >> str;
            if (str[0] == 'r') // rook 4
            {
                ++first[10];
            }
            else if (str[0] == 'b') // bishop 2
            {
                ++first[8];
            }
            else if (str[0] == 'q') // queen 1
            {
                ++first[7];
            }
            else if (str[0] == 'p') // pawns 5
            {
                ++first[11];
            }
            else if (str[1] == 'n') // knight 3
            {
                ++first[9];
            }
            else if (str[1] == 'i')// king 0
            {
                ++first[6];
            }
        }
    }
    
    std::string answer = "";
    int cnt;
    if (first[0] != 1)
    {
        answer += "black king\n";
    }
    if (first[1] != 1)
    {
        answer += "black queen\n";
    }
    if (first[2] != 2)
    {
        cnt = 2 - first[2];
        while (cnt)
        {
            answer += "black bishop\n";
            --cnt;
        }
    }
    if (first[3] != 2)
    {
        cnt = 2 - first[3];
        while (cnt)
        {
            answer += "black knight\n";
            --cnt;
        }
    }
    if (first[4] != 2)
    {
        cnt = 2 - first[4];
        while (cnt)
        {
            answer += "black rook\n";
            --cnt;
        }
    }
    if (first[5] != 8)
    {
        cnt = 8 - first[5];
        while (cnt)
        {
            answer += "black pawn\n";
            --cnt;
        }
    }
    
    if (first[6] != 1)
    {
        answer += "white king\n";
    }
    if (first[7] != 1)
    {
        answer += "white queen\n";
    }
    if (first[8] != 2)
    {
        cnt = 2 - first[8];
        while (cnt)
        {
            answer += "white bishop\n";
            --cnt;
        }
    }
    if (first[9] != 2)
    {
        cnt = 2 - first[9];
        while (cnt)
        {
            answer += "white knight\n";
            --cnt;
        }
    }
    if (first[10] != 2)
    {
        cnt = 2 - first[10];
        while (cnt)
        {
            answer += "white rook\n";
            --cnt;
        }
    }
    if (first[11] != 8)
    {
        cnt = 8 - first[11];
        while (cnt)
        {
            answer += "white pawn\n";
            --cnt;
        }
    }
    
    for (int i = 0; i < k2; ++i)
    {
        std::cin >> str;
        
        if (str[0] == 'b') // black
        {
            std::cin >> str;
            if (str[0] == 'r') // rook 4
            {
                ++first[4];
            }
            else if (str[0] == 'b') // bishop 2
            {
                ++first[2];
            }
            else if (str[0] == 'q') // queen 1
            {
                ++first[1];
            }
            else if (str[0] == 'p') // pawns 5
            {
                ++first[5];
            }
            else if (str[1] == 'n') // knight 3
            {
                ++first[3];
            }
            else if (str[1] == 'i')// king 0
            {
                ++first[0];
            }
        }
        else
        {
            std::cin >> str;
            if (str[0] == 'r') // rook 4
            {
                ++first[10];
            }
            else if (str[0] == 'b') // bishop 2
            {
                ++first[8];
            }
            else if (str[0] == 'q') // queen 1
            {
                ++first[7];
            }
            else if (str[0] == 'p') // pawns 5
            {
                ++first[11];
            }
            else if (str[1] == 'n') // knight 3
            {
                ++first[9];
            }
            else if (str[1] == 'i')// king 0
            {
                ++first[6];
            }
        }
    }
    
    if (first[0] < 1)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    if (first[1] < 1)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    if (first[2] < 2)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    if (first[3] < 2)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    if (first[4] < 2)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    if (first[5] < 8)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    
    if (first[6] < 1)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    if (first[7] < 1)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    if (first[8] < 2)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    if (first[9] < 2)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    if (first[10] < 2)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    if (first[11] < 8)
    {
        std::cout << "impossible" << std::endl;
        return 0;
    }
    
    // maybe no need to check this
    if (answer.size() != 0)
    {
        std::cout << answer;
    }
    else
    {
        std::cout << std::endl;
    }

    
    return 0;
}


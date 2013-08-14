#include <iostream>
#include <Cloak/cloak.h>

// マクロ文字列化
#define XSTR(x) #x
#define STR(x)  XSTR(x)

// 繰り返し制御テスト TEST1
#define M(s, i, _) i
#define TEST1 EXPR_S(0)(REPEAT_S(0, 8, M, ~))

// 繰り返し制御テスト TEST2
#define TEST2 EXPR_S(0)(REPEAT_S(0, 9, M, ~))

/**
 * Build and Run: g++ -I. preprocessor.cpp -o preprocessor && ./preprocessor
 */
int main()
{
     std::cout << "preprocessor test..." << std::endl;

     /**
      * とりあえず EXPR_S(0)(REPEAT_S(0, <ループ回数>, M, ~)) の形で10回ループまでできる
      */
     std::string test1 = STR(TEST1);
     std::cout << "EXPR_S(0)(REPEAT_S(0, 8, M, ~)) : " << test1 << std::endl;

     std::string test2 = STR(TEST2);
     std::cout << "EXPR_S(0)(REPEAT_S(0, 9, M, ~)) : " << test2 << std::endl;

     return 0;
}

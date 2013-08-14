#include <iostream>
#include <Cloak/cloak.h>
#include <enumstring.hpp>
#include <preprocessor.hpp>

// 繰り返し制御テスト TEST1
#define M(s, i, _) i
#define TEST1 EXPR_S(0)(REPEAT_S(0, 8, M, ~))

// 繰り返し制御テスト TEST2
#define TEST2 EXPR_S(0)(REPEAT_S(0, 9, M, ~))

/** 列挙型を文字列化 ~ 通常版 */
// Begin_Enum_String( TEST_ENUMS )
// {
//      Enum_String( ID_Hoge );
// }
// End_Enum_String;

/**
 * Build and Run: g++ -I. preprocessor.cpp -o preprocessor && ./preprocessor
 */
int main()
{
     std::cout << "preprocessor test..." << std::endl << std::endl;

     /**
      * とりあえず EXPR_S(0)(REPEAT_S(0, <ループ回数>, M, ~)) の形で10回ループまでできる
      */
     std::string test1 = STR(TEST1);
     std::cout << "EXPR_S(0)(REPEAT_S(0, 8, M, ~)) : " << test1 << std::endl;

     std::string test2 = STR(TEST2);
     std::cout << "EXPR_S(0)(REPEAT_S(0, 9, M, ~)) : " << test2 << std::endl;

     // 文字列化された列挙型の出力
     for (int i = 0; i < ID_End; i++) {
	  const std::string &str = EnumString<TEST_ENUMS>::From( static_cast<TEST_ENUMS>(i) );
	  std::cout << "enums: " << str << std::endl;
     }

     return 0;
}

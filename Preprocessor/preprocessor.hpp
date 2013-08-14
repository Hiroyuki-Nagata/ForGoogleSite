#ifndef PREPROCESSOR_HPP_
#define PREPROCESSOR_HPP_

#include "enumstring.hpp"
#include <algorithm>

// マクロ文字列化
#define XSTR(x) #x
#define STR(x)  XSTR(x)

// テーブル要素
#define X_TABLE_ITEM(x) X(x, STR(x))
// テーブル
#define X_TABLE \
     X_TABLE_ITEM(ID_Hoge) \
     X_TABLE_ITEM(ID_Fuga) \
     X_TABLE_ITEM(ID_Piyo) \
     X_TABLE_ITEM(ID_End)

// 列挙型の宣言
typedef enum {
     ID_Begin = -1,
     #define X(Enum, String) Enum,
     X_TABLE
     #undef X
} TEST_ENUMS;

// 文字列化
Begin_Enum_String( TEST_ENUMS )
{

#define X(Enum, String)					\
     Enum_String( Enum )                                \

     X_TABLE
#undef X

}
End_Enum_String;


#endif /* PREPROCESSOR */

/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** binaryConverterTests
*/

#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS
#include <criterion/criterion.h>
#include <cstring>

#include "utils/binaryConverter/binaryConverter.hpp"

Test(binaryConverter, convertBinary_1)
{
    binaryConverter converter;
    message_t messages[2] = {
        {"test1.raw", 212, 3999},
        {"test2.ppt", 533, 612}
    };
    char *buffer = converter.convertStructToBinary(2, messages);
    message_t *result = converter.convertBinaryToStruct(buffer);

    cr_assert_str_eq(result[0].sprite_name, "test1.raw");
    cr_assert_eq(result[0].x, 212);
    cr_assert_eq(result[0].y, 3999);
    cr_assert_str_eq(result[1].sprite_name, "test2.ppt");
    cr_assert_eq(result[1].x, 533);
    cr_assert_eq(result[1].y, 612);
    delete[] buffer;
    delete[] result;
}

Test(binaryConverter, convertBinary_2)
{
    binaryConverter converter;
    message_t messages[2] = {
        {"zoulou.jpeg", -332, 17822},
        {"houhou.png", 352, -2226}
    };
    char *buffer = converter.convertStructToBinary(2, messages);
    message_t *result = converter.convertBinaryToStruct(buffer);

    cr_assert_str_eq(result[0].sprite_name, "zoulou.jpeg");
    cr_assert_eq(result[0].x, -332);
    cr_assert_eq(result[0].y, 17822);
    cr_assert_str_eq(result[1].sprite_name, "houhou.png");
    cr_assert_eq(result[1].x, 352);
    cr_assert_eq(result[1].y, -2226);
    delete[] buffer;
    delete[] result;
}

Test(binaryConverter, convertBinary_long)
{
    binaryConverter converter;
    message_t messages[20] = {
        {"zoulou.jpeg", -332, 17822},
        {"houhou.png", 352, -2226},
        {"ab.jpeg", 1432, 3693},
        {"b.jpeg", 6783, 0},
        {"c.jpeg", 683, 0},
        {"d.jpeg", 68337, 0},
        {"e", 68337, 0},
        {"f", 678337, 0},
        {"g", 6783, 0},
        {"h", 6743, 6720},
        {"i", 6743, 6720},
        {"j.test", -3430, 23720},
        {"k.test", -3430, 23720},
        {"l.test", -3430, 24},
        {"m", -3430, 24},
        {"n", -34327, 204},
        {"o.---", -34327, 143},
        {"p.---", -34327, 123},
        {"q.---", -34327, 123},
        {"r", 0, 123}
    };
    char *buffer = converter.convertStructToBinary(20, messages);
    message_t *result = converter.convertBinaryToStruct(buffer);

    cr_assert_str_eq(result[0].sprite_name, "zoulou.jpeg");
    cr_assert_eq(result[0].x, -332);
    cr_assert_eq(result[0].y, 17822);
    cr_assert_str_eq(result[1].sprite_name, "houhou.png");
    cr_assert_eq(result[1].x, 352);
    cr_assert_eq(result[1].y, -2226);
    cr_assert_str_eq(result[2].sprite_name, "ab.jpeg");
    cr_assert_eq(result[2].x, 1432);
    cr_assert_eq(result[2].y, 3693);
    cr_assert_str_eq(result[3].sprite_name, "b.jpeg");
    cr_assert_eq(result[3].x, 6783);
    cr_assert_eq(result[3].y, 0);
    cr_assert_str_eq(result[4].sprite_name, "c.jpeg");
    cr_assert_eq(result[4].x, 683);
    cr_assert_eq(result[4].y, 0);
    cr_assert_str_eq(result[5].sprite_name, "d.jpeg");
    cr_assert_eq(result[5].x, 68337);
    cr_assert_eq(result[5].y, 0);
    cr_assert_str_eq(result[6].sprite_name, "e");
    cr_assert_eq(result[6].x, 68337);
    cr_assert_eq(result[6].y, 0);
    cr_assert_str_eq(result[7].sprite_name, "f");
    cr_assert_eq(result[7].x, 678337);
    cr_assert_eq(result[7].y, 0);
    cr_assert_str_eq(result[8].sprite_name, "g");
    cr_assert_eq(result[8].x, 6783);
    cr_assert_eq(result[8].y, 0);
    cr_assert_str_eq(result[9].sprite_name, "h");
    cr_assert_eq(result[9].x, 6743);
    cr_assert_eq(result[9].y, 6720);
    cr_assert_str_eq(result[10].sprite_name, "i");
    cr_assert_eq(result[10].x, 6743);
    cr_assert_eq(result[10].y, 6720);
    cr_assert_str_eq(result[11].sprite_name, "j.test");
    cr_assert_eq(result[11].x, -3430);
    cr_assert_eq(result[11].y, 23720);
    cr_assert_str_eq(result[12].sprite_name, "k.test");
    cr_assert_eq(result[12].x, -3430);
    cr_assert_eq(result[12].y, 23720);
    cr_assert_str_eq(result[13].sprite_name, "l.test");
    cr_assert_eq(result[13].x, -3430);
    cr_assert_eq(result[13].y, 24);
    cr_assert_str_eq(result[14].sprite_name, "m");
    cr_assert_eq(result[14].x, -3430);
    cr_assert_eq(result[14].y, 24);
    cr_assert_str_eq(result[15].sprite_name, "n");
    cr_assert_eq(result[15].x, -34327);
    cr_assert_eq(result[15].y, 204);
    cr_assert_str_eq(result[16].sprite_name, "o.---");
    cr_assert_eq(result[16].x, -34327);
    cr_assert_eq(result[16].y, 143);
    cr_assert_str_eq(result[17].sprite_name, "p.---");
    cr_assert_eq(result[17].x, -34327);
    cr_assert_eq(result[17].y, 123);
    cr_assert_str_eq(result[18].sprite_name, "q.---");
    cr_assert_eq(result[18].x, -34327);
    cr_assert_eq(result[18].y, 123);
    cr_assert_str_eq(result[19].sprite_name, "r");
    cr_assert_eq(result[19].x, 0);
    cr_assert_eq(result[19].y, 123);
    delete[] buffer;
    delete[] result;
}

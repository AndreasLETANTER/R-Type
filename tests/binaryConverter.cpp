#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "utils/binaryConverterClass/binaryConverter.hpp"

Test(binaryConverter, string_to_binary_connexion)
{
    binaryConverter binaryConverter;
    std::string input = "100:";
    std::string expected_output = "00110001001100000011000000111010";
    std::string output = binaryConverter.string_to_binary(input);
    cr_assert(output == expected_output, "Expected %s but got %s", expected_output.c_str(), output.c_str());
}

Test(binaryConverter, binary_to_string_connexion)
{
    binaryConverter binaryConverter;
    std::string input = "00110001001100000011000000111010";
    std::string expected_output = "100:";
    std::string output = binaryConverter.binary_to_string(input);
    cr_assert(output == expected_output, "Expected %s but got %s", expected_output.c_str(), output.c_str());
}

Test(binaryConverter, string_to_binary_connexion2)
{
    binaryConverter binaryConverter;
    std::string input = "300:id=2;{sprite_name=”plane.jpeg”,pos=[x=”-92.92”,y=“686.16”]};{sprite_name=”mob.jpeg”,pos=[x=”23.19”,y=“68.22”]}";
    std::string expected_output = "001100110011000000110000001110100110100101100100001111010011001000111011011110110111001101110000011100100110100101110100011001010101111101101110011000010110110101100101001111011110001010000000100111010111000001101100011000010110111001100101001011100110101001110000011001010110011111100010100000001001110100101100011100000110111101110011001111010101101101111000001111011110001010000000100111010010110100111001001100100010111000111001001100101110001010000000100111010010110001111001001111011110001010000000100111000011011000111000001101100010111000110001001101101110001010000000100111010101110101111101001110110111101101110011011100000111001001101001011101000110010101011111011011100110000101101101011001010011110111100010100000001001110101101101011011110110001000101110011010100111000001100101011001111110001010000000100111010010110001110000011011110111001100111101010110110111100000111101111000101000000010011101001100100011001100101110001100010011100111100010100000001001110100101100011110010011110111100010100000001001110000110110001110000010111000110010001100101110001010000000100111010101110101111101";
    std::string output = binaryConverter.string_to_binary(input);
    cr_assert(output == expected_output, "Expected %s but got %s", expected_output.c_str(), output.c_str());
}

Test(binaryConverter, binary_to_string_empty)
{
    binaryConverter binaryConverter;
    std::string input = "";
    std::string expected_output = "";
    std::string output = binaryConverter.binary_to_string(input);
    cr_assert(output == expected_output, "Expected %s but got %s", expected_output.c_str(), output.c_str());
}

Test(binaryConverter, string_to_binary_empty)
{
    binaryConverter binaryConverter;
    std::string input = "";
    std::string expected_output = "";
    std::string output = binaryConverter.string_to_binary(input);
    cr_assert(output == expected_output, "Expected %s but got %s", expected_output.c_str(), output.c_str());
}

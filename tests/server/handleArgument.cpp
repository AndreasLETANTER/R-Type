/*
** EPITECH PROJECT, 2023
** Test handle argument
** File description:
** In this file we test the handle argument class
*/

#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../../sources/server/handleArgument/handleArgument.hpp"

Test(handleArgument, getPort_validPort)
{
    handleArgument ha;
    std::string validPort = "8080";
    u_int16_t expectedPort = 8080;

    cr_redirect_stderr();
    u_int16_t actualPort = ha.getPort(validPort.c_str());
    cr_assert_stderr_eq_str("");
    cr_assert_eq(actualPort, expectedPort, "Expected port %d but got %d", expectedPort, actualPort);
}

Test(handleArgument, getPort_validPort_underMin)
{
    handleArgument ha;
    std::string validPort = "1024";
    u_int16_t expectedPort = 1024;

    cr_redirect_stderr();
    u_int16_t actualPort = ha.getPort(validPort.c_str());
    cr_assert_stderr_eq_str("");
    cr_assert_eq(actualPort, expectedPort, "Expected port %d but got %d", expectedPort, actualPort);
}

Test(handleArgument, getPort_validPort_overMax)
{
    handleArgument ha;
    std::string validPort = "65535";
    u_int16_t expectedPort = 65535;

    cr_redirect_stderr();
    u_int16_t actualPort = ha.getPort(validPort.c_str());
    cr_assert_stderr_eq_str("");
    cr_assert_eq(actualPort, expectedPort, "Expected port %d but got %d", expectedPort, actualPort);
}

Test(handleArgument, getPort_emptyString)
{
    handleArgument ha;
    std::string emptyString = "";
    u_int16_t expectedPort = 8080;

    cr_redirect_stderr();
    u_int16_t actualPort = ha.getPort(emptyString.c_str());
    cr_assert_stderr_eq_str("Invalid argument: empty string\n");
    cr_assert_eq(actualPort, expectedPort, "Expected port %d but got %d", expectedPort, actualPort);
}

Test(handleArgument, getPort_invalidPort)
{
    handleArgument ha;
    std::string invalidPort = "22";
    u_int16_t expectedPort = 8080;

    cr_redirect_stderr();
    u_int16_t actualPort = ha.getPort(invalidPort.c_str());
    cr_assert_stderr_eq_str("Invalid argument: port is not in range\n");
    cr_assert_eq(actualPort, expectedPort, "Expected port %d but got %d", expectedPort, actualPort);
}

Test(handleArgument, getPort_negativePort)
{
    handleArgument ha;
    std::string negativePort = "-1";
    u_int16_t expectedPort = 8080;

    cr_redirect_stderr();
    u_int16_t actualPort = ha.getPort(negativePort.c_str());
    cr_assert_stderr_eq_str("Invalid argument: not a number or not a positive number\n");
    cr_assert_eq(actualPort, expectedPort, "Expected port %d but got %d", expectedPort, actualPort);
}

Test(handleArgument, getPort_nonNumericPort)
{
    handleArgument ha;
    std::string nonNumericPort = "abc";
    u_int16_t expectedPort = 8080;

    cr_redirect_stderr();
    u_int16_t actualPort = ha.getPort(nonNumericPort.c_str());
    cr_assert_stderr_eq_str("Invalid argument: not a number or not a positive number\n");
    cr_assert_eq(actualPort, expectedPort, "Expected port %d but got %d", expectedPort, actualPort);
}

Test(handleArgument, getPort_nonNumericPort2)
{
    handleArgument ha;
    std::string nonNumericPort = "abc123";
    u_int16_t expectedPort = 8080;

    cr_redirect_stderr();
    u_int16_t actualPort = ha.getPort(nonNumericPort.c_str());
    cr_assert_stderr_eq_str("Invalid argument: not a number or not a positive number\n");
    cr_assert_eq(actualPort, expectedPort, "Expected port %d but got %d", expectedPort, actualPort);
}

Test(handleArgument, getPort_nonNumericPort3)
{
    handleArgument ha;
    std::string nonNumericPort = "123abc";
    u_int16_t expectedPort = 8080;

    cr_redirect_stderr();
    u_int16_t actualPort = ha.getPort(nonNumericPort.c_str());
    cr_assert_stderr_eq_str("Invalid argument: not a number or not a positive number\n");
    cr_assert_eq(actualPort, expectedPort, "Expected port %d but got %d", expectedPort, actualPort);
}

Test(handleArgument, getPort_nonNumericPort4)
{
    handleArgument ha;
    std::string nonNumericPort = "abc123abc";
    u_int16_t expectedPort = 8080;

    cr_redirect_stderr();
    u_int16_t actualPort = ha.getPort(nonNumericPort.c_str());
    cr_assert_stderr_eq_str("Invalid argument: not a number or not a positive number\n");
    cr_assert_eq(actualPort, expectedPort, "Expected port %d but got %d", expectedPort, actualPort);
}

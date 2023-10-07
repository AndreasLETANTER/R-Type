/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** temp
*/

#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS
#include <criterion/criterion.h>
#include "ECS/SparseArrayClass/SparseArray.hpp"

Test(GetValueIndex, basic_get_value_index)
{
    int entity(10);
    SparseArray<int> sparseArray;

    sparseArray.insert_at(0, entity);
    cr_assert_eq(sparseArray[0].value(), 10);
}

Test(insert_at, basic_insert_at)
{
    int entity(10);
    SparseArray<int> sparseArray;

    sparseArray.insert_at(0, entity);
    cr_assert_eq(sparseArray.size(), 1);
}

Test(insert_at, multiple_insert_at)
{
    int entity(10);
    SparseArray<int> sparseArray;

    sparseArray.insert_at(0, entity);
    sparseArray.insert_at(1, entity);
    sparseArray.insert_at(2, entity);
    sparseArray.insert_at(3, entity);
    cr_assert_eq(sparseArray.size(), 4);
}

Test(insert_at, multiple_insert_at_same_place)
{
    int entity(10);
    SparseArray<int> sparseArray;

    sparseArray.insert_at(0, entity);
    sparseArray.insert_at(0, entity);
    sparseArray.insert_at(0, entity);
    sparseArray.insert_at(0, entity);
    cr_assert_eq(sparseArray.size(), 1);
}

Test(insert_at, insert_at_with_hole)
{
    int entity(10);
    SparseArray<int> sparseArray;

    sparseArray.insert_at(0, entity);
    sparseArray.insert_at(3, entity);
    cr_assert_eq(sparseArray.size(), 4);
}

Test(insert_at, multiple_insert_at_with_hole)
{
    int entity(10);
    SparseArray<int> sparseArray;

    sparseArray.insert_at(0, entity);
    sparseArray.insert_at(3, entity);
    sparseArray.insert_at(6, entity);
    sparseArray.insert_at(60, entity);
    cr_assert_eq(sparseArray.size(), 61);
}

Test(emplace_at, basic_emplace_at)
{
    SparseArray<int> sparseArray;

    sparseArray.emplace_at(0, 10);
    cr_assert_eq(sparseArray.size(), 1);
}

Test(emplace_at, multiple_emplace_at)
{
    SparseArray<int> sparseArray;

    sparseArray.emplace_at(0, 10);
    sparseArray.emplace_at(1, 10);
    sparseArray.emplace_at(2, 10);
    sparseArray.emplace_at(3, 10);
    cr_assert_eq(sparseArray.size(), 4);
}

Test(emplace_at, multiple_emplace_at_with_hole)
{
    SparseArray<int> sparseArray;

    sparseArray.emplace_at(0, 10);
    sparseArray.emplace_at(3, 10);
    sparseArray.emplace_at(6, 10);
    sparseArray.emplace_at(60, 10);
    cr_assert_eq(sparseArray.size(), 61);
}

Test(emplace_at, multiple_emplace_at_same_place)
{
    SparseArray<int> sparseArray;

    sparseArray.emplace_at(0, 10);
    sparseArray.emplace_at(0, 10);
    sparseArray.emplace_at(0, 10);
    sparseArray.emplace_at(0, 10);
    cr_assert_eq(sparseArray.size(), 1);
}

Test(emplace_at, multiple_emplace_at_advanced)
{
    SparseArray<int> sparseArray;

    sparseArray.emplace_at(0, 10);
    sparseArray.emplace_at(3, 11);
    sparseArray.emplace_at(2, 12);
    sparseArray.emplace_at(1, 13);
    cr_assert_eq(sparseArray.size(), 4);
    cr_assert_eq(sparseArray[0].value(), 10);
    cr_assert_eq(sparseArray[1].value(), 13);
    cr_assert_eq(sparseArray[2].value(), 12);
    cr_assert_eq(sparseArray[3].value(), 11);
}

Test(emplace_at, multiple_insert_at_advanced)
{
    SparseArray<int> sparseArray;

    sparseArray.insert_at(0, int(10));
    sparseArray.insert_at(3, int(11));
    sparseArray.insert_at(2, int(12));
    sparseArray.insert_at(1, int(13));
    cr_assert_eq(sparseArray.size(), 4);
    cr_assert_eq(sparseArray[0].value(), 10);
    cr_assert_eq(sparseArray[1].value(), 13);
    cr_assert_eq(sparseArray[2].value(), 12);
    cr_assert_eq(sparseArray[3].value(), 11);
}

Test(erase, basic_erase)
{
    SparseArray<int> sparseArray;

    sparseArray.emplace_at(0, 10);
    sparseArray.erase(0);
    cr_assert_eq(sparseArray.size(), 0);
}

Test(erase, advanced_erase)
{
    SparseArray<int> sparseArray;

    sparseArray.emplace_at(0, 10);
    sparseArray.emplace_at(1, 10);
    sparseArray.erase(0);
    cr_assert_eq(sparseArray.size(), 1);
    cr_assert_eq(sparseArray[0].value(), 10);
}

Test(insert_at, multiple_insert_at_value_check)
{
    SparseArray<int> sparseArray;

    sparseArray.insert_at(0, int(10));
    sparseArray.insert_at(3, int(11));
    sparseArray.insert_at(2, int(12));
    sparseArray.insert_at(1, int(13));
    cr_assert_eq(sparseArray.size(), 4);
    cr_assert_eq(sparseArray[0].value(), 10);
    cr_assert_eq(sparseArray[1].value(), 13);
    cr_assert_eq(sparseArray[2].value(), 12);
    cr_assert_eq(sparseArray[3].value(), 11);
}

Test(insert_at, multiple_insert_at_value_check_with_hole)
{
    SparseArray<int> sparseArray;

    sparseArray.insert_at(0, int(10));
    sparseArray.insert_at(3, int(11));
    sparseArray.insert_at(1, int(13));
    cr_assert_eq(sparseArray[0].value(), 10);
    cr_assert_eq(sparseArray[1].value(), 13);
    cr_assert_eq(sparseArray[2].has_value(), false);
    cr_assert_eq(sparseArray[3].value(), 11);
}

Test(get_index, basic_get_index)
{
    SparseArray<int> sparseArray;
    int entity(10);

    sparseArray.insert_at(0, entity);
    cr_assert_eq(sparseArray.get_index(sparseArray[0]), 0);
}

Test(get_index, get_index_with_hole)
{
    SparseArray<int> sparseArray;
    int entity(10);

    sparseArray.insert_at(0, entity);
    sparseArray.insert_at(3, entity);
    cr_assert_eq(sparseArray.get_index(sparseArray[0]), 0);
    cr_assert_eq(sparseArray.get_index(sparseArray[3]), 3);
}

Test(get_index, multiple_get_index)
{
    SparseArray<int> sparseArray;
    int entity(10);

    sparseArray.insert_at(0, entity);
    sparseArray.insert_at(3, int(11));
    sparseArray.insert_at(2, int(12));
    sparseArray.insert_at(1, int(13));
    cr_assert_eq(sparseArray.get_index(sparseArray[0]), 0);
    cr_assert_eq(sparseArray.get_index(sparseArray[1]), 1);
    cr_assert_eq(sparseArray.get_index(sparseArray[2]), 2);
    cr_assert_eq(sparseArray.get_index(sparseArray[3]), 3);
}

Test(get_index, get_index_error)
{
    SparseArray<int> sparseArray;
    int entity(10);

    sparseArray.insert_at(0, entity);
    cr_assert_throw(sparseArray.get_index(entity), std::runtime_error);
}

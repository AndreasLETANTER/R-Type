/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Registry
*/

#define _LIBCPP_DISABLE_DEPRECATION_WARNINGS
#include <criterion/criterion.h>
#include "../../sources/ECS/EntityClass/Entity.hpp"
#include "../../sources/ECS/SparseArrayClass/SparseArray.hpp"
#include "../../sources/ECS/RegistryClass/Registry.hpp"

Test(Registry, basic_register)
{
    Registry reg;

    cr_assert_eq(reg.register_component<int>().size(), 0);
}

Test(Registry, register_with_add)
{
    Registry reg;

    cr_assert_eq(reg.register_component<int>().insert_at(0, int(10)), 10);
}

Test(Registry, register_components_already_exist)
{
    Registry reg;

    reg.register_component<int>();
    cr_assert_throw(reg.register_component<int>(), std::runtime_error);
}

Test(Registry, basic_get_components)
{
    Registry reg;

    reg.register_component<int>();
    cr_assert_eq(reg.get_components<int>().size(), 0);
    reg.get_components<int>().insert_at(0, int(10));
    cr_assert_eq(reg.get_components<int>().size(), 1);
    cr_assert_eq(reg.get_components<int>()[0].value(), 10);
}

Test(Registry, advanced_get_components)
{
    Registry reg;

    reg.register_component<double>();
    reg.register_component<int>();
    cr_assert_eq(reg.get_components<double>().size(), 0);
    cr_assert_eq(reg.get_components<int>().size(), 0);
    reg.get_components<double>().insert_at(0, double(10));
    reg.get_components<int>().insert_at(0, 10);
    cr_assert_eq(reg.get_components<double>().size(), 1);
    cr_assert_eq(reg.get_components<int>().size(), 1);
    cr_assert_eq(reg.get_components<double>()[0].value(), 10);
    cr_assert_eq(reg.get_components<int>()[0], 10);
}

Test(Registry, advanced_get_components_with_hole)
{
    Registry reg;

    reg.register_component<char>();
    reg.register_component<int>();
    cr_assert_eq(reg.get_components<char>().size(), 0);
    cr_assert_eq(reg.get_components<int>().size(), 0);
    reg.get_components<char>().insert_at(0, 'a');
    reg.get_components<char>().insert_at(3, 'b');
    reg.get_components<int>().insert_at(0, 10);
    reg.get_components<int>().insert_at(3, 11);
    cr_assert_eq(reg.get_components<char>().size(), 4);
    cr_assert_eq(reg.get_components<int>().size(), 4);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
    cr_assert_eq(reg.get_components<int>()[0], 10);
    cr_assert_eq(reg.get_components<char>()[1].has_value(), false);
    cr_assert_eq(reg.get_components<char>()[2].has_value(), false);
    cr_assert_eq(reg.get_components<char>()[3].value(), 'b');
    cr_assert_eq(reg.get_components<int>()[1].has_value(), false);
    cr_assert_eq(reg.get_components<int>()[2].has_value(), false);
    cr_assert_eq(reg.get_components<int>()[3], 11);
}

Test(Registry, get_components_components_doesnt_exist)
{
    Registry reg;

    cr_assert_throw(reg.get_components<Entity>(), std::runtime_error);
}

Test(Registry, advanced_get_components_components_doesnt_exist)
{
    Registry reg;

    reg.register_component<int>();
    cr_assert_throw(reg.get_components<Entity>(), std::runtime_error);
}

Test(Registry, basic_erase_component)
{
    Registry reg;
    int entity(10);
    
    reg.register_component<int>();
    reg.spawn_entity();
    reg.get_components<int>().insert_at(0, entity);
    cr_assert_eq(reg.get_components<int>().size(), 1);
    reg.erase_entity<int>(reg.entity_from_index(0));
    cr_assert_eq(reg.get_components<int>().size(), 1);
    cr_assert_eq(reg.get_components<int>()[0].has_value(), false);
}

Test(Registry, advanced_erase_component)
{
    Registry reg;
    int entity(0);
    int entity2(2);
    
    reg.register_component<int>();
    reg.spawn_entity();
    reg.get_components<int>().insert_at(0, entity);
    reg.get_components<int>().insert_at(2, entity2);
    cr_assert_eq(reg.get_components<int>().size(), 3);
    reg.erase_entity<int>(reg.entity_from_index(0));
    cr_assert_eq(reg.get_components<int>().size(), 3);
    cr_assert_eq(reg.get_components<int>()[0].has_value(), false);
    cr_assert_eq(reg.get_components<int>()[1].has_value(), false);
    cr_assert_eq(reg.get_components<int>()[2].value(), 2);
}

Test(Registry, basic_spawn_entity)
{
    Registry reg;

    cr_assert_eq(reg.spawn_entity(), 0);
}

Test(Registry, multiple_spawn_entity)
{
    Registry reg;

    cr_assert_eq(reg.spawn_entity(), 0);
    cr_assert_eq(reg.spawn_entity(), 1);
    cr_assert_eq(reg.spawn_entity(), 2);
    cr_assert_eq(reg.spawn_entity(), 3);
    cr_assert_eq(reg.spawn_entity(), 4);
}

Test(Registry, basic_entity_from_index)
{
    Registry reg;

    cr_assert_eq(reg.spawn_entity(), 0);
    cr_assert_eq(reg.spawn_entity(), 1);
    cr_assert_eq(reg.spawn_entity(), 2);
    cr_assert_eq(reg.entity_from_index(0), 0);
    cr_assert_eq(reg.entity_from_index(1), 1);
    cr_assert_eq(reg.entity_from_index(2), 2);
}

Test(Registry, basic_entity_from_index_error)
{
    Registry reg;

    cr_assert_eq(reg.spawn_entity(), 0);
    cr_assert_eq(reg.spawn_entity(), 1);
    cr_assert_eq(reg.spawn_entity(), 2);
    cr_assert_eq(reg.entity_from_index(0), 0);
    cr_assert_eq(reg.entity_from_index(1), 1);
    cr_assert_eq(reg.entity_from_index(2), 2);
    cr_assert_throw(reg.entity_from_index(3), std::runtime_error);
}

Test(Registry, basic_kill_entity)
{
    Registry reg;

    cr_assert_eq(reg.spawn_entity(), 0);
    cr_assert_eq(reg.spawn_entity(), 1);
    cr_assert_eq(reg.spawn_entity(), 2);
    cr_assert_eq(reg.entity_from_index(0), 0);
    cr_assert_eq(reg.entity_from_index(1), 1);
    cr_assert_eq(reg.entity_from_index(2), 2);
    reg.kill_entity(reg.entity_from_index(1));
    cr_assert_eq(reg.entity_from_index(0), 0);
    cr_assert_throw(reg.entity_from_index(1), std::runtime_error);
    cr_assert_eq(reg.entity_from_index(2), 2);
}

Test(Registry, advanced_kill_entity)
{
    Registry reg;

    reg.register_component<int>();
    reg.register_component<char>();

    reg.spawn_entity();
    reg.spawn_entity();
    reg.spawn_entity();

    reg.add_component<int>(reg.entity_from_index(0), 10);
    reg.add_component<char>(reg.entity_from_index(0), 'a');
    reg.add_component<int>(reg.entity_from_index(1), 11);
    reg.add_component<char>(reg.entity_from_index(1), 'b');
    reg.add_component<int>(reg.entity_from_index(2), 12);
    reg.add_component<char>(reg.entity_from_index(2), 'c');

    cr_assert_eq(reg.entity_from_index(0), 0);
    cr_assert_eq(reg.entity_from_index(1), 1);
    cr_assert_eq(reg.entity_from_index(2), 2);
    cr_assert_eq(reg.get_components<int>()[0].value(), 10);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
    cr_assert_eq(reg.get_components<int>()[1].value(), 11);
    cr_assert_eq(reg.get_components<char>()[1].value(), 'b');
    cr_assert_eq(reg.get_components<int>()[2].value(), 12);
    cr_assert_eq(reg.get_components<char>()[2].value(), 'c');

    reg.kill_entity(reg.entity_from_index(1));
    cr_assert_eq(reg.entity_from_index(0), 0);
    cr_assert_throw(reg.entity_from_index(1), std::runtime_error);
    cr_assert_eq(reg.entity_from_index(2), 2);
    cr_assert_eq(reg.get_components<int>()[0].value(), 10);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
    cr_assert_eq(reg.get_components<int>()[1].has_value(), false);
    cr_assert_eq(reg.get_components<char>()[1].has_value(), false);
    cr_assert_eq(reg.get_components<int>()[2].value(), 12);
    cr_assert_eq(reg.get_components<char>()[2].value(), 'c');

    reg.spawn_entity();

    cr_assert_eq(reg.entity_from_index(0), 0);
    cr_assert_eq(reg.entity_from_index(1), 1);
    cr_assert_eq(reg.entity_from_index(2), 2);
    cr_assert_eq(reg.get_components<int>()[0].value(), 10);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
    cr_assert_eq(reg.get_components<int>()[1].has_value(), false);
    cr_assert_eq(reg.get_components<char>()[1].has_value(), false);
    cr_assert_eq(reg.get_components<int>()[2].value(), 12);
    cr_assert_eq(reg.get_components<char>()[2].value(), 'c');

    reg.add_component<int>(reg.entity_from_index(1), 11);
    reg.add_component<char>(reg.entity_from_index(1), 'b');

    cr_assert_eq(reg.entity_from_index(0), 0);
    cr_assert_eq(reg.entity_from_index(1), 1);
    cr_assert_eq(reg.entity_from_index(2), 2);
    cr_assert_eq(reg.get_components<int>()[0].value(), 10);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
    cr_assert_eq(reg.get_components<int>()[1].value(), 11);
    cr_assert_eq(reg.get_components<char>()[1].value(), 'b');
    cr_assert_eq(reg.get_components<int>()[2].value(), 12);
    cr_assert_eq(reg.get_components<char>()[2].value(), 'c');
}

Test(Registry, basic_add_component)
{
    Registry reg;

    reg.register_component<int>();
    reg.register_component<char>();
    reg.spawn_entity();
    reg.add_component<int>(reg.entity_from_index(0), 10);
    reg.add_component<char>(reg.entity_from_index(0), 'a');
    cr_assert_eq(reg.get_components<int>()[0].value(), 10);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
}

Test(Registry, advanced_add_component)
{
    Registry reg;

    reg.register_component<int>();
    reg.register_component<char>();
    reg.register_component<double>();
    reg.spawn_entity();
    reg.spawn_entity();
    reg.add_component<int>(reg.entity_from_index(0), 10);
    reg.add_component<double>(reg.entity_from_index(0), 15);
    reg.add_component<char>(reg.entity_from_index(0), 'a');
    reg.add_component<int>(reg.entity_from_index(1), 11);
    cr_assert_eq(reg.get_components<int>()[0].value(), 10);
    cr_assert_eq(reg.get_components<double>()[0].value(), 15);
    cr_assert_eq(reg.get_components<int>()[1].value(), 11);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
    cr_assert_eq(reg.get_components<char>()[1].has_value(), false);
}

Test(Registry, basic_emplace_component)
{
    Registry reg;

    reg.register_component<int>();
    reg.register_component<char>();
    reg.register_component<double>();
    reg.spawn_entity();
    reg.emplace_component<int>(reg.entity_from_index(0), 10);
    reg.emplace_component<char>(reg.entity_from_index(0), 'a');
    reg.emplace_component<double>(reg.entity_from_index(0), 10);
    cr_assert_eq(reg.get_components<int>()[0].value(), 10);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
    cr_assert_eq(reg.get_components<double>()[0].value(), 10);
}

Test(Registry, basic_remove_component)
{
    Registry reg;

    reg.register_component<int>();
    reg.register_component<char>();
    reg.register_component<double>();
    reg.spawn_entity();
    reg.emplace_component<int>(reg.entity_from_index(0), 10);
    reg.emplace_component<char>(reg.entity_from_index(0), 'a');
    reg.emplace_component<double>(reg.entity_from_index(0), 10);
    reg.remove_component<int>(reg.entity_from_index(0));
    cr_assert_eq(reg.get_components<int>()[0].has_value(), false);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
    cr_assert_eq(reg.get_components<double>()[0].has_value(), true);
}

Test(Registry, advanced_remove_component)
{
    Registry reg;

    reg.register_component<int>();
    reg.register_component<char>();
    reg.register_component<double>();
    reg.spawn_entity();
    reg.emplace_component<int>(reg.entity_from_index(0), 10);
    reg.emplace_component<char>(reg.entity_from_index(0), 'a');
    reg.emplace_component<double>(reg.entity_from_index(0), 10);
    reg.remove_component<int>(reg.entity_from_index(0));
    cr_assert_eq(reg.get_components<int>()[0].has_value(), false);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
    cr_assert_eq(reg.get_components<double>()[0].has_value(), true);
    reg.add_component<int>(reg.entity_from_index(0), 10);
    cr_assert_eq(reg.get_components<int>()[0].value(), 10);
}

Test(Registry, advanced_entity_manager)
{
    Registry reg;

    reg.register_component<int>();
    reg.register_component<char>();
    reg.register_component<double>();
    reg.spawn_entity();
    reg.spawn_entity();
    reg.emplace_component<int>(reg.entity_from_index(0), 10);
    reg.emplace_component<char>(reg.entity_from_index(0), 'a');
    reg.emplace_component<double>(reg.entity_from_index(0), 10);
    reg.remove_component<int>(reg.entity_from_index(0));

    reg.emplace_component<int>(reg.entity_from_index(1), 11);
    reg.emplace_component<char>(reg.entity_from_index(1), 'b');
    reg.emplace_component<double>(reg.entity_from_index(1), 11);
    reg.remove_component<int>(reg.entity_from_index(1));

    cr_assert_eq(reg.get_components<int>()[0].has_value(), false);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
    cr_assert_eq(reg.get_components<double>()[0].has_value(), true);
    reg.add_component<int>(reg.entity_from_index(0), 10);
    cr_assert_eq(reg.get_components<int>()[0].value(), 10);

    cr_assert_eq(reg.get_components<int>()[1].has_value(), false);
    cr_assert_eq(reg.get_components<char>()[1].value(), 'b');
    cr_assert_eq(reg.get_components<double>()[1].has_value(), true);
    reg.add_component<int>(reg.entity_from_index(1), 11);
    cr_assert_eq(reg.get_components<int>()[1].value(), 11);
    reg.kill_entity(reg.entity_from_index(0));

    cr_assert_eq(reg.get_components<int>()[0].has_value(), false);
    cr_assert_eq(reg.get_components<double>()[0].has_value(), false);
    cr_assert_eq(reg.get_components<char>()[0].has_value(), false);
    cr_assert_throw(reg.entity_from_index(0), std::runtime_error);
    reg.spawn_entity();
    cr_assert_eq(reg.entity_from_index(0), 0);

    reg.emplace_component<int>(reg.entity_from_index(0), 10);
    reg.emplace_component<char>(reg.entity_from_index(0), 'a');
    reg.emplace_component<double>(reg.entity_from_index(0), 10);
    reg.remove_component<int>(reg.entity_from_index(0));

    cr_assert_eq(reg.get_components<int>()[0].has_value(), false);
    cr_assert_eq(reg.get_components<char>()[0].value(), 'a');
    cr_assert_eq(reg.get_components<double>()[0].has_value(), true);
    reg.add_component<int>(reg.entity_from_index(0), 10);
    cr_assert_eq(reg.get_components<int>()[0].value(), 10);
}

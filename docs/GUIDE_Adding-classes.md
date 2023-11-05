# Guide for Adding Classes to the Game

This guide will walk you through the process of adding new classes to the game using the Entity-Component-System (ECS) architecture.

## Prerequisites
Before you start, make sure you have a good understanding of C++ programming and the ECS architecture used in this game.

Familiarize yourself with the existing codebase and the EntityClass structure.

## Step 1: Understand the EntityClass Structure
The `EntityClass` structure contains various attributes defining an entity, such as asset names, positions, health, damage, shooting patterns, and more.

Make sure you understand the purpose of each attribute before creating a new class.

## Step 2: Create a New EntityClass
To add a new class to the game, follow these steps:

1. **Define the EntityClass Enum:**
   In the `Parser.cpp` file, add a new enum value for your class.
   This is needed if you want to be able to add your new class to the game via the default mode that uses a parser.

   For example:
   ```cpp
   std::map<std::string, EntityClasses> entityClassesMap = {
        {"NUGO", EntityClasses::NUGO},
        [...],
        {"MY_NEW_CLASS", EntityClasses::MY_NEW_CLASS}
    };
   ```

2. **Implement the EntityClass:**
   In the `EntityClass.cpp` file, use the `EntityClassFactory::CreateEntityClass` function to create your new class. Provide appropriate values for each attribute based on the characteristics of your class.

   If you need new assets, take a look at the guide for [Adding Assets](GUIDE_Adding-assets.md).

   Example:
   ```cpp
   case EntityClasses::NUGO:
      return EntityClass("SpaceShips.gif", "PBulletNugo.png", Component::Position(102, 57), sf::IntRect(0, 2, 34, 16), 150, 15, 750, 1, ShootingPattern::LINEAR);
   [...]
   case EntityClasses::MY_NEW_CLASS:
      return EntityClass("MyAsset.png", "MyProjectile.png", Component::Position(50, 50), sf::IntRect(0, 0, 32, 32), 100, 20, 500, 3, ShootingPattern::LINEAR);
   default:
      return EntityClass("SpaceShips.gif", "PBulletNugo.png", Component::Position(102, 57), sf::IntRect(0, 2, 34, 16), 100, 5, 500, 5, ShootingPattern::LINEAR);
   ```


## Step 3: Testing and Debugging
After adding your new class, it's crucial to test it thoroughly to ensure it behaves as expected.

Verify the visuals, movements, shooting patterns, and collisions associated with your class. Debug any issues that arise during testing.

## Congratulations!

Congratulations! You have successfully added a new class to the R-Type game.

You can now use your new class in the game.
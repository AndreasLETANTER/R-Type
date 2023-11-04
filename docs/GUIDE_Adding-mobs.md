# Guide for Adding Mobs to the Game

This guide will walk you through the process of adding new mobs to the game using the Entity-Component-System (ECS) architecture.

## Step 1:
Add your new mob using the [EntityClass system](GUIDE_Adding-classes.md).

## Step 2:
Make your mob available to the mob you want.

- Endless mode:
Simply add you mob in the `WaveSystem.cpp`` file.
```cpp
m_enemy_vector.push_back(Component::EntityClassFactory::CreateEntityClass(EntityClasses::MY_NEW_CLASS));
```

- default mode:

[Add your mob to your level file](GUIDE_Adding-levels(default-mode).md).
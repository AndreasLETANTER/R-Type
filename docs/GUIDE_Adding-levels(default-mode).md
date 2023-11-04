# Guide for Adding Levels to the Game (default mode)
This guide will walk you through the process of adding new levels to the default mode of the game.

## Step 1: Create a new level file
You'll have to create a new level file in the `assets/levels` folder.

It has to be a `.yaml` file.

## Step 2: Add params of your level

You need to add the params of your level. For example:

```yaml
params:
{
    level = 1;
    resolution = { width = 1920; height = 1080; };
};
```

## Step 3: Add entities of your level

1. **Add backgrounds:**
You need to add two time the same background so that it can make a beautiful scrolling background. For example:

```yaml
entities: {
    backgrounds = (
        {
            id = 0;
            assetName = "SpaceBackground.png";
            position = { x = 0; y = 0; };
            scale = { x = 1920; y = 1080; };
            rect = { x = 0; y = 0; width = 300; height = 207; };
            offsetLimit = { x = -5700; y = 0; };
            pauseX = 0;
        },
        {
            id = 1;
            assetName = "SpaceBackground.png";
            position = { x = 5700; y = 0; };
            scale = { x = 1920; y = 1080; };
            rect = { x = 0; y = 0; width = 300; height = 207; };
            offsetLimit = { x = 0; y = 0; };
            pauseX = 0;
        }
    );
};
```

2. **Add obstacles:**
You need to add obstacles to your level. For example:

```yaml
    obstacles = (
        {
            id = 2;
            assetName = "GreyRobotObstacle.gif";
            projectileAssetName = "BulletSprite.png";
            position = { x = 2000; y = 925; };
            scale = { x = 170; y = 155; };
            rect = { x = 0; y = 1; width = 34; height = 31; };
            rotation = 0;
            health = 20;
            pauseX = 1500;
        }
    );
```

3. **Add enemies:**

You need to add enemies to your level. For example:

```yaml
    enemies = (
        {
            id = 3;
            class = "MOB_ORANGE_CRAB";
            position = { x = 1450; y = 600; };
            autoMove = { x = 1450; y = 100; };
        },
        {
            id = 4;
            class = "MOB_YELLOW_POPCORN";
            position = { x = 1200; y = 700; };
            autoMove = { x = 1200; y = 200; };
        }
```

The enemies are built using classes.
If you want to add a new type of enemy, you need a [new class](GUIDE_Adding-classes.md).

## Step 4: Add your level to the default mode
You need to add your compiled level content to the DefaultMode `init` method in the `DefaultMode.cpp` file.

For example:
```cpp
std::vector<std::string> filePath = {Level1Config};
```

The name will always be the name of your file with Config added to the end. It corresponds to the compile version of your level that you can find in your build folder.
This is done in order to let people move the project's binary around without having to move the assets folder.

## Congratulations!

Congratulations! You have successfully added a new level to the R-Type game.
Player(s) will be added automatically.

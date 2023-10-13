Creating Maps in our R-Type with Libconfig

In our game, maps play a crucial role in providing immersive gameplay experiences. This guide explains how to create maps using the Libconfig library, a powerful and flexible configuration file format.

Map Configuration

Maps are defined using Libconfig configuration files.They need to be placed in the assets/levels directory of the game.
These configuration files contain key information about the map, such as terrain, objects, and player spawn points.
Creating Maps

Follow these steps to create a new map :

Create a Configuration File: Start by creating a file in the assets/levels directory with a .yaml extension.

Edit the Map: Use a text editor to edit the configuration file. Specify the terrain, objects, and spawn points as needed.

two points are needed to create a map :
- params:
```bash
params:
{
    level = 1;
    resolution = { width = 1920; height = 1080; };
};
```

- entities:

Entities can be of different types :
- backgrounds
- players
- obstacles
- enemies

Example of a background entity :
```bash
entities:
{
    backgrounds = (
        { id = 1;
        name = "Space_Background.png";
        position = { x = 0; y = 0; };
        scale = { x = 1; y = 1; };
        rect = { x = 0; y = 0; width = 1920; height = 1080; };
        offsetLimit = { x = -400; y = -400; };
        }
    );
};
```

Example of a player entity :
```bash
entities:
{
    players = (
        { id = 1;
        assetName = "SpaceShips.gif";
        projectileAssetName = "SpaceShips.gif";
        position = { x = 100; y = 100; };
        scale = { x = 1; y = 1; };
        rect = { x = 0; y = 0; width = 100; height = 100; };
        health = 100;
        }
    );
};
```

Example of an obstacle entity :
```bash
entities:
{
    obstacles = (
        { id = 1;
        assetName = "SpaceShips.gif";
        projectileAssetName = "BurpTemporaryBullet.png";
        position = { x = 100; y = 100; };
        scale = { x = 1; y = 1; };
        rect = { x = 0; y = 0; width = 100; height = 100; };
        rotation = 0;
        health = 100;
        }
    );
};
```

Example of an enemy entity :
```bash
entities:
{
    enemies = (
        { id = 1;
        assetName = "SpaceShips.gif";
        projectileAssetName = "BurpTemporaryBullet.png";
        position = { x = 100; y = 100; };
        scale = { x = 1; y = 1; };
        rect = { x = 0; y = 0; width = 100; height = 100; };
        rotation = 0;
        health = 10;
        }
    );
};
```

Creating maps using Libconfig allows for flexibility and customization. With a well-structured configuration file, you can design intricate and captivating maps to enhance the gameplay experience.

For more detailed information on map creation and advanced features, refer to our official documentation or contact our support team.


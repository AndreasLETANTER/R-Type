# Guide for Adding assets to the game

This guide will walk you through the process of adding new assets to the game.

## Step 1 : Understand the Asset Structure

The `Asset` class contains map for various types of assets:
```cpp
std::map<std::string, std::shared_ptr<sf::Texture>> m_textures;
std::map<std::string, sf::Font> m_fonts;
std::map<std::string, std::shared_ptr<sf::Music>> m_musics;
std::map<std::string, std::shared_ptr<sf::SoundBuffer>> m_sound_buffers;
std::map<std::string, std::shared_ptr<sf::Sound>> m_sounds;
```

## Step 2 : Add a new asset

1. **Add you actual asset file to the assets folder**

2. **Add you asset to the CMakeLists.txt file**

```cpp
set(ASSETS_FILES
    assets/SpaceBackground.png
    [...]
    assets/MyNewAsset.png
)
```

3. **Add you asset to the Asset class**

You need to load your asset in the assets constructor.

- images:
```cpp
this->load_texture("MyNewImage", "assets/MyNewImage.png");
``````

- fonts:
```cpp
this->load_font("MyNewFont", "assets/MyNewFont.ttf");
``````

- musics:
```cpp
this->load_music("MyNewMusic", "assets/MyNewMusic.ogg");
``````

- sounds:
```cpp
this->load_sound_buffer("MyNewSound", "assets/MyNewSound.wav");
this->load_sound("MyNewSound", "assets/MyNewSound.wav");
```

## Congrutulations!

Congratulations! You have successfully added a new asset to the R-Type game.

You can now use your new asset in the game.
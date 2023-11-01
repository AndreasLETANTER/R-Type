/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Assets
*/

#include "ECS/Assets/Assets.hpp"
#include <iostream>

Assets::Assets()
{
    this->load_texture("PBulletNugo.png", "assets/PBulletNugo.png");
    this->load_texture("PBulletAndreas.png", "assets/PBulletAndreas.png");
    this->load_texture("PBulletEliot.png", "assets/PBulletEliot.png");
    this->load_texture("PBulletLouis.png", "assets/PBulletLouis.png");
    this->load_texture("PBulletHugo.png", "assets/PBulletHugo.png");
    this->load_texture("EBulletOrangeCrab.png", "assets/EBulletOrangeCrab.png");
    this->load_texture("EBulletYellowPopcorn.png", "assets/EBulletYellowPopcorn.png");
    this->load_texture("EBulletGreenPlant.png", "assets/EBulletGreenPlant.png");
    this->load_texture("EBulletBlueD.png", "assets/EBulletBlueD.png");
    this->load_texture("BulletSpriteMonster.png", "assets/BulletSpriteMonster.png");
    this->load_texture("GreyRobotObstacle.gif", "assets/GreyRobotObstacle.gif");
    this->load_texture("OrangeCrabEnemy.gif", "assets/OrangeCrabEnemy.gif");
    this->load_texture("GreenPlantEnemy.gif", "assets/GreenPlantEnemy.gif");
    this->load_texture("BlueDEnemy.gif", "assets/BlueDEnemy.gif");
    this->load_texture("SpaceBackground.png", "assets/SpaceBackground.png");
    this->load_texture("SpaceShips.gif", "assets/SpaceShips.gif");
    this->load_texture("YellowPopcornEnemy.gif", "assets/YellowPopcornEnemy.gif");

    this->load_font("font.ttf", "assets/font.ttf");

    this->load_music("MenuMusic", "assets/MenuMusic.wav");
    this->load_music("BackgroundMusic", "assets/BackgroundMusic.wav");

    this->load_sound_buffer("PlugDeathSoundEffect", "assets/PlugDeathSoundEffect.wav");
    this->load_sound("PlugDeathSoundEffect", "assets/PlugDeathSoundEffect.wav");
    this->load_sound_buffer("LaserSoundEffect", "assets/LaserSoundEffect.wav");
    this->load_sound("LaserSoundEffect", "assets/LaserSoundEffect.wav");
    this->load_sound_buffer("RizzPowerUpSoundEffect", "assets/RizzPowerUpSoundEffect.wav");
    this->load_sound("RizzPowerUpSoundEffect", "assets/RizzPowerUpSoundEffect.wav");
}

std::shared_ptr<sf::Texture> &Assets::get_texture(const std::string &name)
{
    if (m_textures.find(name) == m_textures.end()) {
        throw std::runtime_error{"Texture: " + name + " not found"};
    }
    return m_textures[name];
}

sf::Font &Assets::get_font(const std::string &name)
{
    if (m_fonts.find(name) == m_fonts.end()) {
        throw std::runtime_error{"Font: " + name + " not found"};
    }
    return m_fonts[name];
}

std::shared_ptr<sf::Music> &Assets::get_music(const std::string &name)
{
    if (m_musics.find(name) == m_musics.end()) {
        throw std::runtime_error{"Music: " + name + " not found"};
    }
    return m_musics[name];
}

std::shared_ptr<sf::SoundBuffer> &Assets::get_sound_buffer(const std::string &name)
{
    if (m_sound_buffers.find(name) == m_sound_buffers.end()) {
        throw std::runtime_error{"Sound buffer: " + name + " not found"};
    }
    return m_sound_buffers[name];
}

std::shared_ptr<sf::Sound> &Assets::get_sound(const std::string &name)
{
    if (m_sounds.find(name) == m_sounds.end()) {
        throw std::runtime_error{"Sound: " + name + " not found"};
    }
    return m_sounds[name];
}

void Assets::load_texture(const std::string &name, const std::string &path)
{
    auto texture = m_fs.open(path);
    if (texture.size() == 0) {
        throw std::runtime_error{"Texture file: " + path + " not found"};
    }
    m_textures[name] = std::make_shared<sf::Texture>();
    m_textures[name]->loadFromMemory(texture.begin(), texture.size());
}

void Assets::load_font(const std::string &name, const std::string &path)
{
    auto font = m_fs.open(path);
    if (font.size() == 0) {
        throw std::runtime_error{"Font file " + path + " not found"};
    }
    m_fonts[name] = sf::Font();
    m_fonts[name].loadFromMemory(font.begin(), font.size());
}

void Assets::load_music(const std::string &name, const std::string &path)
{
    auto music = m_fs.open(path);
    if (music.size() == 0) {
        throw std::runtime_error{"Music file " + path + " not found"};
    }
    m_musics[name] = std::make_shared<sf::Music>();
    m_musics[name]->openFromMemory(music.begin(), music.size());
}

void Assets::load_sound_buffer(const std::string &name, const std::string &path)
{
    auto sound_buffer = m_fs.open(path);
    if (sound_buffer.size() == 0) {
        throw std::runtime_error{"Sound buffer file " + path + " not found"};
    }
    m_sound_buffers[name] = std::make_shared<sf::SoundBuffer>();
    m_sound_buffers[name]->loadFromMemory(sound_buffer.begin(), sound_buffer.size());
}

void Assets::load_sound(const std::string &name, const std::string &path)
{
    auto sound = m_fs.open(path);
    if (sound.size() == 0) {
        throw std::runtime_error{"Sound file " + path + " not found"};
    }
    m_sounds[name] = std::make_shared<sf::Sound>();
    m_sounds[name]->setBuffer(*m_sound_buffers[name]);
    m_sounds[name]->setVolume(20);
}

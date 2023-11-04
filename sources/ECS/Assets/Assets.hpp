/*
** EPITECH PROJECT, 2023
** MIRROR_R-Type
** File description:
** Assets
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

#include <cmrc/cmrc.hpp>

CMRC_DECLARE(Assets);

/**
 * @brief The Assets class is used to store all the assets of the game.
 */
class Assets {
    public:
        /**
         * @brief Constructs an Assets object, loads all the assets.
         */
        Assets();

        /**
         * @brief Destroys an Assets object.
          */
        ~Assets() = default;

        /**
         * @brief Retrieves a texture by name.
         *
         * @param name The name of the texture to retrieve.
         * @return A reference to the texture.
         */
        std::shared_ptr<sf::Texture> &get_texture(const std::string &name);

        /**
         * @brief Retrieves a font by name.
         *
         * @param name The name of the font to retrieve.
         * @return A reference to the font.
         */
        sf::Font &get_font(const std::string &name);

        /**
         * @brief Retrieves a music by name.
         *
         * @param name The name of the music to retrieve.
         * @return A reference to the music.
         */
        std::shared_ptr<sf::Music> &get_music(const std::string &name);

        /**
         * @brief Retrieves a sound buffer by name.
         *
         * @param name The name of the sound buffer to retrieve.
         * @return A reference to the sound buffer.
         */
        std::shared_ptr<sf::SoundBuffer> &get_sound_buffer(const std::string &name);

        /**
         * @brief Retrieves a sound by name.
         *
         * @param name The name of the sound to retrieve.
         * @return A reference to the sound.
         */
        std::shared_ptr<sf::Sound> &get_sound(const std::string &name);

        /**
         * @brief Loads a texture from a file.
         *
         * @param name The name of the texture.
         * @param path The path to the texture.
         */
        void load_texture(const std::string &name, const std::string &path);

        /**
         * @brief Loads a font from a file.
         *
         * @param name The name of the font.
         * @param path The path to the font.
         */
        void load_font(const std::string &name, const std::string &path);

        /**
         * @brief Loads a music by name.
         *
         * @param name The name of the music to retrieve.
         * @return A reference to the music.
         */
        void load_music(const std::string &name, const std::string &path);

        /**
         * @brief Loads a sound buffer by name.
         *
         * @param name The name of the sound buffer to retrieve.
         * @return A reference to the sound buffer.
         */
        void load_sound_buffer(const std::string &name, const std::string &path);

        /**
         * @brief Loads a sound by name.
         *
         * @param name The name of the sound to retrieve.
         * @return A reference to the sound.
         */
        void load_sound(const std::string &name, const std::string &path);
    private:
        std::map<std::string, std::shared_ptr<sf::Texture>> m_textures;
        std::map<std::string, sf::Font> m_fonts;
        std::map<std::string, std::shared_ptr<sf::Music>> m_musics;
        std::map<std::string, std::shared_ptr<sf::SoundBuffer>> m_sound_buffers;
        std::map<std::string, std::shared_ptr<sf::Sound>> m_sounds;
        cmrc::embedded_filesystem m_fs = cmrc::Assets::get_filesystem();
};

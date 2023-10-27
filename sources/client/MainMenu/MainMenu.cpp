/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MainMenu
*/

#include <iostream>

#include "client/MainMenu/MainMenu.hpp"
#include "MainMenu.hpp"

MainMenu::MainMenu::MainMenu(sf::RenderWindow &window, Assets &assets,
    Registry &registry):
    m_window(window), m_assets(assets), m_registry(registry)
{
    sf::Vector2u windowSize = m_window.getSize();
    double buttonWidthRatio = 8;
    double buttonHeightRatio = 12;
    sf::Vector2f pos = sf::Vector2f((windowSize.x / 2) - ((windowSize.x / buttonWidthRatio) / 2),
        (windowSize.y / 8));
    m_font = m_assets.get_font("font.ttf");

    pos.y += 400;
    pos.x -= 200;
    auto playButton = m_buttons.emplace_back();
    auto text2 = m_texts.emplace_back();
    auto &m_bools = this->m_bools;
    auto &m_buttonTypes = this->m_buttonTypes;
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    m_texts[0].setFont(m_font);
    m_texts[0].setString("TCP Port : 8080");
    m_texts[0].setCharacterSize(28);
    m_texts[0].setFillColor(sf::Color::White);
    m_texts[0].setPosition(pos.x + 15, pos.y + 15);
    playButton.setButtonPosition(pos);
    playButton.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio));
    playButton.setButtonColor(sf::Color::Transparent);
    playButton.setButtonOutlineColor(sf::Color::White);
    playButton.setButtonOutlineThickness(5);
    playButton.setButtonHoverColor(sf::Color::Transparent);
    playButton.setButtonHoverOutlineColor(sf::Color::Green);
    playButton.setCallback([this, &m_bools, &playButton]() {
        resetAndSetSelectedButton(0);
    });
    m_texts.push_back(std::move(text2));
    m_buttons.push_back(std::move(playButton));

    pos.x += 400;
    auto udpPortButton = m_buttons.emplace_back();
    auto text3 = m_texts.emplace_back();
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    m_texts[1].setFont(m_font);
    m_texts[1].setString("UDP Port : 4242");
    m_texts[1].setCharacterSize(28);
    m_texts[1].setFillColor(sf::Color::White);
    m_texts[1].setPosition(pos.x + 15, pos.y + 15);
    udpPortButton.setButtonPosition(pos);
    udpPortButton.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio));
    udpPortButton.setButtonColor(sf::Color::Transparent);
    udpPortButton.setButtonOutlineColor(sf::Color::White);
    udpPortButton.setButtonOutlineThickness(5);
    udpPortButton.setButtonHoverColor(sf::Color::Transparent);
    udpPortButton.setButtonHoverOutlineColor(sf::Color::Green);
    udpPortButton.setCallback([this, &m_bools]() {
        resetAndSetSelectedButton(1);
    });
    m_texts.push_back(std::move(text3));
    m_buttons.push_back(std::move(udpPortButton));

    pos.x -= 250;
    pos.y -= 150;
    auto ipPortButton = m_buttons.emplace_back();
    auto text4 = m_texts.emplace_back();
    m_bools.push_back(false);
    m_buttonTypes.push_back(ADDRESS);
    m_texts[2].setFont(m_font);
    m_texts[2].setString("IP Address : 127.0.0.1");
    m_texts[2].setCharacterSize(28);
    m_texts[2].setFillColor(sf::Color::White);
    m_texts[2].setPosition(pos.x + 15, pos.y + 15);
    ipPortButton.setButtonPosition(pos);
    ipPortButton.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio / 1.5, buttonHeightRatio));
    ipPortButton.setButtonColor(sf::Color::Transparent);
    ipPortButton.setButtonOutlineColor(sf::Color::White);
    ipPortButton.setButtonOutlineThickness(5);
    ipPortButton.setButtonHoverColor(sf::Color::Transparent);
    ipPortButton.setButtonHoverOutlineColor(sf::Color::Green);
    ipPortButton.setCallback([this, &m_bools]() {
            resetAndSetSelectedButton(2);
        });
    m_texts.push_back(std::move(text4));
    m_buttons.push_back(std::move(ipPortButton));
}


char real_chars[sf::Keyboard::KeyCount] = {
    // Printable characters
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    '0', '1', '2', '3', '4', '5', '5', '7', '8', '9',
    0, 0, '.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    '4', 0, 0, 0, 0, '6', 0, 0, 0, 0, 0, 0, 0,

    // Non-printable characters
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0
  };
void MainMenu::draw()
{
    int i = 0;

    for (auto &button : m_buttons) {
        button.draw(m_window);
        for (auto &key : m_keys) {
            for (size_t y = 0; y < m_bools.size(); y++) {
                if (m_bools[y] == true) {
                    std::string str = m_texts[y].getString();
                    if (key == sf::Keyboard::BackSpace) {
                        if ((str.size() > 11 && m_buttonTypes[y] == PORT) || (str.size() > 13 && m_buttonTypes[y] == ADDRESS))
                            str.pop_back();
                        m_texts[y].setString(str);
                    } else if (real_chars[key] != 0 && ((str.size() < 16 && m_buttonTypes[y] == PORT) || (str.size() < 28 && m_buttonTypes[y] == ADDRESS))) {
                        if (m_buttonTypes[y] == PORT && real_chars[key] == '.')
                            continue;
                        str += real_chars[key];
                        m_texts[y].setString(str);
                    } else if (key == sf::Keyboard::Delete) {
                        while ((str.size() > 11 && m_buttonTypes[y] == PORT) || (str.size() > 13 && m_buttonTypes[y] == ADDRESS))
                            str.pop_back();
                        m_texts[y].setString(str);
                    } else if (key == sf::Keyboard::Enter) {
                        m_bools[y] = false;
                    } else if (key == sf::Keyboard::Escape) {
                        m_bools[y] = false;
                    }
                }
            }
        }
        m_keys.clear();
        if  (m_bools[i] == true) {
            m_texts[i].setFillColor(sf::Color::Green);
        } else {
            m_texts[i].setFillColor(sf::Color::White);
        }
        m_window.draw(m_texts[i]);
        i++;
    }
}

void MainMenu::update()
{
    for (auto &button : m_buttons) {
        button.update(m_window);
    }
}

void MainMenu::resize()
{
    //sf::Vector2u windowSize = m_window.getSize();
    //double buttonWidthRatio = 5;
    //double buttonHeightRatio = 10;
    //double textRatio = 15;
    //double buttonWidth = windowSize.x / buttonWidthRatio;
    //double buttonHeight = windowSize.y / buttonHeightRatio;
    //double spacing = windowSize.y / 20;
    //double xPos = (windowSize.x - buttonWidth) / 2;
    //double yPos = (windowSize.y - (2 * buttonHeight + spacing)) / 2;

    /*m_buttons[0].resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
    yPos += buttonHeight + spacing;
    m_buttons[1].resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);*/
}
void MainMenu::resetAndSetSelectedButton(unsigned int index)
{
    for (size_t i = 0; i < m_bools.size(); i++)
        m_bools[i] = false;
    m_bools[index] = !m_bools[index];
}

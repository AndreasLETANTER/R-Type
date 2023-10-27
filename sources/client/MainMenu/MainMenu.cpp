/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MainMenu
*/

#include <iostream>

#include "client/MainMenu/MainMenu.hpp"

MainMenu::MainMenu::MainMenu(sf::RenderWindow &window, Assets &assets,
    Registry &registry):
    m_window(window), m_assets(assets), m_registry(registry)
{
    sf::Vector2u windowSize = m_window.getSize();
    double buttonWidthRatio = 8;
    double buttonHeightRatio = 12;
    double textRatio = 24;
    sf::Vector2f pos = sf::Vector2f((windowSize.x / 2) - ((windowSize.x / buttonWidthRatio) / 2),
        (windowSize.y / 8));
    m_font = m_assets.get_font("font.ttf");

    pos.y += 400;
    pos.x -= 200;
    auto playButton = m_buttons.emplace_back();
    auto text2 = m_texts.emplace_back();
    auto &m_bools = this->m_bools;
    m_bools.push_back(false);
    m_texts[0].setFont(m_font);
    m_texts[0].setString("TCP Port : 8080");
    m_texts[0].setCharacterSize(28);
    m_texts[0].setFillColor(sf::Color::White);
    pos.y += 15;
    pos.x += 15;
    m_texts[0].setPosition(pos);
    pos.y -= 15;
    pos.x -= 15;
    playButton.setButtonPosition(pos);
    playButton.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio));
    playButton.setButtonColor(sf::Color::Transparent);
    playButton.setButtonOutlineColor(sf::Color::White);
    playButton.setButtonOutlineThickness(5);
    playButton.setButtonHoverColor(sf::Color::Transparent);
    playButton.setButtonHoverOutlineColor(sf::Color::Green);
    playButton.setTextSize(windowSize, textRatio);
    playButton.setTextFont(m_font);
    playButton.setTextPosition(TextButton::CENTER, TextButton::MIDDLE);
    playButton.setTextColor(sf::Color::White);
    playButton.setTextHoverColor(sf::Color::Green);
    playButton.setCallback([this, &m_bools, &playButton]() {
        std::cout << "tcp Clicked" << std::endl;
        for (size_t i = 0; i < m_bools.size(); i++)
            m_bools[i] = false;
        m_bools[0] = !m_bools[0];
    });
    m_texts.push_back(std::move(text2));
    m_buttons.push_back(std::move(playButton));

    pos.x += 400;
    auto udpPortButton = m_buttons.emplace_back();
    auto text3 = m_texts.emplace_back();
    m_bools.push_back(false);
    m_texts[1].setFont(m_font);
    m_texts[1].setString("Udp Port : 4242");
    m_texts[1].setCharacterSize(28);
    m_texts[1].setFillColor(sf::Color::White);
    pos.y += 15;
    pos.x += 15;
    m_texts[1].setPosition(pos);
    pos.y -= 15;
    pos.x -= 15;
    udpPortButton.setButtonPosition(pos);
    udpPortButton.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio));
    udpPortButton.setButtonColor(sf::Color::Transparent);
    udpPortButton.setButtonOutlineColor(sf::Color::White);
    udpPortButton.setButtonOutlineThickness(5);
    udpPortButton.setButtonHoverColor(sf::Color::Transparent);
    udpPortButton.setButtonHoverOutlineColor(sf::Color::Green);
    udpPortButton.setTextString("TCP Port : 8080");
    udpPortButton.setTextSize(windowSize, textRatio);
    udpPortButton.setTextFont(m_font);
    udpPortButton.setTextPosition(TextButton::CENTER, TextButton::MIDDLE);
    udpPortButton.setTextColor(sf::Color::White);
    udpPortButton.setTextHoverColor(sf::Color::Green);
    udpPortButton.setCallback([this, &m_bools]() {
            std::cout << "udp Clicked" << std::endl;
            for (size_t i = 0; i < m_bools.size(); i++)
                m_bools[i] = false;
            m_bools[1] = !m_bools[1];
        });
    m_texts.push_back(std::move(text3));
    m_buttons.push_back(std::move(udpPortButton));

    /*pos.y += 150;
    pos.x -= 200;
    auto ipAddressButton = m_buttons.emplace_back();
    ipAddressButton.setButtonPosition(pos);
    ipAddressButton.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio));
    ipAddressButton.setButtonColor(sf::Color::Transparent);
    ipAddressButton.setButtonOutlineColor(sf::Color::White);
    ipAddressButton.setButtonOutlineThickness(5);
    ipAddressButton.setButtonHoverColor(sf::Color::Transparent);
    ipAddressButton.setButtonHoverOutlineColor(sf::Color::Green);
    ipAddressButton.setTextString("IP Address");
    ipAddressButton.setTextSize(windowSize, textRatio);
    ipAddressButton.setTextFont(m_font);
    ipAddressButton.setTextPosition(TextButton::CENTER, TextButton::MIDDLE);
    ipAddressButton.setTextColor(sf::Color::White);
    ipAddressButton.setTextHoverColor(sf::Color::Green);
    ipAddressButton.setCallback([this]() {
        std::cout << "ip clicked" << std::endl;
    });*/
}


char real_chars[sf::Keyboard::KeyCount] = {
    // Printable characters
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    '0', '1', '2', '3', '4', '5', '5', '7', '8', '9',
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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
                        if (str.size() > 11)
                            str.pop_back();
                        m_texts[y].setString(str);
                    } else if (str.size() < 16 && real_chars[key] != 0) {
                        str += real_chars[key];
                        m_texts[y].setString(str);
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

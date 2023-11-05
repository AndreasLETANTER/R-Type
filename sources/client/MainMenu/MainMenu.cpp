/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MainMenu
*/

#include <iostream>

#include "client/MainMenu/MainMenu.hpp"
#include "utils/HandleArgument/HandleArgument.hpp"
#include "MainMenu.hpp"
#include "ECS/Systems/DrawSystem/DrawSystem.hpp"
#include "ECS/Systems/ScrollSystem/ScrollSystem.hpp"
#include "ECS/Systems/PositionSystem/PositionSystem.hpp"
#include "ECS/Components/Drawable.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Scroll.hpp"

MainMenu::MainMenu(sf::RenderWindow &window, Assets &assets, Registry &registry):
    m_window(window), m_assets(assets), m_registry(registry)
{
    m_keyMap[sf::Keyboard::Scan::Num0] = '0';
    m_keyMap[sf::Keyboard::Scan::Num1] = '1';
    m_keyMap[sf::Keyboard::Scan::Num2] = '2';
    m_keyMap[sf::Keyboard::Scan::Num3] = '3';
    m_keyMap[sf::Keyboard::Scan::Num4] = '4';
    m_keyMap[sf::Keyboard::Scan::Num5] = '5';
    m_keyMap[sf::Keyboard::Scan::Num6] = '6';
    m_keyMap[sf::Keyboard::Scan::Num7] = '7';
    m_keyMap[sf::Keyboard::Scan::Num8] = '8';
    m_keyMap[sf::Keyboard::Scan::Num9] = '9';
    m_keyMap[sf::Keyboard::Scan::Comma] = '.';

    m_validKeys.push_back(sf::Keyboard::Scan::Num0);
    m_validKeys.push_back(sf::Keyboard::Scan::Num1);
    m_validKeys.push_back(sf::Keyboard::Scan::Num2);
    m_validKeys.push_back(sf::Keyboard::Scan::Num3);
    m_validKeys.push_back(sf::Keyboard::Scan::Num4);
    m_validKeys.push_back(sf::Keyboard::Scan::Num5);
    m_validKeys.push_back(sf::Keyboard::Scan::Num6);
    m_validKeys.push_back(sf::Keyboard::Scan::Num7);
    m_validKeys.push_back(sf::Keyboard::Scan::Num8);
    m_validKeys.push_back(sf::Keyboard::Scan::Num9);
    m_validKeys.push_back(sf::Keyboard::Scan::Comma);
    sf::Vector2u windowSize = m_window.getSize();
    double buttonWidthRatio = 8;
    double buttonHeightRatio = 12;
    sf::Vector2f pos = sf::Vector2f((windowSize.x / 2) - ((windowSize.x / buttonWidthRatio) / 2),
        (windowSize.y / 8));
    m_font = m_assets.get_font("font.ttf");

    pos.y += 400;
    pos.x -= 200;
    std::unique_ptr<IButton> playButton = m_buttonFactory.createButton("Default");
    sf::Text text2 = sf::Text();
    auto &m_bools = this->m_bools;
    auto &m_buttonTypes = this->m_buttonTypes;
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    text2.setFont(m_font);
    text2.setString("TCP Port : 8080");
    text2.setCharacterSize(28);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(pos.x + 15, pos.y + 25);
    playButton->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setCallback([this, &m_bools, &playButton]() {
        resetAndSetSelectedButton(0);
        });
    m_texts.push_back(std::move(text2));
    m_buttons.push_back(std::move(playButton));

    pos.x += 400;
    std::unique_ptr<IButton> udpPortButton = m_buttonFactory.createButton("Default");
    sf::Text text3 = sf::Text();
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    text3.setFont(m_font);
    text3.setString("UDP Port : 4242");
    text3.setCharacterSize(28);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(pos.x + 15, pos.y + 25);
    udpPortButton->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setCallback([this, &m_bools]() {
        resetAndSetSelectedButton(1);
        });
    m_texts.push_back(std::move(text3));
    m_buttons.push_back(std::move(udpPortButton));

    pos.x -= 250;
    pos.y -= 150;
    std::unique_ptr<IButton> ipPortButton = m_buttonFactory.createButton("Default");
    sf::Text text4 = sf::Text();
    m_bools.push_back(false);
    m_buttonTypes.push_back(ADDRESS);
    text4.setFont(m_font);
    text4.setString("IP Address : 127.0.0.1");
    text4.setCharacterSize(28);
    text4.setFillColor(sf::Color::White);
    text4.setPosition(pos.x + 15, pos.y + 25);
    ipPortButton->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio / 1.5, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setCallback([this, &m_bools]() {
                resetAndSetSelectedButton(2);
            });
    m_texts.push_back(std::move(text4));
    m_buttons.push_back(std::move(ipPortButton));

    pos.y += 300;
    pos.x += 50;
    std::unique_ptr<IButton> connectButton = m_buttonFactory.createButton("OneUse");
    sf::Text text5 = sf::Text();
    m_bools.push_back(false);
    m_buttonTypes.push_back(CONNECT);
    text5.setFont(m_font);
    text5.setString("CONNECT");
    text5.setCharacterSize(38);
    text5.setFillColor(sf::Color::Green);
    text5.setPosition(pos.x + 30, pos.y + 20);
    connectButton->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setButtonHoverColor(sf::Color::Transparent)
        .setCallback([this, &m_bools]() {
            resetAndSetSelectedButton(3);
        });
    m_texts.push_back(std::move(text5));
    m_buttons.push_back(std::move(connectButton));
}

void MainMenu::draw()
{
    int i = 0;
    int error = 0;
    HandleArgument arg;

    for (auto &button : m_buttons) {
        if (m_buttonTypes[i] == ADDRESS) {
            std::string str = m_texts[i].getString();
            str.erase(0, 13);
            if (arg.getIp(str.c_str()) == boost::asio::ip::address::from_string("255.255.255.255"))
                error++;
        }
        if (m_buttonTypes[i] == PORT) {
            std::string str = m_texts[i].getString();
            str.erase(0, 11);
            if (str.size() == 0 && (i == 0 || i == 1)) {
                error++;
            }
        }
        if (error != 0 && i  == 7) {} else {
            button->draw(m_window);
        }
        if (error != 0 && i == 3) {} else {
            m_window.draw(m_texts[i]);
        }
        i++;
    }

}

sf::Keyboard::Scan::Scancode MainMenu::getValidKeyPressed()
{
    for (auto &validKey : m_validKeys) {
        if (sf::Keyboard::isKeyPressed(validKey) == true) {
            return validKey;
        }
    }
    return sf::Keyboard::Scan::Scancode::Unknown;
}

void MainMenu::update()
{
    int i = 0;

    for (auto &button : m_buttons) {
        for (auto &key : m_keys) {
            for (size_t y = 0; y < m_bools.size(); y++) {
                if (m_bools[y] == true) {
                    std::string str = m_texts[y].getString();
                    sf::Keyboard::Scan::Scancode keyGot = getValidKeyPressed();
                    if (key == sf::Keyboard::BackSpace) {
                        if ((str.size() > 11 && m_buttonTypes[y] == PORT) || (str.size() > 13 && m_buttonTypes[y] == ADDRESS))
                            str.pop_back();
                        m_texts[y].setString(str);
                    } else if (keyGot != sf::Keyboard::Scan::Scancode::Unknown && ((str.size() < 16 && m_buttonTypes[y] == PORT) || (str.size() < 28 && m_buttonTypes[y] == ADDRESS))) {
                        if (m_buttonTypes[y] == PORT && m_keyMap[keyGot] == '.')
                            continue;
                        str += m_keyMap[keyGot];
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
        button->update(m_window);
        m_texts[i].setFillColor((m_bools[i] == true) ? sf::Color::Green : sf::Color::White);
        m_texts[i].setOutlineColor((m_bools[i] == true) ? sf::Color::Green : sf::Color::White);
        m_texts[i].setOutlineThickness((m_bools[i] == true) ? 0.5 : 0);
        i++;
    }
}

void MainMenu::resetAndSetSelectedButton(unsigned int index)
{
    for (size_t i = 0; i < m_bools.size(); i++)
        m_bools[i] = false;
    m_bools[index] = !m_bools[index];
}

unsigned int MainMenu::getButtonPressed()
{
    for (size_t i = 0; i < m_bools.size(); i++) {
        if (m_bools[i] == true)
            return i;
    }
    return 0;
}

unsigned int MainMenu::getUDPPort() const
{
    std::string str = m_texts[1].getString();
    str.erase(0, 11);
    return std::stoi(str);
}

unsigned int MainMenu::getTCPPort() const
{
    std::string str = m_texts[0].getString();
    str.erase(0, 11);
    return std::stoi(str);
}

ip::address MainMenu::getIp() const
{
    std::string str = m_texts[2].getString();
    str.erase(0, 13);
    return boost::asio::ip::address::from_string(str);
}

void MainMenu::loadBackground(sf::RenderWindow *window, Registry &registry)
{
    registry.spawn_entity();
    registry.spawn_entity();

    registry.add_component<Component::Position>(registry.entity_from_index(0), Component::Position(0, 0));
    registry.add_component<Component::Drawable>(registry.entity_from_index(0), Component::Drawable("SpaceBackground.png", window, sf::IntRect(0, 0, 300, 207), Component::Position(1920, 1080), registry.get_assets().get_texture("SpaceBackground.png")));
    registry.add_component<Component::Scroll>(registry.entity_from_index(0), Component::Scroll(Component::Position(0, 0), Component::Position(-5700, 0), 0.5));
    registry.add_component<Component::Position>(registry.entity_from_index(1), Component::Position(5700, 0));
    registry.add_component<Component::Drawable>(registry.entity_from_index(1), Component::Drawable("SpaceBackground.png", window, sf::IntRect(0, 0, 300, 207), Component::Position(1920, 1080), registry.get_assets().get_texture("SpaceBackground.png")));
    registry.add_component<Component::Scroll>(registry.entity_from_index(1), Component::Scroll(Component::Position(0, 0), Component::Position(0, 0), 0.5));
}

void MainMenu::deleteBackground(Registry &registry)
{
    registry.kill_entity(registry.entity_from_index(0));
    registry.kill_entity(registry.entity_from_index(1));
    (void)registry;
}

void MainMenu::deleteButtons(Registry &registry)
{
    (void)registry;
    m_buttons.clear();
    m_texts.clear();
    m_bools.clear();
    m_buttonTypes.clear();
    sf::Vector2u windowSize = m_window.getSize();
    double buttonWidthRatio = 8;
    double buttonHeightRatio = 12;
    sf::Vector2f pos = sf::Vector2f((windowSize.x / 2) - ((windowSize.x / buttonWidthRatio) / 2),
        (windowSize.y / 8));
    m_font = m_assets.get_font("font.ttf");

    pos.y += 150;
    pos.x -= 600;
    std::unique_ptr<IButton> andreasClass = m_buttonFactory.createButton("OneUse");
    sf::Text text1 = sf::Text();
    sf::Text text2 = sf::Text();
    sf::Text text3 = sf::Text();
    sf::Text text4 = sf::Text();
    sf::Text text5 = sf::Text();
    sf::Text text6 = sf::Text();
    auto &m_bools = this->m_bools;
    auto &m_buttonTypes = this->m_buttonTypes;
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    text1.setFont(m_font);
    text1.setString("ANDREAS");
    text1.setCharacterSize(34);
    text1.setFillColor(sf::Color::White);
    text1.setPosition(pos.x + 40, pos.y + 25);
    text2.setFont(m_font);
    text2.setString("SPEED : [####]");
    text2.setCharacterSize(22);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(pos.x + 35, pos.y + 135);
    text3.setFont(m_font);
    text3.setString("HEALTH : [#            ]");
    text3.setCharacterSize(22);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(pos.x + 20, pos.y + 175);
    text4.setFont(m_font);
    text4.setString("DAMAGE : [##        ]");
    text4.setCharacterSize(22);
    text4.setFillColor(sf::Color::White);
    text4.setPosition(pos.x + 10, pos.y + 215);
    text5.setFont(m_font);
    text5.setString("DELAY : [#            ]");
    text5.setCharacterSize(22);
    text5.setFillColor(sf::Color::White);
    text5.setPosition(pos.x + 35, pos.y + 255);
    text6.setFont(m_font);
    text6.setString("Assassin");
    text6.setCharacterSize(28);
    text6.setFillColor(sf::Color::White);
    text6.setPosition(pos.x + 75, pos.y + 85);
    andreasClass->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio / 3.5))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setCallback([this, &m_bools, &andreasClass]() {
            m_andreasSelected = true;
        });
    m_texts.push_back(std::move(text1));
    m_texts.push_back(std::move(text2));
    m_texts.push_back(std::move(text3));
    m_texts.push_back(std::move(text4));
    m_texts.push_back(std::move(text5));
    m_texts.push_back(std::move(text6));
    m_buttons.push_back(std::move(andreasClass));

    pos.x += 400;
    std::unique_ptr<IButton> nugoClass = m_buttonFactory.createButton("OneUse");
    sf::Text text7 = sf::Text();
    sf::Text text8 = sf::Text();
    sf::Text text9 = sf::Text();
    sf::Text text10 = sf::Text();
    sf::Text text11 = sf::Text();
    sf::Text text12 = sf::Text();
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    text7.setFont(m_font);
    text7.setString("NUGO");
    text7.setCharacterSize(34);
    text7.setFillColor(sf::Color::White);
    text7.setPosition(pos.x + 75, pos.y + 25);
    text8.setFont(m_font);
    text8.setString("SPEED : [#            ]");
    text8.setCharacterSize(22);
    text8.setFillColor(sf::Color::White);
    text8.setPosition(pos.x + 35, pos.y + 135);
    text9.setFont(m_font);
    text9.setString("HEALTH : [###    ]");
    text9.setCharacterSize(22);
    text9.setFillColor(sf::Color::White);
    text9.setPosition(pos.x + 20, pos.y + 175);
    text10.setFont(m_font);
    text10.setString("DAMAGE : [###    ]");
    text10.setCharacterSize(22);
    text10.setFillColor(sf::Color::White);
    text10.setPosition(pos.x + 10, pos.y + 215);
    text11.setFont(m_font);
    text11.setString("DELAY : [####]");
    text11.setCharacterSize(22);
    text11.setFillColor(sf::Color::White);
    text11.setPosition(pos.x + 35, pos.y + 255);
    text12.setFont(m_font);
    text12.setString("Tank");
    text12.setCharacterSize(28);
    text12.setFillColor(sf::Color::White);
    text12.setPosition(pos.x + 90, pos.y + 85);
    nugoClass->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio / 3.5))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setCallback([this, &m_bools, &nugoClass]() {
            m_nugoSelected = true;
        });
    m_texts.push_back(std::move(text7));
    m_texts.push_back(std::move(text8));
    m_texts.push_back(std::move(text9));
    m_texts.push_back(std::move(text10));
    m_texts.push_back(std::move(text11));
    m_texts.push_back(std::move(text12));
    m_buttons.push_back(std::move(nugoClass));

    pos.x += 400;
    std::unique_ptr<IButton> eliotClass = m_buttonFactory.createButton("OneUse");
    sf::Text text13 = sf::Text();
    sf::Text text14 = sf::Text();
    sf::Text text15 = sf::Text();
    sf::Text text16 = sf::Text();
    sf::Text text17 = sf::Text();
    sf::Text text18 = sf::Text();
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    text13.setFont(m_font);
    text13.setString("ELIOT");
    text13.setCharacterSize(34);
    text13.setFillColor(sf::Color::White);
    text13.setPosition(pos.x + 75, pos.y + 25);
    text14.setFont(m_font);
    text14.setString("SPEED : [##        ]");
    text14.setCharacterSize(22);
    text14.setFillColor(sf::Color::White);
    text14.setPosition(pos.x + 35, pos.y + 135);
    text15.setFont(m_font);
    text15.setString("HEALTH : [###    ]");
    text15.setCharacterSize(22);
    text15.setFillColor(sf::Color::White);
    text15.setPosition(pos.x + 20, pos.y + 175);
    text16.setFont(m_font);
    text16.setString("DAMAGE : [##        ]");
    text16.setCharacterSize(22);
    text16.setFillColor(sf::Color::White);
    text16.setPosition(pos.x + 10, pos.y + 215);
    text17.setFont(m_font);
    text17.setString("DELAY : [###    ]");
    text17.setCharacterSize(22);
    text17.setFillColor(sf::Color::White);
    text17.setPosition(pos.x + 35, pos.y + 255);
    text18.setFont(m_font);
    text18.setString("Robber");
    text18.setCharacterSize(28);
    text18.setFillColor(sf::Color::White);
    text18.setPosition(pos.x + 80, pos.y + 85);
    eliotClass->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio / 3.5))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setCallback([this, &m_bools, &eliotClass]() {
            m_eliotSelected = true;
        });
    m_texts.push_back(std::move(text13));
    m_texts.push_back(std::move(text14));
    m_texts.push_back(std::move(text15));
    m_texts.push_back(std::move(text16));
    m_texts.push_back(std::move(text17));
    m_texts.push_back(std::move(text18));
    m_buttons.push_back(std::move(eliotClass));

    pos.x += 400;
    std::unique_ptr<IButton> louisClass = m_buttonFactory.createButton("OneUse");
    sf::Text text19 = sf::Text();
    sf::Text text20 = sf::Text();
    sf::Text text21 = sf::Text();
    sf::Text text22 = sf::Text();
    sf::Text text23 = sf::Text();
    sf::Text text24 = sf::Text();
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    text19.setFont(m_font);
    text19.setString("LOUIS");
    text19.setCharacterSize(34);
    text19.setFillColor(sf::Color::White);
    text19.setPosition(pos.x + 75, pos.y + 25);
    text20.setFont(m_font);
    text20.setString("SPEED : [###    ]");
    text20.setCharacterSize(22);
    text20.setFillColor(sf::Color::White);
    text20.setPosition(pos.x + 35, pos.y + 135);
    text21.setFont(m_font);
    text21.setString("HEALTH : [##        ]");
    text21.setCharacterSize(22);
    text21.setFillColor(sf::Color::White);
    text21.setPosition(pos.x + 20, pos.y + 175);
    text22.setFont(m_font);
    text22.setString("DAMAGE : [##        ]");
    text22.setCharacterSize(22);
    text22.setFillColor(sf::Color::White);
    text22.setPosition(pos.x + 10, pos.y + 215);
    text23.setFont(m_font);
    text23.setString("DELAY : [##        ]");
    text23.setCharacterSize(22);
    text23.setFillColor(sf::Color::White);
    text23.setPosition(pos.x + 35, pos.y + 255);
    text24.setFont(m_font);
    text24.setString("Monge");
    text24.setCharacterSize(28);
    text24.setFillColor(sf::Color::White);
    text24.setPosition(pos.x + 80, pos.y + 85);
    louisClass->setButtonPosition(pos)
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio / 3.5))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setCallback([this, &m_bools, &louisClass]() {
            m_louisSelected = true;
        });
    m_texts.push_back(std::move(text19));
    m_texts.push_back(std::move(text20));
    m_texts.push_back(std::move(text21));
    m_texts.push_back(std::move(text22));
    m_texts.push_back(std::move(text23));
    m_texts.push_back(std::move(text24));
    m_buttons.push_back(std::move(louisClass));

    pos.x -= 600;
    pos.y += 150;
}

void MainMenu::loadClass(sf::RenderWindow *window, Registry &registry)
{
    (void)window;
    (void)registry;
}

void MainMenu::deleteClass(Registry &registry)
{
    (void)registry;
}

void MainMenu::drawClass()
{
    for (auto &button : m_buttons) {
        button->draw(m_window);
    }
    for (auto &text : m_texts) {
        m_window.draw(text);
    }
}


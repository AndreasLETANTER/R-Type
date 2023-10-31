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

    pos.y += 300;
    pos.x += 50;
    auto connectButton = m_buttons.emplace_back();
    auto text5 = m_texts.emplace_back();
    m_bools.push_back(false);
    m_buttonTypes.push_back(CONNECT);
    m_texts[3].setFont(m_font);
    m_texts[3].setString("CONNECT");
    m_texts[3].setCharacterSize(34);
    m_texts[3].setFillColor(sf::Color::Green);
    m_texts[3].setPosition(pos.x + 35, pos.y + 15);
    connectButton.setButtonPosition(pos);
    connectButton.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio));
    connectButton.setButtonColor(sf::Color::Transparent);
    connectButton.setButtonOutlineColor(sf::Color::White);
    connectButton.setButtonOutlineThickness(5);
    connectButton.setButtonHoverOutlineColor(sf::Color::Green);
    connectButton.setButtonHoverColor(sf::Color::Transparent);
    connectButton.setCallback([this, &m_bools]() {
        resetAndSetSelectedButton(3);
    });
    m_texts.push_back(std::move(text5));
    m_buttons.push_back(std::move(connectButton));
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
            button.draw(m_window);
        }
        if (error != 0 && i == 3) {} else {
            m_window.draw(m_texts[i]);
        }
        i++;
    }

}

void MainMenu::update()
{
    int i = 0;

    for (auto &button : m_buttons) {
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
        m_texts[i].setFillColor((m_bools[i] == true) ? sf::Color::Green : sf::Color::White);
        m_texts[i].setOutlineColor((m_bools[i] == true) ? sf::Color::Green : sf::Color::White);
        m_texts[i].setOutlineThickness((m_bools[i] == true) ? 0.5 : 0);
        button.update(m_window);
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

    pos.y += 400;
    pos.x -= 600;
    auto andreasClass = m_buttons.emplace_back();
    auto text3 = m_texts.emplace_back();
    auto &m_bools = this->m_bools;
    auto &m_buttonTypes = this->m_buttonTypes;
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    m_texts[0].setFont(m_font);
    m_texts[0].setString("ANDREAS");
    m_texts[0].setCharacterSize(28);
    m_texts[0].setFillColor(sf::Color::White);
    m_texts[0].setPosition(pos.x + 15, pos.y + 15);
    andreasClass.setButtonPosition(pos);
    andreasClass.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio));
    andreasClass.setButtonColor(sf::Color::Transparent);
    andreasClass.setButtonOutlineColor(sf::Color::White);
    andreasClass.setButtonOutlineThickness(5);
    andreasClass.setButtonHoverColor(sf::Color::Transparent);
    andreasClass.setButtonHoverOutlineColor(sf::Color::Green);
    andreasClass.setCallback([this, &m_bools, &andreasClass]() {
        resetAndSetSelectedButton(0);
    });
    m_texts.push_back(std::move(text3));
    m_buttons.push_back(std::move(andreasClass));

    pos.x += 400;
    auto nugoClass = m_buttons.emplace_back();
    auto text1 = m_texts.emplace_back();
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    m_texts[1].setFont(m_font);
    m_texts[1].setString("NUGO");
    m_texts[1].setCharacterSize(28);
    m_texts[1].setFillColor(sf::Color::White);
    m_texts[1].setPosition(pos.x + 15, pos.y + 15);
    nugoClass.setButtonPosition(pos);
    nugoClass.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio));
    nugoClass.setButtonColor(sf::Color::Transparent);
    nugoClass.setButtonOutlineColor(sf::Color::White);
    nugoClass.setButtonOutlineThickness(5);
    nugoClass.setButtonHoverColor(sf::Color::Transparent);
    nugoClass.setButtonHoverOutlineColor(sf::Color::Green);
    nugoClass.setCallback([this, &m_bools, &nugoClass]() {
        resetAndSetSelectedButton(1);
    });
    m_texts.push_back(std::move(text1));
    m_buttons.push_back(std::move(nugoClass));

    pos.x += 400;
    auto eliotClass = m_buttons.emplace_back();
    auto text2 = m_texts.emplace_back();
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    m_texts[2].setFont(m_font);
    m_texts[2].setString("ELIOT");
    m_texts[2].setCharacterSize(28);
    m_texts[2].setFillColor(sf::Color::White);
    m_texts[2].setPosition(pos.x + 15, pos.y + 15);
    eliotClass.setButtonPosition(pos);
    eliotClass.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio));
    eliotClass.setButtonColor(sf::Color::Transparent);
    eliotClass.setButtonOutlineColor(sf::Color::White);
    eliotClass.setButtonOutlineThickness(5);
    eliotClass.setButtonHoverColor(sf::Color::Transparent);
    eliotClass.setButtonHoverOutlineColor(sf::Color::Green);
    eliotClass.setCallback([this, &m_bools, &eliotClass]() {
        resetAndSetSelectedButton(2);
    });
    m_texts.push_back(std::move(text2));
    m_buttons.push_back(std::move(eliotClass));

    pos.x += 400;
    auto louisClass = m_buttons.emplace_back();
    auto text4 = m_texts.emplace_back();
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    m_texts[3].setFont(m_font);
    m_texts[3].setString("LOUIS");
    m_texts[3].setCharacterSize(28);
    m_texts[3].setFillColor(sf::Color::White);
    m_texts[3].setPosition(pos.x + 15, pos.y + 15);
    louisClass.setButtonPosition(pos);
    louisClass.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio));
    louisClass.setButtonColor(sf::Color::Transparent);
    louisClass.setButtonOutlineColor(sf::Color::White);
    louisClass.setButtonOutlineThickness(5);
    louisClass.setButtonHoverColor(sf::Color::Transparent);
    louisClass.setButtonHoverOutlineColor(sf::Color::Green);
    louisClass.setCallback([this, &m_bools, &louisClass]() {
        resetAndSetSelectedButton(3);
    });
    m_texts.push_back(std::move(text4));
    m_buttons.push_back(std::move(louisClass));

    pos.x -= 600;
    pos.y += 200;
    auto connectButton = m_buttons.emplace_back();
    auto text5 = m_texts.emplace_back();
    m_bools.push_back(false);
    m_buttonTypes.push_back(PORT);
    m_texts[3].setFont(m_font);
    m_texts[3].setString("START");
    m_texts[3].setCharacterSize(28);
    m_texts[3].setFillColor(sf::Color::White);
    m_texts[3].setPosition(pos.x + 15, pos.y + 15);
    connectButton.setButtonPosition(pos);
    connectButton.setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio));
    connectButton.setButtonColor(sf::Color::Transparent);
    connectButton.setButtonOutlineColor(sf::Color::White);
    connectButton.setButtonOutlineThickness(5);
    connectButton.setButtonHoverColor(sf::Color::Transparent);
    connectButton.setButtonHoverOutlineColor(sf::Color::Green);
    connectButton.setCallback([this, &m_bools, &connectButton]() {
        m_classSelected = true;
    });
    m_texts.push_back(std::move(text5));
    m_buttons.push_back(std::move(connectButton));
    resetAndSetSelectedButton(0);
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
        button.draw(m_window);
    }
    for (auto &text : m_texts) {
        m_window.draw(text);
    }
}


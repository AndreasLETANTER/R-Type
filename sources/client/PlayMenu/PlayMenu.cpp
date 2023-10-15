/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** PlayMenu
*/

#include "client/PlayMenu/PlayMenu.hpp"
#include <iostream>

PlayMenu::PlayMenu(sf::RenderWindow &window, Assets &assets, Registry &registry):
    m_window(window), m_assets(assets), m_registry(registry)
{
    sf::Vector2u windowSize = m_window.getSize();
    double buttonWidthRatio = 5;
    double buttonHeightRatio = 10;
    double textRatio = 30;
    double buttonWidth = windowSize.x / buttonWidthRatio;
    double buttonHeight = windowSize.y / buttonHeightRatio;
    double spacing = windowSize.y / 20;
    double xPos = (windowSize.x - buttonWidth) / 2;
    double yPos = (windowSize.y - (2 * buttonHeight + spacing)) / 2;
    m_font = assets.get_font("font.ttf");

    TextButton IPButton = TextButton()
        .setButtonPosition(sf::Vector2f(xPos, yPos))
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setTextString("IP")
        .setTextSize(windowSize, textRatio)
        .setTextFont(m_font)
        .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Green)
        .setCallback([this]() {
            std::cout << "IP button pressed" << std::endl;
            m_isIPEditable = true;
        });
    m_buttons.push_back(IPButton);

    yPos += buttonHeight + spacing;
    TextButton editableTextButton = TextButton()
        .setButtonPosition(sf::Vector2f(xPos, yPos))
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Green)
        .setTextString("Port")
        .setTextSize(windowSize, textRatio)
        .setTextFont(m_font)
        .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Green)
        .setCallback([this]() {
            std::cout << "Editable text button pressed" << std::endl;
            m_isPortEditable = true;
        });
    m_buttons.push_back(editableTextButton);

    yPos += buttonHeight + spacing;
    TextButton confirmButton = TextButton()
        .setButtonPosition(sf::Vector2f(xPos, yPos))
        .setButtonSize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio))
        .setButtonColor(sf::Color::Transparent)
        .setButtonOutlineColor(sf::Color::White)
        .setButtonOutlineThickness(5)
        .setButtonHoverColor(sf::Color::Transparent)
        .setButtonHoverOutlineColor(sf::Color::Blue)
        .setTextString("Confirm")
        .setTextSize(windowSize, textRatio)
        .setTextFont(m_font)
        .setTextPosition(TextButton::CENTER, TextButton::MIDDLE)
        .setTextColor(sf::Color::White)
        .setTextHoverColor(sf::Color::Blue)
        .setCallback([this]() {
            handleArgument handleArguments;
            tcpClientSocket tcpClient(handleArguments.getPort(m_buttons[0].getTextString().c_str()));
            udpClientSocket udpClient(handleArguments.getPort(m_buttons[0].getTextString().c_str()));

            tcpClient.run();
            udpClient.run();
            udpClient.send("connect");
            udpClient.send("");
            this->launchGame(udpClient);
        });
    m_buttons.push_back(confirmButton);
    this->resize();
}

void PlayMenu::draw()
{
    for (auto &button : m_buttons)
        button.draw(m_window);
}

void PlayMenu::update()
{
    for (auto &button : m_buttons)
        button.update(m_window);
    editTextButton(m_buttons[0], "IP", m_isIPEditable, 15, "0123456789.");
    editTextButton(m_buttons[1], "Port", m_isPortEditable, 5, "0123456789");
}

void PlayMenu::resize()
{
    sf::Vector2u windowSize = m_window.getSize();
    double buttonWidthRatio = 5;
    double buttonHeightRatio = 10;
    double textRatio = 30;
    double buttonWidth = windowSize.x / buttonWidthRatio;
    double buttonHeight = windowSize.y / buttonHeightRatio;
    double spacing = windowSize.y / 20;
    double xPos = (windowSize.x - buttonWidth) / 2;
    double yPos = (windowSize.y - (2 * buttonHeight + spacing)) / 2;

    m_buttons[0].resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
    yPos += buttonHeight + spacing;
    m_buttons[1].resize(windowSize, sf::Vector2f(buttonWidthRatio, buttonHeightRatio),
        sf::Vector2f(xPos, yPos), textRatio);
}

void PlayMenu::editTextButton(TextButton &button,
    const std::string &initialText, bool &isEditable,
    const long unsigned int &maxSize, const std::string &acceptedChars)
{
    if (isEditable) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (button.getTextString() == initialText &&
                (acceptedChars.find(event.text.unicode) != std::string::npos
                || event.text.unicode == 8))
                button.setTextString("");
            if (event.type == sf::Event::TextEntered) {
                if (acceptedChars.find(event.text.unicode) != std::string::npos &&
                    button.getTextString().size() < maxSize) {
                    std::string newText = button.getTextString();
                    newText += static_cast<char>(event.text.unicode);
                    button.setTextString(newText);
                } else if (event.text.unicode == 8 && !button.getTextString().empty()) {
                    std::string newText = button.getTextString();
                    newText.pop_back();
                    button.setTextString(newText);
                }
                button.setTextPosition(TextButton::CENTER, TextButton::MIDDLE);
            } else if (event.type == sf::Event::Closed) {
                m_window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                isEditable = false;
                if (button.getTextString() == "") {
                    button.setTextString(initialText);
                    button.setTextPosition(TextButton::CENTER, TextButton::MIDDLE);
                }
            }
        }
    }
}

void PlayMenu::launchGame(udpClientSocket &udpClient)
{
    while (m_window.isOpen()) {
        std::pair<message_t *, size_t> messages = m_converter.convertBinaryToStruct(udpClient.receive());
        m_registry = Registry();
        m_registry.importFromMessages(messages.first, messages.second, &m_window);
        m_window.clear();
        m_registry.run_systems();
        m_window.display();
    }
}

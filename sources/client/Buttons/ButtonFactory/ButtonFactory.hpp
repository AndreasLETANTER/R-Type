/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ButtonFactory
*/

#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <functional>

#include "client/Buttons/IButton.hpp"
#include "client/Buttons/OneUseButton/OneUseButton.hpp"
#include "client/Buttons/CooldownButton/CooldownButton.hpp"
#include "client/Buttons/Button/Button.hpp"

/**
 * @brief Factory to create buttons
 */
class ButtonFactory {
    public:
        /**
         * @brief Constructor of ButtonFactory
         */
        ButtonFactory() = default;

        /**
         * @brief Destructor of ButtonFactory
         */
        ~ButtonFactory() = default;

        /**
         * @brief Create a button
         *
         * @param buttonType Type of the button
         * @return A unique pointer on the button
         */
        std::unique_ptr<IButton> createButton(const std::string &buttonType);
    private:
        std::unordered_map<std::string, std::function<std::unique_ptr<IButton>()>> m_buttonsType = {
            {"OneUse", []() {
                return std::make_unique<OneUseButton>();
            }},
            {"Cooldown", []() {
                return std::make_unique<CooldownButton>();
            }},
            {"Default", []() {
                return std::make_unique<Button>();
            }}
        };
};

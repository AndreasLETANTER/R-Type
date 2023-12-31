/*
** EPITECH PROJECT, 2023
** B-CPP-500-NAN-5-1-bsrtype-andreas.le-tanter
** File description:
** Registry
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>
#include <typeindex>
#include <memory>
#include <any>

#include "ECS/SparseArrayClass/SparseArray.hpp"
#include "ECS/EntityClass/Entity.hpp"
#include "ECS/Components/Position.hpp"
#include "ECS/Components/Score.hpp"
#include "ECS/Assets/Assets.hpp"
#include "client/Buttons/OneUseButton/OneUseButton.hpp"

enum EntityClasses {
    NUGO,
    ANDREAS,
    ELIOT,
    LOUIS,
    MOB_ORANGE_CRAB,
    MOB_YELLOW_POPCORN,
    MOB_GREEN_PLANT,
    MOB_BLUE_D,
    FIRST_BOSS,
    SPEED_POWERUP,
    HEALTH_POWERUP,
    DAMAGE_POWERUP,
    SHOOTING_SPEED_POWERUP
};

#define ALL_GAME_INFO_CODE 100
#define NO_MORE_GAME_INFO_CODE 101
#define ENTITY_DEATH_CODE 102
#define ENTITY_SPAWN_CODE 103
#define ENTITY_MOVE_CODE 104
#define ENTITY_SCORE_CODE 105
#define LOSE_CODE 106
#define WIN_CODE 107
#define RESTART_CODE 108
#define END_CODE 109

#define CLIENT_CLASS_CODE 200
#define CLIENT_INPUT_CODE 201
#define CLIENT_DISCONNECT_CODE 202

/**
 * @brief Struct representing a message containing the sprite name position and score of an entity.
 */
typedef struct message_s {
    char sprite_name[128] = {0};
    double x;
    double y;
    unsigned int entity_id;
    unsigned int client_id;
    sf::IntRect rect;
    Component::Position scale;
    bool isBackground;
    int score;
} message_t;

/**
 * @brief Struct representing a packet with a message type and a message.
 */
typedef struct packet_s
{
    unsigned int messageType;
    unsigned int packet_id;
    message_t message;
} packet_t;

/**
 * @brief Struct representing an input event.
 */
typedef struct input_s
{
    unsigned int id;
    sf::Keyboard::Key key;
    bool pressed;
} input_t;

typedef struct client_packet_s
{
    unsigned int messageType;
    EntityClasses entityClass;
    input_t input;
} client_packet_t;

/**
 * @brief The Registry class is responsible for managing entities and their components.
 * It provides methods to register and remove components, spawn and kill entities, and add and run systems.
 *
 * @tparam Component The type of component to register.
 */
class Registry {
    public:
        Registry() = default;

        /**
         * @brief Construct a new Registry object with a given Assets object.
         *
         * @param assets The assets to use for the registry.
         * @param window The window to draw the entities in.
         * @param clock The clock of the program.
         */
        Registry(Assets assets, sf::RenderWindow *window, sf::Clock *clock);

        /**
         * @brief The type of function used to erase a component from the registry.
         */
        using erase_function = std::function<void(Registry&, Entity const&)>;

        /**
         * @brief Registers a component of type Component in the registry.
         *
         * @tparam Component The type of component to register.
         * @return SparseArray<Component>& A reference to the SparseArray of the registered component.
         */
        template <class Component>
        SparseArray<Component> &register_component();

        /**
         * @brief Registers an erase function for a component of type Component in the registry.
         *
         * @tparam Component The type of component to register the erase function for.
         * @param function The erase function to register.
         * @return erase_function The registered erase function.
         */
        template <class Component>
        erase_function register_erase_function(erase_function function);

        /**
         * @brief Removes a component of type Component from the registry for a given entity.
         *
         * @tparam Component The type of component to remove.
         * @param entity The entity to remove the component from.
         */
        template <class Component>
        void erase_entity(Entity const &entity);

        /**
         * @brief Returns a reference to the SparseArray of components of type Component in the registry.
         *
         * @tparam Component The type of component to get the SparseArray for.
         * @return SparseArray<Component>& A reference to the SparseArray of components of type Component in the registry.
         */
        template <class Component>
        SparseArray<Component> &get_components();

        /**
         * @brief Returns a const reference to the SparseArray of components of type Component in the registry.
         *
         * @tparam Component The type of component to get the SparseArray for.
         * @return SparseArray<Component> const& A const reference to the SparseArray of components of type Component in the registry.
         */
        template <class Component>
        SparseArray<Component> const &get_components() const;

        /**
         * @brief Spawns a new entity in the registry.
         *
         * @return Entity The newly spawned entity.
         */
        Entity spawn_entity();

        /**
         * @brief Spawns a new entity in the registry.
         *
         * @return Entity The newly spawned entity.
         */
        Entity spawn_entity(unsigned int id);

        /**
         * @brief Returns the entity corresponding to a given index in the registry.
         *
         * @param idx The index of the entity to get.
         * @return Entity The entity corresponding to the given index.
         */
        Entity entity_from_index(std ::size_t idx);

        /**
         * @brief Returns the entity associated with the given ID.
         *
         * @param id The ID of the entity to retrieve.
         * @return Entity The entity associated with the given ID.
         */
        Entity entity_from_id(unsigned int id);

        /**
         * @brief Returns the player associated with the given ID.
         *
         * @param id The ID of the entity to retrieve.
         * @return Entity The entity associated with the given ID.
         */
        Entity player_from_id(unsigned int id);

        /**
         * @brief Kills an entity in the registry.
         *
         * @param e The entity to kill.
         */
        void kill_entity(Entity const &e);

        /**
         * @brief Adds a component of type Component to an entity in the registry.
         *
         * @tparam Component The type of component to add.
         * @param to The entity to add the component to.
         * @param c The component to add.
         * @return typename SparseArray<Component>::reference_type A reference to the added component.
         */
        template <typename Component>
        typename SparseArray<Component>::reference_type add_component(Entity const &to,
                                                                        Component &&c);

        /**
         * @brief Emplaces a component of type Component to an entity in the registry.
         *
         * @tparam Component The type of component to emplace.
         * @tparam Params The types of the parameters to emplace the component with.
         * @param to The entity to emplace the component to.
         * @param p The parameters to emplace the component with.
         * @return typename SparseArray<Component>::reference_type A reference to the emplaced component.
         */
        template <typename Component, typename... Params>
        typename SparseArray<Component>::reference_type emplace_component(Entity const &to, Params &&...p);

        /**
         * @brief Removes a component of type Component from an entity in the registry.
         *
         * @tparam Component The type of component to remove.
         * @param from The entity to remove the component from.
         */
        template <typename Component>
        void remove_component(Entity const &from);

        /**
         * @brief Adds a system to the registry.
         *
         * @tparam Components The types of components the system requires.
         * @tparam Function The type of the function to add as a system.
         * @param f The function to add as a system.
         */
        template <class... Components, typename Function>
        void add_system(Function &&f);

        /**
         * @brief Adds a system to the registry.
         *
         * @tparam Components The types of components the system requires.
         * @tparam Function The type of the function to add as a system.
         * @param f The function to add as a system.
         */
        template <class... Components, typename Function>
        void add_system(Function const &f);

        /**
         * @brief Runs all the systems in the registry.
         */
        void run_systems();

        /**
         * @brief Exports the registry's entities and components to an array of messages.
         * @param needAllGameInfo If true, all the game info will be sent.
         *
         * @return std::tuple<message_t *, size_t> A tuple containing a pointer to the array of messages and its size.
         */
        std::vector<packet_t> exportToPackets(bool needAllGameInfo = false);

        /**
         * @brief Exports the recently killed entities as a vector of packets.
         *
         * @return std::vector<packet_t>
         */
        std::vector<packet_t> exportRecentlyKilledEntities();

        /**
         * @brief Updates the registry from a received packet.
         *
         * @param packet The packet to update the registry from.
         * @param window The render window to draw entities on.
         * @param scoreButton The button to update the score.
         * @param clientId The ID of the client that sent the packet.
         */
        void updateFromPacket(packet_t packet, sf::RenderWindow *window, std::unique_ptr<IButton> &scoreButton, unsigned int clientId);

        /**
         * @brief Returns the assets of the registry.
         *
         * @return Assets& A reference to the assets of the registry.
         */
        Assets &get_assets();

        /**
         * @brief Update the key pressed of an entity.
         *
         * @param input The input of the entity.
         */
        void updateEntityKeyPressed(input_t input);

        /**
         * @brief Returns true or false if all players are dead or not.
         *
         * @return true if all players are dead.
         * @return false if not all players are dead.
         */
        bool playersAreDead();

        /**
         * @brief Returns true or false if all enemies are dead or not.
         *
         * @return true if all enemies are dead.
         * @return false if not all enemies are dead.
         */
        bool enemiesAreDead();

        /**
         * @brief Returns the window of the registry.
         *
         * @return sf::RenderWindow* A pointer to the window of the registry.
         */
        sf::RenderWindow *getWindow() const;

        /**
         * @brief Returns a pointer to the clock used by the registry.
         *
         * @return sf::Clock* A pointer to the clock used by the registry.
         */
        sf::Clock *getClock() const;

        /**
         * @brief set the window of the registry.
         *
         * @param window The window to set.
         */
        void setWindow(sf::RenderWindow *window);

        /**
         * @brief set the clock of the registry.
         *
         * @param clock The clock to set.
         */
        void setClock(sf::Clock *clock);

        void setNeedToRestart(bool needToRestart);

        bool getNeedToRestart() const;

        SparseArray<std::pair<Entity, unsigned int>> &getEntities();

        /**
         * @brief Add a player class to the list.
         *
         * @param id The id of the player.
         * @param entityClass The class of the player.
         */
        void addPlayerClass(unsigned int id, EntityClasses entityClass);

        /**
         * @brief Get the player class of a player by his id.
         *
         * @param id The id of the player.
         * @return The class of the player.
         */
        EntityClasses getPlayerClass(unsigned int id);
    private:
        std::unordered_map<std::type_index, std::any> m_components;
        std::unordered_map<std::type_index, erase_function> m_erase_functions;
        std::vector<std::function<void(Registry&)>> m_systems;
        SparseArray<std::pair<Entity, unsigned int>> m_entities;
        SparseArray<std::pair<Entity, unsigned int>> m_previous_entities;
        std::vector<packet_t> m_recently_killed_entities;
        SparseArray<Component::Position> m_previous_positions;
        SparseArray<Component::Score> m_previous_scores;
        sf::RenderWindow *m_window;
        sf::Clock *m_clock;
        Assets m_assets;
        bool m_needToRestart = false;
        std::map<unsigned int, EntityClasses> m_playersClasses;
};

#include "ECS/RegistryClass/Registry.tpp"

# RFC - Client / Server

**Date:** *23 / 10 / 2023*
**Author**: *Andréas LE TANTER*
**Status**: *Draft*
**Version:** *0.2*

## 1 - Introduction

This RFC outlines the network component requirements and specifications for the R-Type project. The network component is responsible for facilitating multiplayer functionality within the game.  For this project we use the UDP (User Datagram Protocol) communication protocol, which allows us to have an application with low latency.

## 2 - Goals

The primary goals of the network component are as follows:

- Enable multiplayer gameplay for R-Type.
- Provide a reliable communication framework for real-time game data exchange.
- Ensure scalability and performance to support a reasonable number of concurrent players.

## 3 - Network Protocol

The network should use a standardized protocol for communication.

The protocol is composed of two parts :

- **TCP** (Transmission Control Protocol) for the connection between the client and the server for letting the server know the id of the client so it can be assigned to a spaceship.

- **UDP** (User Datagram Protocol) for the communication between the client and the server for the game data (like the death of an entity, spawn of an entity, etc...).

## 3.1 - Command structure

Commands must all be composed the same according to the following model.

All packets must be composed of a message type and a message.

### Message Type :

The differents types of packets are:

- ALL_GAME_INFO_CODE  (100) -> used when a new client connect for sending him all the informations about the game.
- NO_MORE_GAME_INFO_CODE (101) -> used to tell the clients when the games info are all sent to him so he can now look on other codes.
- ENTITY_DEATH_CODE (102) -> used to tell the clients that an entity died.
- ENTITY_SPAWN_CODE (103) -> used to tell the clients that an entity spawned.
- ENTITY_MOVE_CODE (104) -> used to tell the clients that an entity position changed.

### Message :

A typical message is structured like so:

```bash
typedef struct message_s {
    char sprite_name[128];
    double x;
    double y;
    unsigned int entity_id;
    sf::IntRect rect;
    Component::Position scale;
} message_t;
```

The sprite_name is the name of the sprite associated with the entity.

The x and y are the coordinates of the entity's position.

The entity_id is the id of the entity.

The rect is the rectangle of the sprite associated with the entity.

The scale is the scale of the texture.

### Warning, the server does not fill all the information based on the message type, for example the death of an entity doesnt need more information than the id of the entity and the type of the message.

## 3.2 - Client-Server tcp communication

The client only need to connect to the server, it will then send back the id of the client. Letting the client know that he is connected to the server.

## 3.3 - Client-Server udp communication

At connection the server will generate information about ALL the game in multiple packets to the clients. Letting the client get all the current information and states of the game.
    
Then the server will send packets to the clients when an entity dies, spawn, or move.

It is the responsability of the client to update the game based on the information received.

# RFC - Client / Server

**Date:** *25 / 09 / 2023*
**Author**: *To complete*
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

## 3.1 - Command structure

Commands must all be composed the same according to the following model.

All messages must be composed of a header and a body.

### Header :

```bash
typedef struct s_header
{
    unsigned int messageId;
    unsigned int timestamp;
    unsigned int nbEntities;
} t_header;
```

- **messageId**

Message identifier generated with the random library like this :

```bash
std::rand() % 10000000
```

- **timestamp**

Timestamp of the message in milliseconds generated with the chrono library like this :

```bash
static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() % 10000000);
```

- **nbEntities**

Number of entities in the message transmitted with the export message function of the registry.

### Body :

The body message can be composed of several things :

- **First message**

```bash
typedef struct s_first_message
{
    unsigned int id;
    unsigned int udp_port;
} t_first_message;
```

- **Entity message**

```bash
typedef struct message_s {
    char sprite_name[128] = {0};
    double x;
    double y;
    sf::IntRect rect;
    Component::Position position;
} message_t;
```

## 3.2 - Client-Server tcp Initialization

When a client requests to connect to the server it must send the following messages.

### Server response ✔️:

Header :
```bash
typedef struct s_header
{
    unsigned int messageId;
    unsigned int timestamp;
    unsigned int nbEntities;
} t_header;
```

Message :
```bash
typedef struct s_first_message
{
    unsigned int id;
    unsigned int udp_port;
} t_first_message;
```

- **id**

*Unique identifier of the player* (start at 1)

- **udp_port**

*Port of the udp socket*

## 3.3 - Client-Server Disconnection

With the udp process we do not need to send a connection or disconnection message

## 4 - Data Exchange

The network component is responsible for facilitating the exchange of data between the client and the server. The following data must be exchanged between the client and the server:

- Player position and sprite
- Player actions
- Player health
- Player score

## 4.1 - Player position and sprite

The player position and sprite are sent by the client to the server and by the server to the client. The player position and sprite are sent in the following format:

```bash
{sprite_name=”plane.jpeg”,pos=[x=”-92.92”,y=“686.16”]}
```

- **{sprite_name=”plane.jpeg”,pos=[x=”-92.92”,y=“686.16”]}**

*Entity of the map :*

- **sprite_name=”plane.jpeg”**

*Entity sprite name for the display processus*

- **pos=[x=”-92.92”,y=“686.16”]**

*Entity position :*

```bash
pos=[x=”-92.92”,y=“686.16”]
```

- **x=”-92.92”**

*X position*

- **y=“686.16”**

*Y position*

## 4.2 - Player actions

The player actions are sent by the client to the server and by the server to the client. The player actions are sent in the following format:

```bash
action=[up=“true”,down=“false”,left=“false”,right=“false”,shoot=“false”]
```

- **up=“true”**

*Up action*

- **down=“false”**

*Down action*

- **left=“false”**

*Left action*

- **right=“false”**

*Right action*

- **shoot=“false”**

*Shoot action*


## 4.3 - Player health

The player health is sent by the client to the server and by the server to the client. The player health is sent in the following format:

```bash
health=“100”
```

- **health=“100”**

*Health value*

## 4.4 - Player score

The player score is sent by the client to the server and by the server to the client. The player score is sent in the following format:

```bash
score=“100”
```

- **score=“100”**

*Score value*

## 5 - Binary data exchange


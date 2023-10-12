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

### Client request ✔️:

The client must send an empty message to the server to request a connection.

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

## 4 - Message datas

Before sending a message, the server export the entities in the following format :

```bash
std::pair<size_t nbEntities, message_t> exportMessage();
```

The message is composed message_t * nbEntities.
For example, if the server has 3 entities, the message will be composed of 3 message_t.

Filled like this :

```bash
struct message_s {
    sprite_name = "plane.jpeg";
    x=-92.92;
    y=686.16;
    rect = sf::IntRect(263, 11, 80, 3);
    position = {22, 98};
};
```

# RFC - Client / Server

**Date:** *25 / 09 / 2023*
**Author**: *To complete*
**Status**: *Draft*
**Version:** *0.1*

## 1 - Introduction

This RFC outlines the network component requirements and specifications for the R-Type project. The network component is responsible for facilitating multiplayer functionality within the game.  For this project we use the UDP (User Datagram Protocol) communication protocol, which allows us to have an application with low latency.

## 2 - Goals

The primary goals of the network component are as follows:

- Enable multiplayer gameplay for R-Type.
- Provide a reliable communication framework for real-time game data exchange.
- Ensure scalability and performance to support a reasonable number of concurrent players.

## 3 - Network Protocol

The network should use a standardized protocol for communication. 

| Status codes | Description |
| --- | --- |
| 1xx | Informational, Request   |
| 2xx | Client |
| 3xx | Server |

| Status codes | Description |
| --- | --- |
| 100 | I want to connect to the server |
| 200 |  |
| 300 | Connexion established |
| 301 | Connection not successful |

## 3.1 - Command structure

Commands must all be composed the same according to the following model

```bash
[STATUS CODE]:[PARAMETER OR ANSWER];[PARAMETER OR ANSWER]
```

- [STATUS CODE]

*The return code according to the response table*

- :

*The first separator that differentiates status code and parameters*

- [PARAMETER OR ANSWER]

*The different feedback information, this can be player positions, displays, etc.*

- ;

*Separator which allows you to differentiate between the different parameters*

## 3.2 - Client-Server Initialization

When a client requests to connect to the server it must send the following messages

### Client request :

```bash
100:
```

- **100**

*Return code*

### Server answer ✔️:

```bash
300:id=2;{sprite_name=”plane.jpeg”, pos=[x=”-92.92”, y=“686.16”]};{sprite_name=”mob.jpeg”, pos=[x=”23.19”, y=“68.22”]}
```

- **300**

*Status code*

- **id=2**

*Id of the player*

- **{sprite_name=”plane.jpeg”, pos=[x=”-92.92”, y=“686.16”]}**

*Entity of the map :*

- **sprite_name=”plane.jpeg”**

*Entity sprite name for the display processus*

- **pos=[x=”-92.92”, y=“686.16”]**

*Entity position :*

- **x=”-92.92”**

*X position*

- **y=“686.16”**

*Y position*

### Server answer ✖️:

```bash
301:
```

- **301**

*Status code*

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
{sprite_name=”plane.jpeg”, pos=[x=”-92.92”, y=“686.16”]}
```

- **{sprite_name=”plane.jpeg”, pos=[x=”-92.92”, y=“686.16”]}**

*Entity of the map :*

- **sprite_name=”plane.jpeg”**

*Entity sprite name for the display processus*

- **pos=[x=”-92.92”, y=“686.16”]**

*Entity position :*

```bash
pos=[x=”-92.92”, y=“686.16”]
```

- **x=”-92.92”**

*X position*

- **y=“686.16”**

*Y position*

## 4.2 - Player actions

The player actions are sent by the client to the server and by the server to the client. The player actions are sent in the following format:

```bash
action=[up=“true”, down=“false”, left=“false”, right=“false”, shoot=“false”]
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


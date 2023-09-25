# RFC - Client / Server

**Date:** *25 / 09 / 2023*
**Author**: *To complete*
**Status**: *Draft*

**Version:** *0.1*

## 1 - Introduction

This RFC outlines the network component requirements and specifications for the R-Type project. The network component is responsible for facilitating multiplayer functionality within the game.

## 2 - Goals

The primary goals of the network component are as follows:

- Enable multiplayer gameplay for R-Type.
- Provide a reliable communication framework for real-time game data exchange.
- Ensure scalability and performance to support a reasonable number of concurrent players.

## 3 - Network Protocol

The network component should use a standardized protocol for communication. We propose using TCP/IP for reliable communication between game clients and the game server. UDP may be considered for specific real-time data transfer

| Status codes | Description |
| --- | --- |
| 1xx | Informational, Request   |
| 2xx | Client |
| 3xx | Server |

| Status codes | Description |
| --- | --- |
| 100 | Je veux me connecter au serveur |
| 200 |  |
| 300 | Connection établie |
| 301 | La connection à échouée |

“to complete with comment for each description”

## 3.1 - Command structure

Commands must all be composed the same according to the following model

```bash
[STATUS CODE]:[PARAMETER OR ANSWER];[PARAMETER OR ANSWER]
```

- [STATUS CODE]

*The returns code according to the response table*

- :

*The first separator that differentiates between the status code and the parameters*

- [PARAMETER OR ANSWER]

*The different feedback information, this can be player positions, displays, etc.*

- ;

*Separator which allows you to differentiate between the different parameters*

## 3.2 - Client-Server Initialization

When a client requests to connect to the server it must send the following messages

### Client request :

<aside>
✉️ 100:

</aside>

- **100**

*Return code*

### Server answer ✔️:

<aside>
✉️ 300:id=2;{sprite_name=”plane.jpeg”, pos=[x=”-92.92”, y=“686.16”]};{sprite_name=”mob.jpeg”, pos=[x=”23.19”, y=“68.22”]}

</aside>

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

<aside>
✉️ 301:

</aside>

- **301**

*Status code*
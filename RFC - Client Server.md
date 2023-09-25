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

Lorsque un client demande à se connecter au serveur il doit envoyer les messages suivants

### Client request :

<aside>
✉️ 100:

</aside>

### Server answer :

<aside>
✉️ 300:id=2;

</aside>
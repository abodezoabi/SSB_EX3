Catan Game Simulation
Welcome to the Catan Game Simulation project, implemented in C++. This project replicates the mechanics of the popular board game Catan, focusing on strategic resource management, settlement building, and competitive gameplay dynamics.

Game Overview
Catan is a strategic board game where players compete to establish settlements and cities on an island by collecting and trading resources such as wood, brick, ore, wheat, and sheep. Players earn victory points through strategic decisions and the expansion of their territories.

Implemented Classes
Board
The Board class represents the game board with hexagonal tiles and manages the distribution of resources and dice roll probabilities associated with each tile. It ensures that resources are distributed based on dice rolls and handles the setup and management of hexagonal tiles.

Vertex and Edge
Vertex: Represents the corners where players can build settlements or cities. These locations are critical for players to expand their influence and earn victory points.

Edge: Represents the roads connecting vertices, which players must build to connect their settlements and cities. Roads play a pivotal role in expanding territories and gaining access to new resources.

Player
The Player class manages each player's state throughout the game:

Resources: Tracks resources such as wood, brick, ore, wheat, and sheep, which are essential for building settlements, cities, and roads.
Development Cards: Handles the acquisition and use of development cards, including knights, monopoly, road building, and year of plenty.
Victory Points: Tracks the number of victory points earned by the player, which determines their progress towards winning the game.
Card
The Card class hierarchy implements various development cards used in the game:

KnightCard: Allows players to move the robber and steal resources from opponents, providing a strategic advantage in resource management and disruption of opponents' plans.
VictoryPointCard: Increases a player's victory points directly, representing significant milestones towards winning the game.
MonopolyCard: Enables a player to monopolize a specific resource type from all other players, which can drastically shift resource availability and trading dynamics.
RoadBuildingCard: Allows construction of two roads, facilitating rapid expansion and connectivity across the game board.
YearOfPlentyCard: Grants two resources of choice from the bank, offering flexibility in resource acquisition and strategic planning.
Catan
The Catan class orchestrates game mechanics such as turn management, resource allocation, dice rolling, and win condition checks. It ensures fair gameplay, manages the sequence of turns, and verifies win conditions based on victory points accumulated by players.

Implementation Details
Inheritance in Card Class: Utilizes inheritance to implement different card functionalities while maintaining a unified interface, ensuring that each card type can be used seamlessly within the game mechanics.

Resource Management: Implements logic to manage the acquisition, expenditure, and trading of resources among players, ensuring balanced gameplay and strategic decision-making.

Turn-based Mechanics: Implements turn-based gameplay where each player takes turns to perform actions such as rolling dice, collecting resources, building structures, and using development cards.

Win Condition Verification: Implements logic to verify win conditions based on victory points earned by players, declaring a winner when a player reaches the required number of victory points.

Compilation and Execution Instructions
Running the Demo
To compile and execute the main game demo:

Compile the executable:


make catan
Run the game:


./catan
Running Tests
To compile and execute unit tests:

Compile the test executable:


make test

Execute the tests:


./test

EMAIL: abodezoabi2000@gmail.com 


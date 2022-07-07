# Two Player Battle Adventure
This is a text based C++ Game which can be played by 2 Players

## Rules of the Game
* Both players will have one turn at a time.
* Each player will have two options for performing an action.
    1. To heal → This will heal the active player and current health will get updated.
        1. If the health of the player is already full then healing will not take place and the respected player will lose the turn showing some text output.
    2. To attack → This will damage the other player and console-based output will get shown.
* There will be three types of players that a user can choose at the beginning of the game.
    - Type-A → High Health, Low Damage, Low Healing.
    - Type B → Avg Health, Avg Damage, Avg Healing.
    - Type C → Low Health, High Damage, Avg Healing.
    
## Notable Mentions
* Player as parent class.
* Other types of players will inherit from the Player class and will be children of the Player Class.
* virtual methods in parent class for taking damage and giving additional damage.
* Also used method overriding method overloading of OOP Consept

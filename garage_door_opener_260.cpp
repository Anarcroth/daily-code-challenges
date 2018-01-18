// Description
//
// You just got a new garage door installed by the Automata™ Garage Door Company. You are having a lot of fun playing with the remote clicker, opening and closing the door, scaring your pets and annoying the neighbors.
//
// The clicker is a one-button remote that works like this:
//
//     If the door is OPEN or CLOSED, clicking the button will cause the door to move, until it completes the cycle of opening or closing.
//
//     Door: Closed -> Button clicked -> Door: Opening -> Cycle complete -> Door: Open.
//
//     If the door is currently opening or closing, clicking the button will make the door stop where it is. When clicked again, the door will go the opposite direction, until complete or the button is clicked again.
//
// We will assume the initial state is CLOSED.
// Formal Inputs & Outputs
// Input description
//
// Input will be a series of commands (can be hard coded, no need to parse):
//
// button_clicked
// cycle_complete
// button_clicked
// button_clicked
// button_clicked
// button_clicked
// button_clicked
// cycle_complete
//
// Output description
//
// Output should be the state of the door and the input commands, such as:
//
// Door: CLOSED
// > Button clicked.
// Door: OPENING
// > Cycle complete.
// Door: OPEN
// > Button clicked.
// Door: CLOSING
// > Button clicked.
// Door: STOPPED_WHILE_CLOSING
// > Button clicked.
// Door: OPENING
// > Button clicked.
// Door: STOPPED_WHILE_OPENING
// > Button clicked.
// Door: CLOSING
// > Cycle complete.
// Door: CLOSED
//
// Notes/Hints
//
// This is an example of a simple Finite State Machine with 6 States and 2 inputs.
// Bonus
//
// Bonus challenge - The door has an infrared beam near the bottom, and if something is breaking the beam, (your car, your cat, or a baby in a stroller) the door will be BLOCKED and will add the following rules:
//
//     If the door is currently CLOSING, it will reverse to OPENING until completely OPEN. It will remain BLOCKED, however, until the input BLOCK_CLEARED is called.
//     Any other state, it will remain in that position, until the input BLOCK_CLEARED is called, and then it will revert back to it's prior state before it was blocked. Button clicks will be discarded. If the door was already in the process of opening, it will continue to OPEN until CYCLE_COMPLETE is called.
//
// Bonus Challenge Input
//
// button_clicked
// cycle_complete
// button_clicked
// block_detected
// button_clicked
// cycle_complete
// button_clicked
// block_cleared
// button_clicked
// cycle_complete
//
// Bonus Challenge output:
//
// Door: CLOSED
// > Button clicked
// Door: OPENING
// > Cycle complete
// Door: OPEN
// > Button Clicked
// Door: CLOSING
// > Block detected!
// Door: EMERGENCY_OPENING
// > Button clicked.
// Door: EMERGENCY_OPENING
// > Cycle complete.
// Door: OPEN_BLOCKED
// > Button clicked
// Door: OPEN_BLOCKED
// > Block cleared
// Door: OPEN
// > Button clicked
// Door: CLOSING
// > Cycle complete
// Door: CLOSED
//

#include <iostream>
#include <string>

class GarageDoor
{
public:
    GarageDoor();

    void show_state();
    void set_state(std::string state);

    bool is_opened();

private:
    void cycle_state(int& counter);

    bool opened;
    std::string state;
};

GarageDoor::GarageDoor() : opened(false), state("CLOSED")
{}

void GarageDoor::show_state()
{
    std::cout << state;
}

void GarageDoor::set_state(std::string state)
{
    this->state = state;
}

bool GarageDoor::is_opened()
{
    return opened;
}

void GarageDoor::cycle_state(int& counter)
{
    switch(counter)
    {
    case 0: // CLOSED
        counter += 1;
    case 1: // OPENING
    case 2: // STOPPED WHILE OPENING
    case 3: // OPENED
    case 4: // CLOSING
    case 5: // STOPPED WHILE CLOSING
    default:
        break;
    }
}

int main()
{
    int cycle_counter = 0;

    for (int i = 0; i < 6; i++)
    {
        
    }

    return 0;
}

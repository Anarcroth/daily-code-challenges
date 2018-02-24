#!bin/python3

class node:
    def __init__(self, init_key):
        self.key = init_key;
        self.next = None;

    def get_key(self):
        return self.key;

    def get_next(self):
        return self.next;

    def set_key(self, key):
        self.key = key;

    def set_next(self, _next):
        self.next = _next;

class linked_list:
    def insert_position(val, pos):
        previous = node();
        temp = node();

        current = None;

        current = head;

        for i in range(1, pos):
            previous = current;
            current = current._next;

        temp.key = val;
        previous._next = temp;
        temp._next = current;

    def delete_position(pos):
        current = head;
        previous = node();

        for i in range(1, pos):
            previous = current;
            currnet = currnet._next;

        previous._next = current._next;

        del currnet;

    def insert_start(val):
        temp = node();
        temp.key = val;
        temp._next = head;
        head = temp;

    def insert_node(val):
        temp = node();
        temp.key = val;
        temp._next = None;

        if head is None:
            head = temp;
            tail = temp;
            temp = None;
        else:
            temp._next = temp;
            tail = temp;
            temp = None;

    def delete_first():
        temp = None;
        temp = head;
        head = head_next;

        del temp;

    def delete_last():
        current = None;
        previous = node();
        current = head;
        while current._next is not None:
            previous = current;
            currnet = current._nextl

        tail = previous;
        previous._next = None;

        del current;

    def display():
        temp = head;

        while temp is not None:
            print(temp.key);
            temp = temp._next;

    head = node;
    tail = node;


if __name__ == "__main__":
    ll = linked_list();

    answer = 1;
    elem = 0;
    pos = 0;

    print("1. Insert element to the list.");
    print("2. Insert element at a position.");
    print("3. Display contents of the list.");
    print("4. Delete element at a position.");
    print("5. Quit.");

    while answer is not 0:
        #answer = input("Enter action: ");

        if answer == 1:
            elem = input("Enter an element: ");
            ll.insert_node(elem);

        elif answer == 2:
            elem = input("Enter an element: ");
            pos = input("Enter a position: ");
            ll.insert_position(elem, pos);

        elif answer == 3:
            ll.display();

        elif answer == 4:
            pos = input("Enter a position to delete: ");
            ll.delete_position(pos);

        elif answer == 5:
            answer = 0;

#!bin/python3

class node:
    def __init__(self, key):
        self._key = key;
        self._next = None;

    def get_key(self):
        return self._key;

    def get_next(self):
        return self.next;

    def set_key(self, key):
        self._key = key;

    def set_next(self, n_next):
        self._next = n_next;

class linked_list:
    def __init__(self, head, tail):
        self._head = head;
        self._tail = tail;

    def insert_position(val, pos):
        _prev = node();
        _tmp = node();

        _cur = None;

        _cur = head;

        for i in range(1, pos):
            _prev = _cur;
            _cur = _cur._next;

        _tmp.key = val;
        _prev._next = _tmp;
        _tmp._next = _cur;

    def delete_position(pos):
        _cur = head;
        _prev = node();

        for i in range(1, pos):
            _prev = _cur;
            _cur = _cur._next;

        _prev._next = _cur._next;

        del currnet;

    def insert_start(val):
        _tmp = node();
        _tmp.key = val;
        _tmp._next = head;
        head = _tmp;

    def insert_node(val):
        _tmp = node();
        _tmp.key = val;
        _tmp._next = None;

        if head is None:
            head = _tmp;
            tail = _tmp;
            _tmp = None;
        else:
            _tmp._next = _tmp;
            tail = _tmp;
            _tmp = None;

    def delete_first():
        _tmp = None;
        _tmp = head;
        head = head_next;

        del _tmp;

    def delete_last():
        _cur = None;
        _prev = node();
        _cur = head;
        while _cur._next is not None:
            _prev = _cur;
            currnet = _cur._nextl

        tail = _prev;
        _prev._next = None;

        del _cur;

    def display():
        _tmp = head;

        while _tmp is not None:
            print(_tmp.key);
            _tmp = _tmp._next;

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

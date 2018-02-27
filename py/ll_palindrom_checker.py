#!bin/python3

class node:
    def __init__(self, key):
        self._key = key;
        self._next = None;

    def get_key(self):
        return self._key;

    def get_next(self):
        return self._next;

    def set_key(self, key):
        self._key = key;

    def set_next(self, n_next):
        self._next = n_next;

class linked_list:
    def __init__(self):
        self._head = None;
        self._tail = None;

    def insert_position(self, val, pos):
        _prev = None;
        _cur = self._head;

        for i in range(1, int(pos)):
            _prev = _cur;
            _cur = _cur.get_next();

        _tmp = node(val);
        _prev.set_next(_tmp);
        _tmp.set_next(_cur);

    def delete_position(self, pos):
        _cur = self._head;
        _prev = None;

        for i in range(1, int(pos)):
            _prev = _cur;
            _cur = _cur.get_next();

        _prev.set_next(_cur.get_next());

    def insert_start(self, val):
        _tmp = node(val);
        _tmp.set_next(self._head);
        self._head = _tmp;

    def insert_node(self, val):
        _tmp = node(val);

        if self._head is None:
            self._head = _tmp;
            self._tail = _tmp;
        else:
            self._tail.set_next(_tmp);
            self._tail = _tmp;

    def delete_first(self):
        _tmp = self._head;
        self._head = self._head.get_next();

    def delete_last(self):
        _prev = None;
        _cur = self._head;
        while _cur.get_next() is not None:
            _prev = _cur;
            _cur = _cur.get_next();

        self._tail = _prev;
        _prev.set_next(None);

    def display(self):
        _tmp = self._head;

        while _tmp is not None:
            print(_tmp.get_key());
            _tmp = _tmp.get_next();

def check_for_pal(linked_list):
    _tmp = linked_list._head;

    tmp_ll_vals = [];
    while _tmp is not None:
        tmp_ll_vals.append(_tmp.get_key());
        _tmp = _tmp.get_next();

    for index, n in enumerate(tmp_ll_vals):
        if n == tmp_ll_vals[len(tmp_ll_vals) - index - 1]:
            print(n, " - ", tmp_ll_vals[len(tmp_ll_vals) - index - 1]);

        if index == int(len(tmp_ll_vals) / 2):
            break;

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
        answer = int(input("Enter action: "));

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

    check_for_pal(ll);

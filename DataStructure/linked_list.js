class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor(head = null, size = 0, tail = null) {
        this.head = head;
        this.size = size;
        this.tail = tail;
    }

    append(data) {
        if (this.head === null) {
            this.head = new Node(data);
            this.tail = this.head;
            ++this.size;
            return;
        }

        let last = this.tail;
        last.next = new Node(data);
        this.tail = last.next;

        ++this.size;
    }

    prepend(data) {
        const newHead = new Node(data);
        newHead.next = this.head;
        this.head = newHead;
        ++this.size;
    }

    at(index) {
        if (index >= this.size) {
            return null;
        }

        let current = this.head;
        for (let i = 0; i < index; ++i) {
            current = current.next;
        }

        return current;
    }

    containes(data) {
        let current = this.head;
        while (current !== null) {
            if (current.data === data) {
                return true;
            }
            current = current.next;
        }

        return false;
    }

    find(data) {
        // return index of data
        let current = this.head;
        let index = 0;
        while (current !== null) {
            if (current.data === data) {
                return index;
            }
            current = current.next;
            ++index;
        }
    }

    // toString for debugging
    toString() {
        // represent it like ( value ) -> ( value ) -> ( value ) -> null
        let current = this.head;
        let str = "";
        while (current !== null) {
            str += `(${current.data}) -> `;
            current = current.next;
        }
        str += "null";
        return str;
    }
}

const list = new LinkedList();
list.append(1);
list.append(2);
list.append(3);
list.append(4);
list.append(5);
list.prepend(0);
console.log(list.toString());
console.log(list.at(3));
console.log(list.containes(3));
console.log(list.find(3));
console.log(list.find(10));
console.log(list.toString());

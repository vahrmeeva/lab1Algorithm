#include <iostream>

using namespace std;

class Node { //класс одного объекта, узла
public:
    int data; // значение переменной
    Node* next; //ссылка на первый элемент
};

class LinkedList {
public:
    LinkedList() { //конструктор
        head = nullptr; //присваиваем первому элементу пустоту
    }

    //добавление элемента в начало списка
    void addAtBeginning(int data) { //принимает значение элемента
        Node* newNode = new Node(); //создаем временную переменную
        newNode->data = data; // указатель дата к нему присваиваем значение дата
        newNode->next = head; //и следовательно передаем в том узле ссылку на первый элемент
        head = newNode;
    }

    //добавление элемента в конец списка
    void addAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data; //передаем ей значение дата  и ссылку на след элемент пустую!, так как последний элемент
        newNode->next = nullptr;

        if (head == nullptr) { // если голова пустая
            head = newNode; // просто присваиваем хед нашу переменную
            return;
        }

        Node* current = head; //временная переменная
        while (current->next != nullptr) { //пока мы не долли до конца списка
            current = current->next; //двигаемся по списку
        }

        current->next = newNode; // добавляем элемент в конец списка
    }

    void print() {
        Node* current = head; //присваиваем временной переменной значение головы
        while (current != nullptr) { //пока этоот элемент существует
            cout << current->data << " ";
            current = current->next; // идем к следующему элементу
        }
        cout << endl;
    }

    //добавление элемента по индексу
    void addAtPosition(int data, int position) {
        Node* newNode = new Node();  // временная переменная
        newNode->data = data;
        newNode->next = nullptr;

        if (position == 0) { // если это 0ой элемент, то в нашей временной переменной мы вкладываем ссылку на голову, и голова теперь по значению равна нашей переменной
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++) { //проверка , корректный ли у нас указан узел в current и не вышел ли индекс за рамки нашего списка
            current = current->next;// если все хорошо, то current ссылается на следующий элемент
        }

        if (current == nullptr) { // если он пустой , то позиция не входит на список
            cout << "Position out of range" << endl;
            return;
        }

        newNode->next = current->next; // здесь мы как раз добавляем этот элемент
        current->next = newNode;
    }



    //удаление по индексу
    void removeByIndex(int index) {
        if (head == nullptr) { // если голова пустая, то ничего не происходит
            return;
        }

        Node* current = head; // у current значение голова

        if (index == 0) {
            head = head->next; // перемещаем голову на след элемент
            delete current; // удаляем, то что запрашивалось
            return;
        }

        for (int i = 0; current != nullptr && i < index - 1; i++) { // проверка на то что мы не дошли до конца  и на то, что позиция не выходит за список
            current = current->next; //переходим к следующему узлу списка
        }

        if (current == nullptr || current->next == nullptr) {
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Метод для поиска элемента по значению
    int searchByValue(int value, Node** node) {
        *node = head;

        // Итерируемся по списку, пока не найдем элемент или не достигнем конца списка
        while (*node != nullptr) {
            if ((*node)->data == value) {
                return 1;
            }

            *node = (*node)->next;
        }
    }

    //поиск по позиции
    int findAt(int pos) {
        if (pos < 0 ) {
            cout << "Invalid position!" << endl;
            return -1;//проверка на неправильную позицию
        }

        Node* curr = head;//указаелю присваиваем значение головы
        int i = 0;

        while (curr != nullptr && i < pos) { //
            curr = curr->next;
            i++;
        }

        if (curr == nullptr) {
            cout << "Element not found!" << endl;
            return -1;
        }

        return curr->data;
    }

//удалить 1 элемент
    void removeHead() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeByValue(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            removeHead();
            return;
        }

        Node* current = head;
        //ищем элемент со значанеием data в списке пока не дойдем до конца списка или не найдем элемент с нужным значением
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* nodeToRemove = current->next;
            current->next = current->next->next;
            delete nodeToRemove;
        }
    }


private:
    Node* head;
};

int main() {
    LinkedList ll;
    int choice, data, position;
    while (true) {
        cout << "1. Add to end" << endl;
        cout << "2. Add to start" << endl;
        cout << "3. Add at position" << endl;
        cout << "4. Remove by value" << endl;
        cout << "5. Remove by position" << endl;
        cout << "6. Search by value" << endl;
        cout << "7. Search by position" << endl;
        cout << "8. Display all elements" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the data: ";
                cin >> data;
                ll.addAtEnd(data);
                break;
            case 2:
                cout << "Enter the data: ";
                cin >> data;
                ll.addAtBeginning(data);
                break;
            case 3:
                cout << "Enter the data: ";
                cin >> data;
                cout << "Enter the position: ";
                cin >> position;
                ll.addAtPosition(data, position);
                break;
            case 4:
                cout << "Enter the data: ";
                cin >> data;
                ll.removeByValue(data);
                break;
            case 5:
                cout << "Enter the position: ";
                cin >> position;
                ll.removeByIndex(position);
                break;
            case 6:
                cout << "Enter the data: ";
                cin >> data;
                Node* node;
                ll.searchByValue(data, &node);
                if (node == nullptr) {
                    cout << "Element with value " << data << " not found." << endl;
                } else {
                    cout << "Element with value " << data << " found." << endl;
                }
                position = ll.searchByValue(data, &node);
                if (position == -1) {
                    cout << "Element not found" << endl;
                } else {
                    cout << "Element found at position " << position << endl;
                }
                break;
            case 7:
                cout << "Enter the position: ";
                cin >> position;
                data = ll.findAt(position);
                cout << "Element at position " << position << " is " << data << endl;
                break;
            case 8:
                ll.print();
                break;
            case 9:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}

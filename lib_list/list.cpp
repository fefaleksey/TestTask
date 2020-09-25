#include <vector>
#include <map>

#include "list.h"


void List::Serialize(FILE *file) {
    if (!file) {
        throw std::invalid_argument("Pointer on file cannot be nullptr");
    }

    size_t blocks_written = fwrite(&this->count, sizeof(this->count), 1, file);

    if (blocks_written != 1) {
        throw std::invalid_argument("Cannot write data in the file");
    }

    ListNode *current_node = head;

    // <Address, index>
    std::map<ListNode *, int> nodes;
    for (int i = 0; i < this->count; i++, current_node = current_node->next) {
        nodes.insert(std::pair<ListNode *, int>(current_node, i));
        // we take current_node->data.length() + 1 because we need to write '\0'
        size_t size = (current_node->data.length() + 1);
        blocks_written = fwrite(
                current_node->data.data(),
                sizeof(*current_node->data.data()),
                (current_node->data.length() + 1),
                file);

        if (blocks_written != size) {
            throw std::invalid_argument("Cannot write data in the file");
        }
    }

    current_node = head;
    for (int i = 0; i < this->count; i++, current_node = current_node->next) {

        int index = -1;
        if (current_node->rand != nullptr) {
            auto index_pair = nodes.find(current_node->rand);
            index = index_pair->second;
        }

        size_t size = sizeof(int);
        blocks_written = fwrite(&index, size, 1, file);

        if (blocks_written != 1) {
            throw std::invalid_argument("Cannot write data in the file");
        }
    }
}

void ReadStringFromFile(FILE *file, std::string& str) {
    int c = 1;
    while (c != '\0') {
        c = fgetc(file);
        if (c == EOF) {
            throw std::invalid_argument("Incorrect file");
        }
        str.push_back(c);
    }

    // pop '\0'
    str.pop_back();
}

void List::Deserialize(FILE *file) {
    if (!file) {
        throw std::invalid_argument("Pointer on file cannot be nullptr");
    }

    size_t blocks_read = fread(&this->count, sizeof(count), 1, file);

    if (blocks_read != 1) {
        throw std::invalid_argument("Cannot write data in the file");
    }

    if (this->count == 0) {
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }

    auto *current_node = new ListNode();
    current_node->prev = nullptr;
    current_node->next = nullptr;
    current_node->rand = nullptr;
    this->head = current_node;

    // <Address, index>
    std::map<int, ListNode *> nodes;

    this->tail = current_node;
    nodes.insert(std::pair<int, ListNode *>(0, current_node));

    ReadStringFromFile(file, current_node->data);

    for (int i = 1; i < this->count; i++) {
        auto *next_node = new ListNode();
        current_node->next = next_node;
        next_node->prev = current_node;
        current_node = next_node;

        this->tail = current_node;
        nodes.insert(std::pair<int, ListNode *>(i, current_node));

        ReadStringFromFile(file, current_node->data);
    }

    current_node = head;
    for (int i = 0; i < this->count; i++) {

        int index;
        size_t size = sizeof(int);
        blocks_read = fread(&index, size, 1, file);

        if (blocks_read != 1) {
            throw std::invalid_argument("Incorrect file");
        }

        auto index_pair = nodes.find(index);
        current_node->rand = index_pair->second;
        current_node = current_node->next;
    }
}

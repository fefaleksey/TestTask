#include "list_tests.h"

// This is the simplest and dumbest way to access a private field.
// It is better to use "friend", but for a this task it is ok.
#define private public
#include "list.h"



void ListTest::SetUp() {}

void ListTest::TearDown() {}

TEST_F(ListTest, Empty) {
    List list = List();
    FILE *file = fopen("testfile.txt", "wb");
    list.Serialize(file);
    fclose(file);
    file = fopen("testfile.txt", "rb");
    list.Deserialize(file);
    fclose(file);

    EXPECT_TRUE(list.head == nullptr);
    EXPECT_TRUE(list.tail == nullptr);
    EXPECT_TRUE(list.count == 0);

    ListNode node = ListNode();
    list.head = &node;
    list.tail = &node;
    list.count = 1;

    remove("testfile.txt");
}

TEST_F(ListTest, OneNode) {
    List list = List();

    ListNode node = ListNode();
    node.prev = nullptr;
    node.next = nullptr;
    node.rand = nullptr;
    node.data = "SE CS WE LOVE IT";

    list.head = &node;
    list.tail = &node;
    list.count = 1;

    FILE *file = fopen("testfile.txt", "wb");
    list.Serialize(file);
    fclose(file);
    file = fopen("testfile.txt", "rb");
    list.Deserialize(file);
    fclose(file);

    EXPECT_TRUE(list.head->rand == nullptr);
    EXPECT_TRUE(list.head->next == nullptr);
    EXPECT_TRUE(list.head->prev == nullptr);

    EXPECT_TRUE(list.head == list.tail);
    EXPECT_TRUE(list.count == 1);

    std::string expected("SE CS WE LOVE IT");
    EXPECT_EQ(expected, list.head->data);
}

TEST_F(ListTest, TwoNodes) {
    List list = List();

    ListNode node1 = ListNode();
    ListNode node2 = ListNode();

    node1.prev = nullptr;
    node1.next = &node2;
    node1.rand = &node2;
    node1.data = "SE CS WE LOVE IT";

    node2.prev = &node1;
    node2.next = nullptr;
    node2.rand = &node2;
    node2.data = "MATMEX is the best";

    list.head = &node1;
    list.tail = &node2;
    list.count = 2;

    FILE *file = fopen("testfile.txt", "wb");
    list.Serialize(file);
    fclose(file);
    file = fopen("testfile.txt", "rb");
    list.Deserialize(file);
    fclose(file);

    EXPECT_TRUE(list.head != list.tail);
    EXPECT_TRUE(list.count == 2);

    std::string expected1("SE CS WE LOVE IT");
    std::string expected2("MATMEX is the best");
    EXPECT_EQ(expected1, list.head->data);
    EXPECT_EQ(expected1, list.tail->prev->data);
    EXPECT_EQ(expected1, list.head->next->prev->data);
    EXPECT_EQ(expected2, list.head->next->data);
    EXPECT_EQ(expected2, list.tail->data);
    EXPECT_EQ(expected2, list.tail->prev->next->data);

    EXPECT_EQ(expected2, list.head->rand->data);
    EXPECT_EQ(expected2, list.tail->rand->data);
}

TEST_F(ListTest, ThreeNodes) {
    List list = List();

    ListNode node1 = ListNode();
    ListNode node2 = ListNode();
    ListNode node3 = ListNode();

    node1.prev = nullptr;
    node1.next = &node2;
    node1.rand = &node2;
    node1.data = "SE CS WE LOVE IT";

    node2.prev = &node1;
    node2.next = &node3;
    node2.rand = nullptr;
    node2.data = "MATMEX is the best";

    node3.prev = &node2;
    node3.next = nullptr;
    node3.rand = &node1;
    node3.data = "Biba i Boba dva kruasana";

    list.head = &node1;
    list.tail = &node3;
    list.count = 3;

    FILE *file = fopen("testfile.txt", "wb");
    list.Serialize(file);
    fclose(file);
    file = fopen("testfile.txt", "rb");
    list.Deserialize(file);
    fclose(file);

    EXPECT_TRUE(list.head != list.tail);
    EXPECT_TRUE(list.count == 3);

    std::string expected1("SE CS WE LOVE IT");
    std::string expected2("MATMEX is the best");
    std::string expected3("Biba i Boba dva kruasana");

    EXPECT_EQ(nullptr, list.head->prev);

    EXPECT_EQ(expected1, list.head->data);
    EXPECT_EQ(expected2, list.tail->prev->data);
    EXPECT_EQ(expected1, list.head->next->prev->data);
    EXPECT_EQ(expected2, list.head->next->data);

    EXPECT_EQ(expected3, list.tail->data);
    EXPECT_EQ(expected3, list.tail->prev->next->data);
    EXPECT_EQ(expected3, list.head->next->next->data);

    EXPECT_EQ(nullptr, list.tail->next);
    EXPECT_EQ(expected2, list.tail->prev->data);
    EXPECT_EQ(expected1, list.tail->prev->prev->data);

    EXPECT_EQ(expected2, list.head->rand->data);
    EXPECT_EQ(nullptr, list.head->next->rand);
    EXPECT_EQ(expected1, list.head->next->next->rand->data);
}
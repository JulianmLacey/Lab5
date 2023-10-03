#include "header.h"

/*
Task 1
a. Yes, on line 2 a pointer to a read-only integer is declared. While on line 3 a read only pointer is declared to an integer.
b. No, the operation on line 6 is not allowed because the variable is read only.
c. Yes, the operation on line 7 is allowed because the pointer is not read only.
d. No, the operation on line 8 is not allowed because the pointer is read only.
e. Yes, the operation on line 9 is allowed because the pointer is not read only.
f. Yes, the operation on line 10 is allowed because the array is allocated.
g. Yes, the operation on line 11 is legal because the list pointer is just a pointer to some memory,
    which can be set to the address of n1.
h. No, the operation on line 12 is not legal because because p4 is read only.
i. No the operation on line 13 is not legal because the value of p4 is also read only.

Task 7
For all the below questions it depends on the implementation of the linked list and array. And what you mean by effecient. Since the questions say in general, im going to assume were talking about the worst case time complextiy, and space complextiy is ignored.
Since id rather use all my memory than wait. However if memory usage matters more, just avoid linked lists all together. Since they use far more memory for pointers, and vary dramaticlly, typically 5X more memory than an array.

Im going to answer all of these questions at once since i started and was typing the same thing over and over. And re arrange them.

Insert/Delete at front: Linked lists are more effecient (like the only benefit of them), since you dont have to shift the elements in the array. O(1) vs O(n)
Insert/Delete at end: Linked lists far less effecient unless you have a pointer to the end of the list, since you dont have to traverse the entire list. O(1) vs O(n) if no pointer. O(1) vs O(1) if pointer.
Insert/Delete at middle: Arrays are more effecient for a few reasons, despite having to shift the elements. First, Arrays are stored in contiguous memory which makes accessing/traversing take far less CPU operations per element,
    while linked lists are not continous which can result in hundreds (thousands if you have many inderections, accessings a struct to a struct to a struct ect.) of instructions which result far more cache misses as its much more
    difficult to optimize cache accesses and memory traversal patters. Second, assuming were inserting because the list is sorted, searching a continous block of memory with an array is much faster O(logn) which can often offset
    the number of operations required to shift the array. Textbook worst case: O(n) vs O(n). Searching O(logn) vs O(n). If unsorted their both O(n). Arrays are still more effecient for 99% of use cases.

To access an element in general an array is faster, Binary search is much faster than traversing a list. O(logn) O(n). Since its stored in contiguous memory, less cpu cycles, cache optimized.

Use linkedlist when: often inserting/deleting at the front, and have "few" elemets. The extremly rare case you are unable to allocate a contiguous block of memory, and prefer to use more total memory.

Use array when: everything else

How i assume the question should be answered:
a. Array, O(1) vs O(n) (O(1) if pointer to end)
b. Linked List O(1) vs O(n)(shifting)
c. Same O(n) (Array because searching is faster if sorted)
d. Array, O(1) vs O(n) (O(1) if pointer to end)
e. Linked list, O(1) vs O(n)
f. c. Same O(n) (Array because searching is faster if sorted)
g. Array O(logn) vs O(n)

*/
char *copyStrToHeap(char *pStr) {
    char *str = (char *)malloc(strlen(pStr) + 1);
    if (!str) return NULL;
    strcpy(str, pStr);
    return str;
}

void task2() {
    char *src = "Hello World";
    char *nStr = copyStrToHeap(src);
    printf("Origional: %s\n", src);
    printf("Copied to heap: %s\n", nStr);
    free(nStr);
}

Node *getNextNode(const Node **pList) {
    Node *listIndex = *pList;
    Node **minNode = pList;
    int found = 0;
    while (listIndex->data != NULL) {
        if (!(listIndex)) {
            listIndex++;
            continue;
        }
        if (listIndex->data < (*minNode)->data) {
            minNode = &listIndex;
            found++;
        }

        listIndex++;
    }
    if (!found) return NULL;
    listIndex = *minNode;
    *minNode = (*minNode)->next;
    return *minNode;
}

Node *mergeLists(Node **pList) {
    /*
    -------getNextNode
    loop over array of lists
        if current data = NULL
            continue
        else
            increse found variable

        if the current data is less than the min data
            set the min to the current list
            contunue through array

    if !found
        return NULL

    set the newlist pointer next to the min node
    set the newlist pointer to the min node
    set the pointer in the lists array to the next element.
    ----------
    while (lst=getnextnode)
    return merged list

    */
}

void printList(Node *list) {
    Node *listIndex = list;
    while (listIndex) {
        printf("%d\n", listIndex->data);
        listIndex = listIndex->next;
    }
}

void task3() {
    Node n13 = (Node){5, NULL};
    Node n12 = (Node){3, &n13};
    Node n11 = (Node){1, &n12};

    Node n23 = (Node){6, NULL};
    Node n22 = (Node){4, &n23};
    Node n21 = (Node){2, &n22};

    Node terminate = (Node){NULL, NULL};

    Node *nList[] = {&n11, &n21, &terminate};
    // printList(&mergeLists(&nList));
}

int detectLoop(Node *root) {
    Node *p1 = root;
    Node *p2 = root;
    while (p1 && p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) return 1;
    }
    return 0;
}
void task5() {
    Node n15 = (Node){3, NULL};
    Node n14 = (Node){1, &n15};
    Node n13 = (Node){5, &n14};
    Node n12 = (Node){3, &n13};
    Node n11 = (Node){1, &n12};
    printf("%s\n", detectLoop(&n11) ? "Loop" : "No Loop");
    n13.next = &n11;
    printf("%s\n", detectLoop(&n11) ? "Loop" : "No Loop");
}
void reverseList(Node **pList) {
    Node *cN = *pList;
    Node *nN = NULL;
    Node *pN = NULL;
    while (cN != NULL) {
        nN = cN->next;
        cN->next = pN;
        pN = cN;
        cN = nN;
    }
    *pList = pN;
}

void task6() {
    Node n13 = (Node){5, NULL};
    Node n12 = (Node){3, &n13};
    Node n11 = (Node){1, &n12};
    Node *fn = &n11;
    printList(&n11);
    reverseList(&fn);
    printList(&n13);
}

int main(void) {
    task5();
    return 0;
}
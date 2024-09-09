/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
// Step 1: Calculate the length of the linked list
    int length = 0;
    struct ListNode* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    // Step 2: Calculate the size of each part and the number of extra nodes
    int base_size = length / k;
    int extra = length % k;

    // Step 3: Allocate memory for the result array
    struct ListNode** result = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    *returnSize = k;

    // Step 4: Split the list
    current = head;
    for (int i = 0; i < k; i++) {
        result[i] = current;
        int part_size = base_size + (i < extra ? 1 : 0);

        // Move to the end of this part
        for (int j = 0; j < part_size - 1 && current != NULL; j++) {
            current = current->next;
        }

        // Cut off this part from the rest of the list
        if (current != NULL) {
            struct ListNode* next = current->next;
            current->next = NULL;
            current = next;
        }
    }

    return result;
}

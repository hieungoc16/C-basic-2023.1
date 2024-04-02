
int isComplete(char v, int index, int count) {
    Node *r = find(root, v);
    if (r == NULL) return 1;

    if (index >= count) return 0;

    return (isComplete(r->leftChild -> id, 2 * index + 1, count) &&
            isComplete(r->rightChild -> id, 2 * index + 2, count));
}

int isBalanced(char v) {
    Node *r = find(root, v);
    if (r == NULL) return 1;

    int leftHeight = height(r->leftChild);
    int rightHeight = height(r->rightChild);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(r->leftChild->id) && isBalanced(r->rightChild->id))
        return 1;

    return 0;
}
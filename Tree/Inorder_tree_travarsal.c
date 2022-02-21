#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node *left;
    Node *right;
};
Node *create_node(int item)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("error! Could not create A new Node\n");
        exit(1);
    }
    new_node-> data = item;
    new_node-> left = NULL;
    new_node-> right = NULL;
    return new_node;
}
void add_left_child(Node *node, Node *child)
{
    node->left = child;
}
void add_right_child(Node *node, Node *child)
{
    node->right = child;
}
Node *create_tree()
{
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left_child(two, seven);
    add_right_child(two, nine);

    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_child(seven, one);
    add_right_child(seven, six);

    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left_child(six, five);
    add_right_child(six, ten);

    Node *eight = create_node(8);
    add_right_child(nine, eight);

    Node *three = create_node(3);
    Node *four = create_node(4);
    add_left_child(eight, three);
    add_right_child(eight, four);
    return two;
}
Node *bst_search(Node *root, int item)
{
    Node *node = root;
    while (node != NULL)
    {
        if(node -> data == item)
        {
            return node;
        }
        if(item < node -> data)
        {
            node = node -> left;
        }
        else
        {
            node = node -> right;
        }
    }
    return node;
}
Node *bst_minimum(Node *root)
{
    Node *node = root;
    while (node -> left != NULL)
    {
        node = node -> left;
    }
    return node;
}
Node *bst_transplant(Node *root, Node *current_node, Node *new_node)
{
    if(current_node == root)
    {
        root = new_node;
    }
    else if(current_node == current_node->parent->left)
    {
        add_left_child(current_node->parent, new_node);
    }
    else
    {
        add_right_child(current_node->parent, new_node);
    }
    return root;
}

Node *bst_delete(Node *root, Node *node)
{
    Node *smallest_node;
    if(node -> left == NULL)
    {
        root = bst_transplant(root, node, node -> right);
    }
    else if (node -> right == NULL)
    {
        root = bst_transplant(root, node, node -> left);
    }
    else
    {
        smallest_node = bst_minimum(node -> right);
        if(smallest_node -> parent != node)
        {
            root = bst_transplant(root, smallest_node, smallest_node -> right);
            add_right_child(smallest_node, node -> right);
        }
        root = bst_transplant(root, node, smallest_node);
        add_left_child(smallest_node, node -> left);
    }
    free(node);
    return root;
}
int main()
{
    Node *root = create_bst();
    Node *node;
    printf("BST:\n");
    in_order(root);
    printf("\n");
    node = bst_search(root, 1);
    if(node != NULL)
    {
        printf("Will delete %d\n", node -> data);
        root = bst_delete(root, node);
        printf("BST:\n");
        in_order(root);
        printf("\n");
    }
    else
    {
        printf("Node not found!\n");
    }
    node = bst_search(root, 5);
    if(node != NULL)
    {
        printf("Will delete %d\n", node -> data);
        root = bst_delete (root, node);
        printf("BST:\n");
        in_order (root);
        printf("\n");
    }
    else
    {
        printf("Node not found!\n");
    }
    node = bst_search(root, 10);
    if(node != NULL)
    {
        printf("Will delete %d\n", node -> data);
        root = bst_delete(root, node);
        printf("BST:\n");
        in_order(root);
        printf("\n");
    }
    else
    {
        printf("Node not found!");
    }
    return 0;
}

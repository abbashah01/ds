#include <iostream>
#include <string>
using namespace std;

// Node represents one product
struct Node
{
    string productID;
    Node* next;
};

// Add a product at the end
void addProduct(Node*& head, string productID)
{
    Node* newNode = new Node;

    newNode->productID = productID;
    newNode->next = nullptr;

    // If cart is empty
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        // Go to the last product
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        // Add product at the end
        temp->next = newNode;
    }
}

// Display all products
void displayCart(Node* head)
{
    Node* temp = head;

    cout << "Shopping Cart: ";

    while (temp != nullptr)
    {
        cout << temp->productID;

        if (temp->next != nullptr)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

// Remove a product using Product ID
void removeProduct(Node*& head, string productID)
{
    if (head == nullptr)
    {
        cout << "Cart is empty." << endl;
        return;
    }

    // If the first product needs to be removed
    if (head->productID == productID)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    // Search for the product
    while (temp->next != nullptr)
    {
        if (temp->next->productID == productID)
        {
            Node* deleteNode = temp->next;

            temp->next = temp->next->next;

            delete deleteNode;

            return;
        }

        temp = temp->next;
    }

    cout << "Product Not Found" << endl;
}

int main()
{
    Node* head = nullptr;

    // Add products
    addProduct(head, "P101");
    addProduct(head, "P205");
    addProduct(head, "P310");
    addProduct(head, "P415");

    // Display original cart
    displayCart(head);

    // Remove product
    string productID;

    cout << "Remove Product: ";
    cin >> productID;

    removeProduct(head, productID);

    // Display updated cart
    cout << "Updated Cart: ";
    displayCart(head);

    return 0;
}

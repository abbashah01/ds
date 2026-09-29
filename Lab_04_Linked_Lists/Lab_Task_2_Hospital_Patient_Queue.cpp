#include <iostream>
#include <string>
using namespace std;

// Node represents one patient
struct Node
{
    string patientID;
    Node* next;
};

// Add a patient at the end of the queue
void addPatient(Node*& head, string patientID)
{
    Node* newNode = new Node;

    newNode->patientID = patientID;
    newNode->next = nullptr;

    // If the queue is empty
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        // Go to the last patient
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        // Add new patient at the end
        temp->next = newNode;
    }
}

// Display all patients
void displayPatients(Node* head)
{
    Node* temp = head;

    cout << "Waiting Patients: ";

    while (temp != nullptr)
    {
        cout << temp->patientID;

        if (temp->next != nullptr)
        {
            cout << " -> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

// Remove the first patient
void removeFirstPatient(Node*& head)
{
    if (head == nullptr)
    {
        cout << "No patients waiting." << endl;
        return;
    }

    Node* temp = head;

    cout << "Patient " << head->patientID << " is being served." << endl;

    head = head->next;

    delete temp;
}

int main()
{
    Node* head = nullptr;

    // Add patients
    addPatient(head, "P101");
    addPatient(head, "P102");
    addPatient(head, "P103");
    addPatient(head, "P104");

    // Display original queue
    displayPatients(head);

    // Remove first patient
    removeFirstPatient(head);

    // Display updated queue
    cout << "Updated Queue: ";
    displayPatients(head);

    return 0;
}

#include<iostream>
#include<math.h>
using namespace std;

#define max1 20

class stud {
public:
    int marks[max1], total;

    stud() {
        for (int i = 0; i < max1; i++)
            marks[i] = 0;
    }

    void createHeap();
    void displayHeap();
    void showmax();
    void showmin();
};

void stud::createHeap() {
    int i, j, par, temp, M;
    cout << "\nEnter How many Students: ";
    cin >> total; //5
    for (i = 0; i < total; i++) { //0-4=5 times
        cout << "\nEnter Marks: ";
        cin >> marks[i];
        M = marks[i];
        j = i; //j is child
        par = floor((j - 1) / 2);
        while (marks[j] < marks[par] && j != 0) {
            temp = marks[j];
            marks[j] = marks[par];
            marks[par] = temp;
            j = par;
            par = floor((j - 1) / 2);
        }
        cout << "\n\nCurrent Heap: After Inserting: " << M << " is:\n";
        displayHeap();
    }
}

void stud::displayHeap() {
    int i = 0, space = 6;
    cout << endl;
    while (i < total) {
        if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15) {
            cout << endl << endl;
            for (int j = 0; j < space; j++)
                cout << " ";
            space -= 2;
        }
        cout << " " << marks[i];
        i++;
    }
}

void stud::showmin() {
    cout << marks[0];
}

void stud::showmax() {
    int max, i;
    max = marks[0];
    for (i = 1; i < total; i++) {
        if (max < marks[i])
            max = marks[i];
    }
    cout << max;
}

int main() {
    stud s1;
    int ch, ans;
    do {
        cout << "\n1. Insert Marks";
        cout << "\n2. Display Marks";
        cout << "\n3. Show Max Marks";
        cout << "\n4. Show Min Marks";
        cout << "\n\nEnter Your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                s1.createHeap();
                break;
            case 2:
                s1.displayHeap();
                break;
            case 3:
                s1.showmax();
                break;
            case 4:
                s1.showmin();
                break;
        }
        cout << "\nDo you want to continue? (1 for continue): ";
        cin >> ans;
    } while (ans == 1);
    return 0;
}


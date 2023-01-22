#include <iostream>
#include <stdlib.h>

using namespace std;

int step = 1;

void allRingOn(int N);
void allRingOff(int N);
void printStep(int N, int action);

void allRingOn(int N) // take on 1~N-th rings
{
    if (N > 2)
    {
        allRingOn(N - 1);
        allRingOff(N - 2);
        printStep(N, 2); // take on N-th ring
        allRingOn(N - 2);
    }
    else if (N == 2) // take on ring 1 and ring 2;
    {
        cout << "Step " << step << ": Take on ring 1 and ring 2 together\n";
        step++;
    }
    else if (N == 1)
    {
        printStep(N, 2);
    }
}

void allRingOff(int N) // take off 1~N-th rings
{
    if (N > 2)
    {
        allRingOff(N - 2);
        printStep(N, 1); // take off N-th ring
        allRingOn(N - 2);
        allRingOff(N - 1);
    }
    else if (N == 2) // take off ring 1 and ring 2;
    {
        cout << "Step " << step << ": Take off ring 1 and ring 2 together\n";
        step++;
    }
    else if (N == 1)
    {
        printStep(N, 1);
    }
}

void printStep(int N, int action)
{
    if (action == 1)
    { // take off
        cout<<"Step "<<step<<": Take off ring "<<N<<endl;
    }
    else
    { // take on
        cout<<"Step "<<step<<": Take on ring "<<N<<endl;
    }

    step++;
}

int main(void)
{
    int N, action;
    cout << "What is the number of rings? : ";
    cin >> N;
    cout << "(1)Take off or (2)Take on : ";
    cin >> action;

    cout << "n=" << N << " d=" << action << endl;

    if (action == 1)
    {
        allRingOff(N);
    }
    else if (action == 2)
    {
        allRingOn(N);
    }
    else
    {
        cout << "There is no other action\n";
    }

    system("pause");
    return 0;
}

#include <iostream>

using namespace std;

//***************************************************************
// D.S. Malik
//
// This class specifies the functions to solve the n-queens puzzle.
//***************************************************************

class nQueensPuzzle
{
public:
    nQueensPuzzle(int queens = 8);
    //constructor
    //Postcondition: noOfSolutions = 0; noOfQueens = queens;
    //   queensInRow is a pointer to the array to store the
    //   n-tuple

    bool canPlaceQueen(int k, int i);
    //Function to determine whether a queen can be placed
    //in row k and column i.
    //Postcondition: returns true if a queen can be placed in
    //    row k and column i; otherwise it returns false

    void queensConfiguration(int k);
    //Function to determine all solutions to the n-queens
    //puzzle using backtracking.
    //The function is called with the value 0.
    //Postcondition: All n-tuples representing solutions of
    //    n-queens puzzle are generated and printed.

    void printConfiguration();
    //Function to output an n-tuple containing a solution
    //to the n-queens puzzle.

    int solutionsCount();
    //Function to return the total number of solutions.
    //Postcondition: The value of noOfSolution is returned.

private:
    int noOfSolutions;
    int noOfQueens;
    int* queensInRow;
};


nQueensPuzzle::nQueensPuzzle(int queens)
{
    noOfQueens = queens;
    queensInRow = new int[noOfQueens];
    noOfSolutions = 0;
}

bool nQueensPuzzle::canPlaceQueen(int k, int i)
{
    for (int j = 0; j < k; j++)
        if ((queensInRow[j] == i)
            || (abs(queensInRow[j] - i) == abs(j - k)))
            return false;
    return true;
}

void nQueensPuzzle::queensConfiguration(int k)
{
    for (int i = 0; i < noOfQueens; i++)
    {
        if (canPlaceQueen(k, i))
        {
            queensInRow[k] = i;  //place the kth queen in column i
            if (k == noOfQueens - 1)  //all the queens are placed
                printConfiguration(); //print the n-tuple
            else
                queensConfiguration(k + 1); //determine the place
                                            //for the (k+1)th queen
        }
    }
}

void nQueensPuzzle::printConfiguration()
{
    noOfSolutions++;
    cout << "(";
    for (int i = 0; i < noOfQueens - 1; i++)
        cout << queensInRow[i] << ", ";

    cout << queensInRow[noOfQueens - 1] << ")" << endl;
}

int nQueensPuzzle::solutionsCount()
{
    return noOfSolutions;
}

int main()
{
    nQueensPuzzle queens(4);

    queens.queensConfiguration(0);
    cout << "Number of Solutions: " << queens.solutionsCount() << endl;

    return 0;
}

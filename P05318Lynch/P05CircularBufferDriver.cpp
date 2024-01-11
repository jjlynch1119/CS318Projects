// P05CircularBufferDriver.cpp -- starter code

/*  REQUIREMENTS NOTES:

    Fill in the remainder of this driver program.
    Replicate exactly the sample run provided with project's specs.
    Use a capacity of 5

*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "circular_buffer.h"
#include "dog.h"

using namespace std;

int main() {
    cout << "\n*************** <int> Circular Buffer Demo ******************\n";
    //  FINISH THIS SECTION
    
    CircularBuffer<int, 5> intBuff = CircularBuffer<int, 5>();
    cout << "\nInitial state\n";
    cout << intBuff;

    intBuff.push_back(0);

    cout << "\n\nPushing 0\n";
    cout << intBuff;

    intBuff.push_back(10);

    cout << "\n\nPushing 10\n";
    cout << intBuff;

    intBuff.push_back(20);

    cout << "\n\nPushing 20\n";
    cout << intBuff;

    intBuff.push_back(30);

    cout << "\n\nPushing 30\n";
    cout << intBuff;

    intBuff.push_back(40);

    cout << "\n\nPushing 40\n";
    cout << intBuff;

    intBuff.push_back(50);

    cout << "\n\nPushing 50\n";
    cout << intBuff;

    intBuff.push_back(60);

    cout << "\n\nPushing 60\n";
    cout << intBuff;

    intBuff.push_back(70);

    cout << "\n\nPushing 70\n";
    cout << intBuff;

    intBuff.pop();

    cout << "\n\nPopping 30\n";
    cout << intBuff;

    intBuff.pop();

    cout << "\n\nPopping 40\n";
    cout << intBuff;

    intBuff.pop();

    cout << "\n\nPopping 50\n";
    cout << intBuff;

    intBuff.pop();

    cout << "\n\nPopping 60\n";
    cout << intBuff;

    intBuff.pop();

    cout << "\n\nPopping 70\n";
    cout << intBuff;

    cout << "\n\n";

    cout << "\n*************** <string> Circular Buffer Demo ******************\n";

    //  FINISH THIS SECTION --
    vector<string> words = { "the", "wonderful", "world", "of", "oz" };  // create a vector of words

    CircularBuffer<string, 5> stringBuff = CircularBuffer<string, 5>();
    back_insert_iterator<CircularBuffer<string, 5>> back_it = back_inserter(stringBuff);  // use back_insert_iterator to fill the buffer

    copy(words.begin(), words.end(), back_it);

    cout << "\nInitial state\n";

    cout << "After using back_insert_iterator\n";
    cout << stringBuff;
    
    stringBuff.pop();
    cout << "\n\nPopping: the\n";
    cout << stringBuff;

    stringBuff.pop();
    cout << "\n\nPopping: wonderful\n";
    cout << stringBuff;

    stringBuff.pop();
    cout << "\n\nPopping: world\n";
    cout << stringBuff;

    stringBuff.pop();
    cout << "\n\nPopping: of\n";
    cout << stringBuff;

    stringBuff.pop();
    cout << "\n\nPopping: oz\n";
    cout << stringBuff;

    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n";

    //  FINISH THIS SECTION

    CircularBuffer<dog, 5> dogBuff = CircularBuffer<dog, 5>();

    dogBuff.push_back(dog("Guiness", "Wheaton", 9));
    dogBuff.push_back(dog("Grimlock", "Lab", 2));
    dogBuff.push_back(dog("Optimus", "Bulldog", 5));
    dogBuff.push_back(dog("Murphy", "Lab", 14));
    dogBuff.push_back(dog("Floyd", "Beagle", 12));

    cout << dogBuff;
    cout << "dogs Full?: ";

    if (dogBuff.full() == true)
        cout << "true";
    else
        cout << "false";

    cout << "\n\n";

    dogBuff.push_back(dog("Snoopy", "Beagle", 100));
    cout << dogBuff;

    dogBuff.push_back(dog("Archie", "Brittany", 1));
    cout << dogBuff;

    dogBuff.push_back(dog("Penny", "Beagle", 100));
    cout << dogBuff;

    cout << "\n\nPopping:";
    cout << " " << dogBuff.head();
    dogBuff.pop();
    cout



    cout << endl;
}

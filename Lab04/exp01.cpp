#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int cards[4]{};
    int hands[4];

    int price[] = {3, 4, 5, 9};
    char direction[4] {'L', 82, 'U', 68};

    char title[] = "ChatGPT is an awesown tool,";
    
    cout << "sizeof(cards) = " << sizeof(cards) << ", size of cards[0] = " << sizeof(cards[0]) << endl;
    cout << "sizeof(price) = " << sizeof(price) << ", size of price[0] = " << sizeof(price[0]) << endl;
    cout << "sizeof(direction) = " << sizeof(direction) << ", length of direction = " << strlen(direction) << endl;
    cout << "sizeof(title) = " << sizeof(title) << ", length of title = " << strlen(title) << endl;

    // Print the value and address of each element in cards and hands respectively
    for(int i = 0; i < 4; i++)
    {
        cout << "cards[" << i << "] = " << cards[i] << ", and address of cards[" << i << "] = " << &cards[i] << endl;
    }
    for(int i = 0; i < 4; i++)
    {
        cout << "hands[" << i << "] = " << hands[i] << ", and address of hands[" << i << "] = " << &hands[i] << endl;
    }
}
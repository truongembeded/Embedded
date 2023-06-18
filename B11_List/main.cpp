#include<iostream>
#include<list>

using namespace std;

int main(int argc, char const *argv[])
{
    list<int> l = {1, 2, 3, 4, 5, 6};

    l.push_back(7);
    l.push_back(10);
	l.push_front(1);
	l.insert(l.begin(), 8);
	l.pop_back();
	l.pop_front();
	l.erase(l.begin(), l.end());
	l.clear();

    cout << "Cac phan tu cua list la :" << endl;
    for(auto i : l){
        cout << i << " ";
    }
    
    return 0;
}
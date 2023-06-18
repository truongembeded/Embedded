#include<iostream>
#include<map>

using namespace std;

int main(int argc, char const *argv[])
{
   
   
    // Khởi tạo map
    std::map<std::string, int> m;
    m["Alice"] = 25;
    m["Bob"] = 30;
    m["Charlie"] = 35;
    
    // Thêm một cặp key-value mới vào map
    m.insert(std::make_pair("David", 40));
    m.erase("Bob");
    
      for(auto it : m){
        cout << it.first << " " << it.second << endl;
    }
    
    return 0;
}
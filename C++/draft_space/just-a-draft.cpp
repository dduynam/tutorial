#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <atomic>
#include <memory>
#include <string>
#include <random>
#include <ctime>
#include <vector>
#include <array>

#ifndef Map
#define Map
void write(int _SensorID, std::map<int16_t, std::atomic<uint16_t>> &MsgSeqCount)
{
    MsgSeqCount[_SensorID]++;
}
void map()
{
    typedef std::map<uint16_t, std::atomic<int64_t>> value_map_t;
    static value_map_t map;
    //std::cout << "Before explicit initialization: " << map[1] << std::endl;
    if (map[2] != 0)
        std::cout << "Map is initialized implicitly with " << map[1] << std::endl;

    if (!(map.count(1)))
    {
        std::cout << "Map is not initialized implicitly." << std::endl;
        map[1] = 10;
    }
    //map[1] = map.count(1)?map[1]:10;

    map[1]++;
    std::cout << "After implicit initializarion: " << map[1] << std::endl;

    // Map insert
    map.insert(std::pair<uint16_t, uint16_t>(10, 100));

    /*srand(time(NULL));
    static std::map<int16_t, std::atomic<uint16_t>> g_MsgSeqCount; 
    for (int i = 0; i < 100; i++)
    {
        int ranNum = rand() % 10;
        write(ranNum, g_MsgSeqCount);
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << g_MsgSeqCount[i] << std::endl;
    }*/

    /*Use an indirection, utilizing a map to (smart) pointes of atomic*/
    /*using atomic_ptr_t = std::shared_ptr<std::atomic<int64_t>>;
    typedef std::map <uint16_t, atomic_ptr_t> _value_map_t;
    _value_map_t _map;*/
}
#endif

#ifndef Random
#define Random
void random()
{
    srand(time(NULL));
    int ranNum = rand() % 10;
}

#endif

#ifndef Loop
#define Loop
/* For loop in C++11 */
void loop()
{
    std::vector<int> _arr{1, 2, 3, 4, 5};
    for (auto &it : _arr)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

/* Common for loop with iterator */
void loop1(){
    std::vector<int> _arr{5,4,3,2,1};
    for (auto it = _arr.begin(); it != _arr.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/* For each */
void loop2(){
    int arr[5] = {1,2,3,4,5}; //array
    auto printx2 = []();

}
#endif

#ifndef LambdaExpression
#define LambdaExpression
void printVector(std::vector<int> v)
{

    for_each(v.begin(), v.end(), [](int i) -> void
             { std::cout << i << " "; });
    std::cout << std::endl;
}
#endif

#ifndef JustaTest
#define JustaTest
void test()
{
}
#endif

enum Haha
{
    one = 0,
    two,
    three,
    four,
    five,
    six,
    number
} haha;

int main()
{
#ifdef Map0
    const int size = 9;
    int SensorID = 10; // invalid value.

    std::cout << std::endl
              << "-----------MaP------------" << std::endl;
    std::map<int, int> _map1;
    std::cout << _map1[SensorID] << std::endl;
    std::cout << "MAX_SIZE: " << _map1.max_size() << std::endl;

    std::cout << std::endl
              << "-----------Vector----------" << std::endl;
    std::vector<int> _vector(10);
    for (size_t i = 0; i < Haha::number; i++)
    {
        std::cout << _vector[i] << " ";
    }
    std::cout << _vector[SensorID] << std::endl;
    std::cout << _vector.size() << std::endl;

    std::cout << std::endl
              << "-----------Array----------" << std::endl;
    std::array<int, size> _array;
    std::cout << _array[SensorID] << std::endl;
    std::cout << _array.size() << std::endl;

    // static std::vector<std::pair<int,std::atomic<uint16_t>>> g_MsgSeqCount(10);
    // g_MsgSeqCount.push_back({1,2});
    // std::cout << g_MsgSeqCount[0].first << std::endl;

    std::cout << std::endl
              << "-----------Testing----------" << std::endl;
    SensorID = 100; // Invalid value
    std::cout << "Invalid SensorID Value: " << SensorID << std::endl;

    static std::map<int, std::atomic<uint16_t>> _map;
    std::cout << "Value stored in Map: " << _map[SensorID] << std::endl;

    static std::vector<std::atomic<uint16_t>> g_MsgSeqCount(Haha::number);
    std::cout << "Value stored in Vector: " << g_MsgSeqCount[1] << std::endl;
    std::fill(g_MsgSeqCount.begin(), g_MsgSeqCount.end(), 10);

    for (size_t i = 0; i < Haha::number; i++)
    {
        std::cout << g_MsgSeqCount[i] << " ";
    }
#endif

#ifdef Map1
    //empty map container
    std::map<int, int> daniel;

    //insert element in random order
    daniel.insert(std::pair<int, int>(1, 12));
    daniel.insert(std::pair<int, int>(2, 17));
    daniel.insert(std::pair<int, int>(3, 16));
    daniel.insert(std::pair<int, int>(4, 13));
    daniel.insert(std::pair<int, int>(5, 15));
    daniel.insert(std::pair<int, int>(6, 14));
    daniel.insert(std::pair<int, int>(7, 12));

    //Or we can insert following this method
    daniel.insert(daniel.begin(), std::pair<int, int>(0, 10)); // Insert from somewhere of daniel map
    //daniel.insert(nam.begin(), nam.find(3)); // Insert from element 0->2 of map "nam" to backward of daniel.

    // find a element
    std::map<int, int>::iterator var = daniel.find(4);

    //printing map
    std::map<int, int>::iterator itr;
    std::cout << "\nThe map is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (itr = daniel.begin(); itr != daniel.end(); itr++)
    {
        std::cout << "\t" << itr->first
                  << "\t" << itr->second << "\n";
    }
    std::cout << std::endl;

    //assign the elements from daniel to nam ---> Range Constructor
    std::map<int, int> nam(daniel.begin(), daniel.end());

    // Copy constructor
    std::map<int, int> nam(daniel);

    //operator
    //nam = daniel;

    //printing all elements of nam
    std::cout << "\nThe nam map after assigning is : \n";
    std::cout << "\tKEY\tELEMENT\n";
    for (itr = nam.begin(); itr != nam.end(); itr++)
    {
        std::cout << "\t" << itr->first
                  << "\t" << itr->second << "\n";
    }

    //remove elements up to 3
    std::cout << "\n";
    std::cout << "\tKEY\tELEMENT\n";
    nam.erase(nam.begin(), nam.find(3));
    for (itr = nam.begin(); itr != nam.end(); itr++)
    {
        std::cout << "\t" << itr->first
                  << "\t" << itr->second << "\n";
    }

    //remove all element with key = 4
    int num = nam.erase(4); // Or if we assign 4th element to iterator var, we can use nam.erase(var);
    std::cout << "\nnam.erase(4): " << num << " removed" << std::endl;
    for (itr = nam.begin(); itr != nam.end(); itr++)
    {
        std::cout << "\t" << itr->first
                  << "\t" << itr->second << "\n";
    }

    //To remove all elements from the map
    //nam.clear();

    //To swap the elements between two maps
    //map1.swap(map2);

    // Check whether map is empty
    if (nam.empty())
        std::cout << "map is empty" << std::endl;

    // Instead of using insert, we can use emplace --- vector and pair
    std::vector<std::pair<std::string, int>> example;
    std::pair<std::string, int> _pair;
    _pair = std::make_pair(std::string("haha"), 10);
    example.push_back(_pair);

    //Or we can make it faster by
    example.emplace_back("haha", 10);
    example.at(0);

#endif

#ifdef LambdaExpression

#endif

#ifdef Loop
    loop1();
#endif
    test();

    return 0;
}

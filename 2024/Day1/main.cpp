#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    std::ifstream file("../input");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    std::vector<int> vec1, vec2;
    int num1, num2;
    while(file >> num1 >> num2)
    {
        vec1.push_back(num1);
        vec2.push_back(num2);
    }
    file.close();

    std::cout << vec1[0] << std::endl;
    std::cout << vec2[0] << std::endl;

    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end()); 

    std::cout << vec1[0] << std::endl;
    std::cout << vec2[0] << std::endl;

    size_t diff = 0;
    size_t score = 0;
    for(size_t i = 0; i < vec1.size(); i++)
    {
        diff += std::abs(vec1[i] - vec2[i]);
        score += vec1[i] * std::count(vec2.begin(), vec2.end(), vec1[i]);
    }

    std::cout << "distance: " << diff << std::endl;
    std::cout << "similiraity score: " << score << std::endl;

    return 0;
}
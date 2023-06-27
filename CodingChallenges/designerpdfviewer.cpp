#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int designerPdfViewer(std::vector<int> h, std::string word) {
{
   std::map<int, int> chMap;
    for (int i = 0; i < h.size(); i++) {
      chMap[i + 97] = h.at(i);
    }

    int size = word.size();
    int height = 0;
    for (auto i : word)
      // std::cout << (int)i << std::endl;
      height = std::max(height, chMap[static_cast<int>(i)]);

    return (height * size);
}

  void anotherFunction() { std::cout << "called another func" << std::endl; }

  int main() {
    std::vector<int> h = {1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5,
                          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

  

    std::string word = "abc";

    std::cout << designerPdfViewer(h, word) << std::endl;

    return 0;
  }

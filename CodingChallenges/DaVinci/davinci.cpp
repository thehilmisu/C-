#include <iostream>
#include <locale>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <locale>
#include <algorithm>
#include <chrono>

struct IdVolume {
    int64_t id;
    int64_t volume;
};

struct PriceVolume {
    double price;
    int64_t volume;
};

struct Order{
  
  std::string timeStamp;
  std::string symbol;
  std::string orderID;
  std::string operation;
  std::string side;
  std::string volume;
  std::string price;
    
};

/*
 * Complete the member functions below as per the question's description.
 */

class TestSolution {
  public:
    const std::vector<std::string>& m_data;
    TestSolution(const std::vector<std::string>& data) : m_data(data)
    {}
    
    Order splitString(const std::string& str)
    {
        std::string delimiter = ";";
        Order _order;
        std::vector<std::string> result;
        size_t delimiterPos = 0;
        size_t startPos = 0;

        while ((delimiterPos = str.find(delimiter, startPos)) != std::string::npos)
        {
            std::string token = str.substr(startPos, delimiterPos - startPos);
            result.push_back(token);
            startPos = delimiterPos + delimiter.length();
        }

        // Add the remaining part of the string after the last delimiter
        std::string lastToken = str.substr(startPos);
        result.push_back(lastToken);
        
    
        //0:timestamps, 1:symbol, 2:order-id,3:operation
        _order.timeStamp = result.at(0);
        _order.symbol = result.at(1);
        _order.orderID = result.at(2);
        _order.operation = result.at(3);
        _order.side = result.at(4);
        _order.volume = result.at(5);
        _order.price = result.at(6);
        
      

        return _order;
    }
        
    std::unordered_map<std::string, int64_t> OrderCounts()
    {
        std::unordered_map<std::string, int64_t> orderCounts;
        
        for(auto& i : m_data)
        {
            Order order = splitString(i);
            if(order.operation == "I")
                orderCounts[order.symbol]++;
        }
            
        
        return orderCounts;
    }
    std::vector<IdVolume> BiggestBuyOrders(const std::string& symbol)
    {
         std::vector<IdVolume> biggestBuys;

        // Filter the buy orders for the specific symbol
        std::vector<IdVolume> buyOrders;
        for (auto& i : m_data)
        {
            Order order = splitString(i);
            if (order.symbol == symbol  && order.side == "BUY")
            {
                IdVolume buyOrder;
                buyOrder.id = std::stoi(order.orderID);
                buyOrder.volume = std::stoi(order.volume);
                buyOrders.push_back(buyOrder);
            }
        }

        // Sort the buy orders in descending order based on volume
        std::sort(buyOrders.begin(), buyOrders.end(), [](const IdVolume& a, const IdVolume& b) {
            return a.volume > b.volume;
        });

        // Keep track of unique IDs using an unordered set
        std::unordered_set<int64_t> uniqueIds;

        // Get the top three biggest buy orders (unique by ID)
        for (const auto& buyOrder : buyOrders)
        {
            if (uniqueIds.insert(buyOrder.id).second)
            {
                biggestBuys.push_back(buyOrder);
                if (biggestBuys.size() >= 3)
                    break;
            }
        }

        return biggestBuys;
    }
    
    
    std::time_t ConvertToTimeSinceEpoch(const std::string& timestamp)
    {
        std::istringstream ss(timestamp);
        std::tm tm = {};
        ss >> std::get_time(&tm, "%H:%M:%S");

        std::time_t time = std::mktime(&tm);
        return time;
    }

   PriceVolume BestSellAtTime(const std::string& symbol, const std::string& timestamp)
    {

        PriceVolume bestSell= {0.1, 1};
        
        for(auto& i : m_data)
        {
            Order order = splitString(i);
            
            std::time_t timeSinceEpochTimestamp = ConvertToTimeSinceEpoch(timestamp);
            std::time_t timeSinceEpochOrderTimeStamp = ConvertToTimeSinceEpoch(order.timeStamp);
            
            // I really don't understand why this is not working
            if (order.symbol == symbol  && order.side == "SELL" && timeSinceEpochOrderTimeStamp <= timeSinceEpochTimestamp)
            {
                //if ((std::stod(order.price) * std::stod(order.volume)) > (bestSell.price * bestSell.volume))
                //if(std::stod(order.price) > bestSell.price && (std::stoi(order.volume ) > bestSell.volume))
                //if((std::stoi(order.volume ) > bestSell.volume) && std::stod(order.price) > bestSell.price)
                //if ((double)(std::stoi(order.volume) / std::stod(order.price)) > (double)(bestSell.volume / bestSell.price))
                if ((double)(std::stod(order.price) / std::stoi(order.volume)) > (double)(bestSell.price / bestSell.volume))
                {
                    bestSell.price = std::stod(order.price);
                    bestSell.volume = std::stoi(order.volume);
                }
            }
        }
        
        return bestSell;
    } 
    
  };

int main()
{
    std::vector<std::string> data;
    std::string line;
    while (std::getline(std::cin, line)) {
        data.emplace_back(line);
    }
    
    TestSolution solution{data};
    std::cout << "Order counts:\n";
    for (const auto& [symbol, count] : solution.OrderCounts()) {
        std::cout << symbol << " " << count << "\n";
    }
    
    std::cout << "\nBiggest buys:\n";
    for (const IdVolume& idVolume : solution.BiggestBuyOrders("DVAM1")) {
        std::cout << idVolume.id << " " << idVolume.volume << "\n";
    }
    
    std::cout << "\nBest sell:\n";
    PriceVolume priceVolume = solution.BestSellAtTime("DVAM1", "15:30:00");
    std::cout << priceVolume.price << " " << priceVolume.volume << "\n";
    
    return 0;
}



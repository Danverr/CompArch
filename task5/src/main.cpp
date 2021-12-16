#include <iostream>
#include <vector>
#include <map>
#include <thread>
#include <mutex>
using namespace std;
using namespace chrono;

auto start = system_clock::now().time_since_epoch();

void logString(const string& log) {
    int time_elapsed = (system_clock::now().time_since_epoch() - start) / milliseconds(1);
    cout << "[" + to_string(time_elapsed) + "ms] " + log + "\n";
}


struct Item {
    string name;
    int time_to_buy = 0;
    int section = 0;
};

map<string, Item> items;



class Seller {
 public:
    void sellItem(const string& buyer_name, const Item& item) {
        const lock_guard<mutex> lock(seller_mutex);
        logString(buyer_name + " is buying " + item.name + " from section #" + to_string(item.section));
        this_thread::sleep_for(chrono::milliseconds(item.time_to_buy));
        logString(buyer_name + " finally has bought " + item.name + " from section #" + to_string(item.section));
    }
 private:
    mutex seller_mutex;
};

Seller sellers[2];



class Buyer {
 public:
    Buyer() = default;

    explicit Buyer(string name_) : name(std::move(name_)) {
    }

    void goShopping() {
        for (auto& item : shopping_list) {
            logString(name + " wants to buy " + item.name + " from section #" + to_string(item.section));
            sellers[item.section].sellItem(name, item);
        }
    }

    void addItem(const Item& item) {
        shopping_list.push_back(item);
    }

    void setName(const string& name_) {
        name = name_;
    }

    string getName() const {
        return name;
    }

 private:
    string name;
    vector<Item> shopping_list;
};



int main() {
    // Вводим возможные товары и их секции
    // Количество_товаров
    // Название_товара_1 Количество_времени_для_покупки_1 Номер_секции_1
    // ...
    // Название_товара_N Количество_времени_для_покупки_N Номер_секции_N
    int items_count = 0;
    cin >> items_count;
    for (int i = 0; i < items_count; ++i) {
        string name;
        int time_to_buy;
        int section;
        cin >> name >> time_to_buy >> section;
        items[name] = Item({name, time_to_buy, section - 1});
    }

    // Вводим покупателей в формате
    // Кол-во покупателей
    // Имя_1 Количество_товаров_1 Товар_1 Товар_2 ... Товар_N
    // ...
    // Имя_N Количество_товаров_N Товар_1 Товар_2 ... Товар_N
    int buyers_count = 0;
    cin >> buyers_count;
    vector<Buyer> buyers(buyers_count);

    for (auto& buyer : buyers) {
        string name;
        int count = 0;
        cin >> name >> count;
        buyer.setName(name);
        for (int i = 0; i < count; ++i) {
            string item_name;
            cin >> item_name;
            buyer.addItem(items[item_name]);
        }
    }

    // Создаем потоки для каждого покупателя,
    // чтобы они начали ходить за покупками
    vector<thread> threads;
    threads.reserve(buyers.size());
    for (auto& buyer : buyers) {
        threads.emplace_back(&Buyer::goShopping, &buyer);
    }

    for (auto& thr : threads) {
        thr.join();
    }

    return 0;
}

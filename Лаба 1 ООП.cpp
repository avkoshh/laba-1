#include <iostream>
#include <string>


int safe_input_int(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cout << "Ошибка! Пожалуйста, введите целое число.\n";
        }
        else {
            return value;
        }
    }
}


class enterprise 
{

private:
    std::string district;
    int number;
    int price;

public:
    int number_paid;
    int number_people;

    void amount_duty()
    {
        int debtor = number_people - number_paid;
        int duty = debtor * price;
        std::cout << "\n=== ОТЧЕТ О ДОЛГАХ ===" << std::endl;
        std::cout << "ЖЭС №" << number << std::endl;
        std::cout << "Количество должников: " << debtor << std::endl;
        std::cout << "Стоимость оплаты на человека: " << price << " руб." << std::endl;
        std::cout << "Сумма долга: " << duty << " руб." << std::endl;
        std::cout << "=========================" << std::endl;
    }

    void Set_number(int Number)
    {
        number = Number;
    }

    void Set_price(int Price)
    {
        price = Price;
    }

    void Set_district(std::string District)
    {
        district = District;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    int num;
    int price;
    std::string dis;

    enterprise housing_office;

    std::cout << "Введите улицу: ";
    std::cin >> dis;
    housing_office.Set_district(dis);

    num = safe_input_int("\nВведите номер ЖЭС: ");
    housing_office.Set_number(num);

    std::cout << "\nТак так так. О мы нашли эту контору";

    

    price = safe_input_int("\nКакая стоимость оплаты: ");
    housing_office.Set_price(price);

    while (true) {
        housing_office.number_people = safe_input_int("\nСколько сейчас людей в ней проживает: ");

        housing_office.number_paid = safe_input_int("\nА сколько из них всё оплатили: ");
        if (housing_office.number_people >= housing_office.number_paid) {
            break;
        }
        else {
            std::cout << "\nНе могут вам платить люди, которые у вас не живут.\n";
        }
    }
   
    
    housing_office.amount_duty();
}
